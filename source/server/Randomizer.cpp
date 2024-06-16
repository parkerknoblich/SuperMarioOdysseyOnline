#include "server/Randomizer.hpp"
#include "nn/util.h"
#include "Keyboard.hpp"
#include "server/Client.hpp"
#include "sead/container/seadTList.h"

SEAD_SINGLETON_DISPOSER_IMPL(Randomizer);

Randomizer::Randomizer() {
    mHeap = sead::ExpHeap::create(0x50000, "RandomizerHeap", sead::HeapMgr::instance()->getCurrentHeap(), 8, sead::Heap::cHeapDirection_Forward, false);

    mDebugAmount = 0;
    mDebugCounter = 0;
}

void Randomizer::init() {
    sInstance->WarpMap.allocBuffer(16, sInstance->mHeap);
}

const int Randomizer::getSeed() {
    return sInstance ? sInstance->mSeed : -1;
}

void Randomizer::setLastUsedSeed(const int seed) {
    if (sInstance) {
        sInstance->mSeed = seed;
        // Note: this doesn't work on startup, need to manually set the
        // seed to something different first
        randomize();
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

    bool newSeed = prevSeed != sInstance->mSeed;

    if (newSeed) {
        randomize();
    }

    return newSeed;
}

void Randomizer::randomize() {
    sead::ScopedCurrentHeapSetter heapSetter(sInstance->mHeap);

    sead::TList<const char *> warpStages;

    auto x1 = sead::TListNode("WanwanClashExStage");
    warpStages.pushBack(&x1);

    auto seed = getSeed();
    sead::Random x(seed);
    warpStages.shuffle(&x);

    auto first = warpStages.front();
    auto warpStage = first->mData;
    sInstance->WarpMap.clear();
    sead::FixedSafeString<0x80> trexPoppunExStageString("TrexPoppunExStage");
    sInstance->WarpMap.insert(trexPoppunExStageString, warpStage);
}

void Randomizer::warp(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    setDebugString(sead::FixedSafeString<0x80>(changeStageInfo->changeStageId));

    auto originalWarpLocation = changeStageInfo->changeStageName;
    auto newWarpLocationNode = sInstance->WarpMap.find(originalWarpLocation);
    if (newWarpLocationNode != nullptr) {
        auto newWarpLocation = newWarpLocationNode->value();
        ChangeStageInfo newChangeStageInfo(thisPtr,
            "",
            newWarpLocation,
            false,
            -1,
            ChangeStageInfo::SubScenarioType::UNK
        );
        thisPtr->changeNextStage(&newChangeStageInfo, i);
    } else {
        thisPtr->changeNextStage(changeStageInfo, i);
    }
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

void Randomizer::setDebugString(sead::FixedSafeString<0x80> string) {
    if (sInstance) {
        if (sInstance->mDebugString == string) {
            sInstance->mDebugStringCounter += 1;
        } else {
            sInstance->mDebugStringCounter = 1;
        }
        sInstance->mDebugString = string;
    }
}

const char * Randomizer::getDebugString() {
    if (sInstance) {
        return sInstance->mDebugString.cstr();
    } else {
        return nullptr;
    }
}

int Randomizer::getDebugStringCounter() {
    return sInstance ? sInstance->mDebugStringCounter : -1;
}
