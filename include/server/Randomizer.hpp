#pragma once

#include "sead/heap/seadDisposer.h"
#include "heap/seadExpHeap.h"
#include "sead/container/seadTreeMap.h"
#include "sead/container/seadTreeNode.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include "game/GameData/GameDataHolderWriter.h"

class Randomizer {
    SEAD_SINGLETON_DISPOSER(Randomizer)
    Randomizer();

public:
    static void init();

    static const int getSeed();
    static void setLastUsedSeed(const int seed);
    static bool openKeyboardSeed();

    sead::TreeMap<sead::FixedSafeString<0x80>, const char*> WarpMap;
    static void warp(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i);

    static void setDebugAmount(int n);
    static int getDebugAmount();
    static int getDebugCounter();

    static void setDebugString(sead::FixedSafeString<0x80> string);
    static const char * getDebugString();
    static int getDebugStringCounter();

private:
    sead::ExpHeap *mHeap = nullptr;

    int mSeed;
    static void randomize();

    int mDebugAmount;
    int mDebugCounter;
    
    sead::FixedSafeString<0x80> mDebugString;
    int mDebugStringCounter;
};
