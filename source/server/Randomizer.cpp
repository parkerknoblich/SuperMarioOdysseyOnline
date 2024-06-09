#include "server/Randomizer.hpp"
#include "nn/util.h"
#include "Keyboard.hpp"
#include "server/Client.hpp"

SEAD_SINGLETON_DISPOSER_IMPL(Randomizer);

Randomizer::Randomizer() {
    mDebugAmount = 0;
    mDebugCounter = 0;
}

const int Randomizer::getSeed() {
    return sInstance ? sInstance->mSeed : -1;
}

void Randomizer::setLastUsedSeed(const int seed) {
    if (sInstance) {
        sInstance->mSeed = seed;
    }
}

bool Randomizer::openKeyboardSeed() {
    if (!sInstance) {
        return false;
    }

    char buf[7];
    nn::util::SNPrintf(buf, 7, "%u", sInstance->mSeed);

    Client::instance()->getKeyboard()->openKeyboard(buf, [](nn::swkbd::KeyboardConfig& config) {
        config.keyboardMode = nn::swkbd::KeyboardMode::ModeNumeric;
        config.textMaxLength = 6;
        config.textMinLength = 6;
        config.isUseUtf8 = true;
        config.inputFormMode = nn::swkbd::InputFormMode::OneLine;
    });

    int prevSeed = sInstance->mSeed;

    while (true) {
        if (Client::instance()->getKeyboard()->isThreadDone()) {
            if(!Client::instance()->getKeyboard()->isKeyboardCancelled())
                sInstance->mSeed = ::atoi(Client::instance()->getKeyboard()->getResult());
            break;
        }
        nn::os::YieldThread(); // allow other threads to run
    }

    return prevSeed != sInstance->mSeed;
}

void Randomizer::setDebugAmount(int n) {
    if (sInstance) {
        if (sInstance->mDebugAmount == n) {
            sInstance->mDebugCounter += 1;
        } else {
            sInstance->mDebugCounter = 1;
        }
        sInstance->mDebugAmount = n;
    }
}

int Randomizer::getDebugAmount() {
    return sInstance ? sInstance->mDebugAmount : -1;
}

int Randomizer::getDebugCounter() {
    return sInstance ? sInstance->mDebugCounter : -1;
}
