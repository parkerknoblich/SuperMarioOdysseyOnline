#include "server/Randomizer.hpp"
#include "nn/util.h"
#include "Keyboard.hpp"
#include "server/Client.hpp"

SEAD_SINGLETON_DISPOSER_IMPL(Randomizer);

Randomizer::Randomizer() {
    mHeap = sead::ExpHeap::create(0x50000, "RandomizerHeap", sead::HeapMgr::instance()->getCurrentHeap(), 8, sead::Heap::cHeapDirection_Forward, false);

    mDebugAmount = 0;
    mDebugCounter = 0;
}

void Randomizer::init() {
    sead::ScopedCurrentHeapSetter heapSetter(sInstance->mHeap);
    sInstance->WarpMap.allocBuffer(16, sInstance->mHeap);
    sInstance->transitionObjArray.allocBuffer(2, sInstance->mHeap);
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
    sInstance->transitionObjArray.clear();
    // // Cap
    // sInstance->stageTypeMap.insert("CapWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("CapWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CapWorldTowerStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CapWorldTowerStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("FrogSearchExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FrogSearchExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("PoisonWaveExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PoisonWaveExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("PushBlockExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PushBlockExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("RollingExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("RollingExStage", MULTI_WAY);

    // // Cascade
    // sInstance->stageTypeMap.insert("WaterfallWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("WaterfallWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("TrexPoppunExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TrexPoppunExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("Lift2DExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("Lift2DExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("WanwanClashExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("WanwanClashExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CapAppearExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CapAppearExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("WindBlowExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("WindBlowExStage", MULTI_WAY);

    // // Sand
    // sInstance->stageTypeMap.insert("SandWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("SandWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SandWorldSlotStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldSlotStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SandWorldVibrationStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldVibrationStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SandWorldSecretStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldSecretStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SandWorldMeganeExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldMeganeExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldKillerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldKillerExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldPressExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldPressExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldSphinxExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldSphinxExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SandWorldPyramid000Stage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldPyramid000Stage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldPyramid001Stage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldPyramid001Stage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldUnderground000Stage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldUnderground000Stage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldUnderground001Stage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldUnderground001Stage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SandWorldRotateExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SandWorldRotateExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("MeganeLiftExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("MeganeLiftExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("RocketFlowerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("RocketFlowerExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("WaterTubeExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("WaterTubeExStage", MULTI_WAY);

    // // Lake
    // sInstance->stageTypeMap.insert("LakeWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("LakeWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LakeWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LakeWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("FastenerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FastenerExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("TrampolineWallCatchExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TrampolineWallCatchExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("GotogotonExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("GotogotonExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("FrogPoisonExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FrogPoisonExStage", MULTI_WAY);

    // // Wooded
    // sInstance->stageTypeMap.insert("ForestWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("ForestWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldWaterExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldWaterExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldTowerStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldTowerStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldBossStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldBossStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldBonusStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldBonusStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldCloudBonusExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldCloudBonusExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("FogMountainExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FogMountainExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("RailCollisionExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("RailCollisionExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ShootingElevatorExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ShootingElevatorExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldWoodsStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldWoodsStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldWoodsTreasureStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldWoodsTreasureStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("ForestWorldWoodsCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForestWorldWoodsCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("PackunPoisonExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PackunPoisonExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("AnimalChaseExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("AnimalChaseExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("KillerRoadExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("KillerRoadExStage", ONE_WAY);

    // // Cloud
    // sInstance->stageTypeMap.insert("CloudWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("CloudWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("FukuwaraiKuriboStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FukuwaraiKuriboStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("Cube2DExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("Cube2DExStage", ONE_WAY);

    // // Lost
    // sInstance->stageTypeMap.insert("ClashWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("ClashWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ClashWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ClashWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("ImomuPoisonExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ImomuPoisonExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("JangoExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("JangoExStage", ONE_WAY);

    // // Metro
    // sInstance->stageTypeMap.insert("CityWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("CityWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CityWorldMainTowerStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CityWorldMainTowerStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CityWorldFactoryStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CityWorldFactoryStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("CityWorldShop01Stage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CityWorldShop01Stage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CityWorldSandSlotStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CityWorldSandSlotStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("CityPeopleRoadStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CityPeopleRoadStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("PoleGrabCeilExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PoleGrabCeilExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("TrexBikeExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TrexBikeExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("PoleKillerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PoleKillerExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("Note2D3DRoomExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("Note2D3DRoomExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("ShootingCityExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ShootingCityExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CapRotatePackunExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CapRotatePackunExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("RadioControlExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("RadioControlExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("ElectricWireExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ElectricWireExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("Theater2DExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("Theater2DExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("DonsukeExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("DonsukeExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SwingSteelExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SwingSteelExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("BikeSteelExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("BikeSteelExStage", MULTI_WAY);

    // // Snow
    // sInstance->stageTypeMap.insert("SnowWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("SnowWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SnowWorldTownStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SnowWorldTownStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SnowWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SnowWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SnowWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SnowWorldCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SnowWorldCloudBonusExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SnowWorldCloudBonusExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("IceWalkerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("IceWalkerExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("IceWaterBlockExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("IceWaterBlockExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ByugoPuzzleExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ByugoPuzzleExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("IceWaterDashExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("IceWaterDashExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("KillerRailCollisionExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("KillerRailCollisionExStage", MULTI_WAY);

    // // Seaside
    // sInstance->stageTypeMap.insert("SeaWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("SeaWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SeaWorldUtsuboCaveStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SeaWorldUtsuboCaveStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SeaWorldVibrationStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SeaWorldVibrationStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SeaWorldSecretStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SeaWorldSecretStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SeaWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SeaWorldCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SeaWorldSneakingManStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SeaWorldSneakingManStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SenobiTowerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SenobiTowerExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CloudExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CloudExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("WaterValleyExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("WaterValleyExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ReflectBombExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ReflectBombExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("TogezoRotateExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TogezoRotateExStage", ONE_WAY);

    // // Luncheon
    // sInstance->stageTypeMap.insert("LavaWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("LavaWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldUpDownExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldUpDownExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LavaBonus1Zone", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaBonus1Zone", ONE_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldCostumeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("ForkExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("ForkExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldExcavationExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldExcavationExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldClockExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldClockExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldBubbleLaneExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldBubbleLaneExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldTreasureStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldTreasureStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("GabuzouClockExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("GabuzouClockExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("CapAppearLavaLiftExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("CapAppearLavaLiftExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("LavaWorldFenceLiftExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("LavaWorldFenceLiftExStage", MULTI_WAY);

    // // Ruined
    // sInstance->stageTypeMap.insert("BossRaidWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("BossRaidWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("DotTowerExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("DotTowerExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("BullRunExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("BullRunExStage", MULTI_WAY);

    // // Bowsers
    // sInstance->stageTypeMap.insert("SkyWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("SkyWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("SkyWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SkyWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SkyWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SkyWorldCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SkyWorldCloudBonusExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SkyWorldCloudBonusExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("SkyWorldTreasureStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("SkyWorldTreasureStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("JizoSwitchExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("JizoSwitchExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("TsukkunRotateExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TsukkunRotateExStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("KaronWingTowerStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("KaronWingTowerStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("TsukkunClimbExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("TsukkunClimbExStage", MULTI_WAY);

    // // Mushroom
    // sInstance->stageTypeMap.insert("PeachWorldHomeStage", OVER_WORLD);
    // sInstance->exitTypeMap.insert("PeachWorldHomeStage", MULTI_WAY);
    // sInstance->stageTypeMap.insert("PeachWorldShopStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PeachWorldShopStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("PeachWorldCostumeStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("PeachWorldCostumeStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("FukuwaraiMarioStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("FukuwaraiMarioStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("DotHardExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("DotHardExStage", ONE_WAY);
    // sInstance->stageTypeMap.insert("YoshiCloudExStage", SUB_AREA);
    // sInstance->exitTypeMap.insert("YoshiCloudExStage", ONE_WAY);

    // pick two random entries (2 left right pairs)
    // pick random left or right for entry1
    // pick random left or right for entry2
    // if valid (not overworld to overworld, something about pipes, multi-ways and one-ways, etc), swap two picked items

    // keep keys same, just shuffle values (cannot have overworld: overworld)

    static constexpr TransitionPoint sandWorldHomeStageAndSandWorldShopStageFrontOverWorldTransitionPoint = {sInstance->sandWorldHomeStageAndSandWorldShopStageFrontTransition.overWorld, sInstance->sandWorldHomeStageAndSandWorldShopStageFrontTransition.warpId};
    static constexpr TransitionPoint sandWorldHomeStageAndSandWorldShopStageFrontSubAreaTransitionPoint = {sInstance->sandWorldHomeStageAndSandWorldShopStageFrontTransition.subArea, sInstance->sandWorldHomeStageAndSandWorldShopStageFrontTransition.warpId};
    std::pair<TransitionPoint, TransitionPoint> sandWorldHomeStageAndSandWorldShopStageFrontTransitionPointPair(sandWorldHomeStageAndSandWorldShopStageFrontOverWorldTransitionPoint, sandWorldHomeStageAndSandWorldShopStageFrontSubAreaTransitionPoint);

    static constexpr TransitionPoint sandWorldHomeStageAndSandWorldSlotStageOverWorldTransitionPoint = {sInstance->sandWorldHomeStageAndSandWorldSlotStageTransition.overWorld, sInstance->sandWorldHomeStageAndSandWorldSlotStageTransition.warpId};
    static constexpr TransitionPoint sandWorldHomeStageAndSandWorldSlotStageSubAreaTransitionPoint = {sInstance->sandWorldHomeStageAndSandWorldSlotStageTransition.subArea, sInstance->sandWorldHomeStageAndSandWorldSlotStageTransition.warpId};
    std::pair<TransitionPoint, TransitionPoint> sandWorldHomeStageToSandWorldSlotStageTransitionPointPair(sandWorldHomeStageAndSandWorldSlotStageOverWorldTransitionPoint, sandWorldHomeStageAndSandWorldSlotStageSubAreaTransitionPoint);

    // auto sandWorldHomeStageAndSandWorldShopStageFrontTransitionPointPairNode = sead::TListNode(sandWorldHomeStageAndSandWorldShopStageFrontTransitionPointPair);
    // auto sandWorldHomeStageToSandWorldSlotStageTransitionPointPairNode = sead::TListNode(sandWorldHomeStageToSandWorldSlotStageTransitionPointPair);
    
    sInstance->transitionObjArray.pushBack(sandWorldHomeStageAndSandWorldShopStageFrontTransitionPointPair);
    sInstance->transitionObjArray.pushBack(sandWorldHomeStageToSandWorldSlotStageTransitionPointPair);

    
    // sInstance->transitionList.pushBack(&sandWorldHomeStageAndSandWorldShopStageFrontTransitionPointPairNode);
    // sInstance->transitionList.pushBack(&sandWorldHomeStageToSandWorldSlotStageTransitionPointPairNode);
    // transitionList = {
    //     ({{"SandWorldHomeStage", "bar1"}, {"SandWorldShopStage", "bar1"}}),
    //     ({{"SandWorldHomeStage", "town"}, {"SandWorldSlotStage", "town"}})
    // }

    // std::swap(sInstance->transitionList.nth(0)->mData.second, sInstance->transitionList.nth(1)->mData.second);

    // transitionList = {
    //     ({{"SandWorldHomeStage", "bar1"}, {"SandWorldSlotStage", "town"}}),
    //     ({{"SandWorldHomeStage", "town"}, {"SandWorldShopStage", "bar1"}})
    // }

    auto firstPair = sInstance->transitionObjArray[0];
    sead::FixedSafeString<0x80> foo(firstPair->first.stage);
    sInstance->setDebugString(foo);

    // auto firstPair = sInstance->transitionList.nth(0);

    // sead::FixedSafeString<0x80> foo(firstPair->mData.second.stage);

    // sInstance->setDebugString(foo);
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
