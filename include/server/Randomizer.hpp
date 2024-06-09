#pragma once

#include "sead/heap/seadDisposer.h"

class Randomizer {
    SEAD_SINGLETON_DISPOSER(Randomizer)
    Randomizer();

public:
    static const int getSeed();
    static void setLastUsedSeed(const int seed);
    static bool openKeyboardSeed();

    static void setDebugAmount(int n);
    static int getDebugAmount();
    static int getDebugCounter();

private:
    int mSeed;

    int mDebugAmount;
    int mDebugCounter;
};
