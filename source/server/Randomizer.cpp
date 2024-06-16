#include "server/Randomizer.hpp"
#include "nn/util.h"
#include "Keyboard.hpp"
#include "server/Client.hpp"
#include "sead/container/seadTList.h"

enum StageType : unsigned int {
    ONE_WAY,
    MULTI_WAY
};

struct Stage {
    const char* name;
    const char* id;
    const StageType type;
};

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

    // Cap
    Stage capWorldHomeStageViaCapWorldTowerStageBottom = {"CapWorldHomeStage", "Ex", StageType::MULTI_WAY};
    Stage capWorldHomeStageViaCapWorldTowerStageTop = {"CapWorldHomeStage", "Goal", StageType::MULTI_WAY};
    Stage capWorldHomeStageViaFrogSearchExStage = {"CapWorldHomeStage", "FrogSearchExStageEnt", StageType::MULTI_WAY};
    Stage capWorldHomeStageViaPoisonWaveExStage = {"CapWorldHomeStage", "PoisonWaveExExit", StageType::MULTI_WAY};
    Stage capWorldHomeStageviaPushBlockExStage = {"CapWorldHomeStage", "PushBlockExStageEntDokan", StageType::MULTI_WAY};
    Stage capWorldHomeStageViaRollingExStage = {"CapWorldHomeStage", "rollinggoal", StageType::MULTI_WAY};
    Stage capWorldTowerStageBottom = {"CapWorldTowerStage", "Ex", StageType::MULTI_WAY};
    Stage capWorldTowerStageTop = {"CapWorldTowerStage", "Goal", StageType::MULTI_WAY};
    Stage frogSearchExStage = {"FrogSearchExStage", "FrogSearchExStageEnt", StageType::ONE_WAY};
    Stage poisonWaveExStage = {"PoisonWaveExStage", "PoisonWaveExEnt", StageType::MULTI_WAY};
    Stage pushBlockExStage = {"PushBlockExStage", "PushBlockExStageEnt", StageType::MULTI_WAY};
    Stage rollingExStage = {"RollingExStage", "rollingstart", StageType::MULTI_WAY};

    // Cascade
    Stage waterfallWorldHomeStageViaTrexPoppunExStage = {"WaterfallWorldHomeStage", "RexPoppunEx", StageType::MULTI_WAY};
    Stage waterfallWorldHomeStageViaLift2DExStage = {"WaterfallWorldHomeStage", "Lift2DExit", StageType::MULTI_WAY};
    Stage waterfallWorldHomeStageViaWanwanClashExStage = {"WaterfallWorldHomeStage", "WanwanExGoal", StageType::MULTI_WAY};
    Stage waterfallWorldHomeStageViaCapAppearExStage = {"WaterfallWorldHomeStage", "CapAppearExExit", StageType::MULTI_WAY};
    Stage waterfallWorldHomeStageViaWindBlowExStage = {"WaterfallWorldHomeStage", "WindBlowExGoal", StageType::MULTI_WAY};
    Stage trexPoppunExStage = {"TrexPoppunExStage", "RexPoppunEx", StageType::ONE_WAY};
    Stage lift2DExStage = {"Lift2DExStage", "Lift2D", StageType::MULTI_WAY};
    Stage wanwanClashExStage = {"WanwanClashExStage", "WanwanExStart", StageType::MULTI_WAY};
    Stage capAppearExStage = {"CapAppearExStage", "CapAppearExEnt", StageType::MULTI_WAY};
    Stage windBlowExStage = {"WindBlowExStage", "WindBlowExStart", StageType::MULTI_WAY};

    // Sand
    Stage sandWorldHomeStageViaSandWorldShopStageFront = {"SandWorldHomeStage", "bar1", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldShopStageBack = {"SandWorldHomeStage", "bar2", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldSlotStage = {"SandWorldHomeStage", "town", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldVibrationStage = {"SandWorldHomeStage", "shindo", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldSecretStage = {"SandWorldHomeStage", "hide", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldMeganeExStage = {"SandWorldHomeStage", "anki2", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldKillerExStage = {"SandWorldHomeStage", "doukutu2", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldPressExStage = {"SandWorldHomeStage", "arijigoku2", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldSphinxExStage = {"SandWorldHomeStage", "run00return", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldCostumeStage = {"SandWorldHomeStage", "abc", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldPyramid000Stage = {"SandWorldHomeStage", "pyramid02", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldPyramid001Stage = {"SandWorldHomeStage", "pyramid04", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldUnderground000Stage = {"SandWorldHomeStage", "Under01", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldUnderground001Stage = {"SandWorldHomeStage", "Out", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaSandWorldRotateExStage = {"SandWorldHomeStage", "birureturn", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaMeganeLiftExStage = {"SandWorldHomeStage", "meganelift02", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaRocketFlowerExStage = {"SandWorldHomeStage", "rocket", StageType::MULTI_WAY};
    Stage sandWorldHomeStageViaWaterTubeExStage = {"SandWorldHomeStage", "EX_2DHosui_Exit", StageType::MULTI_WAY};
    Stage sandWorldShopStageFront = {"SandWorldShopStage", "bar1", StageType::ONE_WAY};
    Stage sandWorldShopStageBack = {"SandWorldShopStage", "bar2", StageType::ONE_WAY};
    Stage sandWorldSlotStage = {"SandWorldSlotStage", "town", StageType::ONE_WAY};
    Stage sandWorldVibrationStage = {"SandWorldVibrationStage", "shindo", StageType::ONE_WAY};
    Stage sandWorldSecretStage = {"SandWorldSecretStage", "hide", StageType::ONE_WAY};
    Stage sandWorldMeganeExStage = {"SandWorldMeganeExStage", "wall", StageType::MULTI_WAY};
    Stage sandWorldKillerExStage = {"SandWorldKillerExStage", "doukutu1", StageType::MULTI_WAY};
    Stage sandWorldPressExStage = {"SandWorldPressExStage", "arijigoku1", StageType::MULTI_WAY};
    Stage sandWorldSphinxExStage = {"SandWorldSphinxExStage", "run00", StageType::MULTI_WAY};
    Stage sandWorldCostumeStage = {"SandWorldCostumeStage", "abc", StageType::ONE_WAY};
    Stage sandWorldPyramid000Stage = {"SandWorldPyramid000Stage", "pyramid01", StageType::MULTI_WAY};
    Stage sandWorldPyramid001Stage = {"SandWorldPyramid001Stage", "pyramid03", StageType::MULTI_WAY};
    Stage sandWorldUnderground000Stage = {"SandWorldUnderground000Stage", "icestart", StageType::MULTI_WAY};
    Stage sandWorldUnderground001Stage = {"SandWorldUnderground001Stage", "Yadokari00", StageType::MULTI_WAY};
    Stage sandWorldRotateExStage = {"SandWorldRotateExStage", "biru", StageType::MULTI_WAY};
    Stage meganeLiftExStage = {"MeganeLiftExStage", "meganelift01", StageType::MULTI_WAY};
    Stage rocketFlowerExStage = {"RocketFlowerExStage", "rocket", StageType::ONE_WAY};
    Stage waterTubeExStage = {"WaterTubeExStage", "EX_2DHosui", StageType::MULTI_WAY};

    // Lake
    Stage lakeWorldHomeStageViaLakeWorldShopStage = {"LakeWorldHomeStage", "LakeWorldShop", StageType::MULTI_WAY};
    Stage lakeWorldHomeStageViaFastenerExStage = {"LakeWorldHomeStage", "FastenerEx", StageType::MULTI_WAY};
    Stage lakeWorldHomeStageViaTrampolineWallCatchExStage = {"LakeWorldHomeStage", "CapTrampolineB", StageType::MULTI_WAY};
    Stage lakeWorldHomeStageViaGotogotonExStage = {"LakeWorldHomeStage", "Goton", StageType::MULTI_WAY};
    Stage lakeWorldHomeStageViaFrogPoisonExStage = {"LakeWorldHomeStage", "LakeWorldMoonEX1b", StageType::MULTI_WAY};
    Stage lakeWorldShopStage = {"LakeWorldShopStage", "LakeWorldShop", StageType::ONE_WAY};
    Stage fastenerExStage = {"FastenerExStage", "FastenerEx", StageType::ONE_WAY};
    Stage trampolineWallCatchExStage = {"TrampolineWallCatchExStage", "CapTrampolineA", StageType::MULTI_WAY};
    Stage gotogotonExStage = {"GotogotonExStage", "Goton", StageType::ONE_WAY};
    Stage frogPoisonExStage = {"FrogPoisonExStage", "LakeWorldMoonEX1a", StageType::MULTI_WAY};

    // Wooded
    Stage forestWorldHomeStageViaForestWorldWaterExStage = {"ForestWorldHomeStage", "EX_Water_Exit", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldTowerStageBottom = {"ForestWorldHomeStage", "Tower001", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldTowerStageTop = {"ForestWorldHomeStage", "Tower002", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldBossStage = {"ForestWorldHomeStage", "boss002", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldBonusStage = {"ForestWorldHomeStage", "bonus2", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldCloudBonusExStage = {"ForestWorldHomeStage", "EXCloud", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaFogMountainExStage = {"ForestWorldHomeStage", "EX_Mist", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaRailCollisionExStage = {"ForestWorldHomeStage", "EX_RailCollision_Exit", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaShootingElevatorExStage = {"ForestWorldHomeStage", "EX_Tankuro_Exit", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldWoodsStageNearOdyssey = {"ForestWorldHomeStage", "Jyukai001v", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldWoodsStageNearFirebro = {"ForestWorldHomeStage", "Jyukai002", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldWoodsStageNearTalkatoo = {"ForestWorldHomeStage", "Jyukai003v", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldWoodsTreasureStage = {"ForestWorldHomeStage", "TreasureTree", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaForestWorldWoodsCostumeStage = {"ForestWorldHomeStage", "Explorer_Bonus", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaPackunPoisonExStage = {"ForestWorldHomeStage", "PoisonEx_Exit", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaAnimalChaseExStage = {"ForestWorldHomeStage", "EX_AnimalChase", StageType::MULTI_WAY};
    Stage forestWorldHomeStageViaKillerRoadExStage = {"ForestWorldHomeStage", "KillerRoad", StageType::MULTI_WAY};
    Stage forestWorldWaterExStage = {"ForestWorldWaterExStage", "EX_Water", StageType::MULTI_WAY};
    Stage forestWorldTowerStageBottom = {"ForestWorldTowerStage", "Tower001", StageType::MULTI_WAY};
    Stage forestWorldTowerStageTop = {"ForestWorldTowerStage", "Tower002", StageType::MULTI_WAY};
    Stage forestWorldBossStage = {"ForestWorldBossStage", "boss001", StageType::MULTI_WAY};
    Stage forestWorldBonusStage = {"ForestWorldBonusStage", "bonus1", StageType::MULTI_WAY};
    Stage forestWorldCloudBonusExStage = {"ForestWorldCloudBonusExStage", "EXCloud", StageType::ONE_WAY};
    Stage fogMountainExStage = {"FogMountainExStage", "EX_Mist", StageType::ONE_WAY};
    Stage railCollisionExStage = {"RailCollisionExStage", "EX_RailCollision", StageType::MULTI_WAY};
    Stage shootingElevatorExStage = {"ShootingElevatorExStage", "EX_Tankuro", StageType::MULTI_WAY};
    Stage forestWorldWoodsStageNearOdyssey = {"ForestWorldWoodsStage", "Jyukai001", StageType::MULTI_WAY};
    Stage forestWorldWoodsStageNearTalkatoo = {"ForestWorldWoodsStage", "Jyukai003", StageType::MULTI_WAY};
    Stage forestWorldWoodsTreasureStage = {"ForestWorldWoodsTreasureStage", "TreasureTree", StageType::ONE_WAY};
    Stage forestWorldWoodsCostumeStage = {"ForestWorldWoodsCostumeStage", "Explorer_Bonus", StageType::ONE_WAY};
    Stage packunPoisonExStage = {"PackunPoisonExStage", "PoisonEx", StageType::MULTI_WAY};
    Stage animalChaseExStage = {"AnimalChaseExStage", "EX_AnimalChase", StageType::ONE_WAY};
    Stage killerRoadExStage = {"KillerRoadExStage", "KillerRoad", StageType::ONE_WAY};

    // Cloud
    Stage cloudWorldHomeStageViaFukuwaraiKuriboStage = {"CloudWorldHomeStage", "Fukuwarai", StageType::MULTI_WAY};
    Stage cloudWorldHomeStageViaCube2DExStage = {"CloudWorldHomeStage", "cube", StageType::MULTI_WAY};
    Stage fukuwaraiKuriboStage = {"FukuwaraiKuriboStage", "Fukuwarai", StageType::ONE_WAY};
    Stage cube2DExStage = {"Cube2DExStage", "cube", StageType::ONE_WAY};

    // Lost
    Stage clashWorldHomeStageViaClashWorldShopStage = {"ClashWorldHomeStage", "Kinopio", StageType::MULTI_WAY};
    Stage clashWorldHomeStageViaImomuPoisonExStage = {"ClashWorldHomeStage", "imomu_02", StageType::MULTI_WAY};
    Stage clashWorldHomeStageViaJangoExStage = {"ClashWorldHomeStage", "ClashWorldMoonEX2", StageType::MULTI_WAY};
    Stage clashWorldShopStage = {"ClashWorldShopStage", "Kinopio", StageType::ONE_WAY};
    Stage imomuPoisonExStage = {"ImomuPoisonExStage", "imomu_01", StageType::MULTI_WAY};
    Stage jangoExStage = {"JangoExStage", "ClashWorldMoonEX2", StageType::ONE_WAY};

    // Metro
    Stage cityWorldHomeStageViaCityWorldMainTowerStageBottom = {"CityWorldHomeStage", "main_enter", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityWorldMainTowerStageTop = {"CityWorldHomeStage", "main_exit", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityWorldFactoryStage = {"CityWorldHomeStage", "under001enter", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityWorldShop01StageYellow = {"CityWorldHomeStage", "shop_coin", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityWorldShop01StagePurple = {"CityWorldHomeStage", "shop_correct", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityWorldSandSlotStage = {"CityWorldHomeStage", "Bonus", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityPeopleRoadStagePrePeace = {"CityWorldHomeStage", "gunsyu", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCityPeopleRoadStagePostPeace = {"CityWorldHomeStage", "gunsyudokan", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaPoleGrabCeilExStage = {"CityWorldHomeStage", "tenjo", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaTrexBikeExStage = {"CityWorldHomeStage", "bike02return", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaPoleKillerExStage = {"CityWorldHomeStage", "boureturn", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaNote2D3DRoomExStage = {"CityWorldHomeStage", "onpu", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaShootingCityExStage = {"CityWorldHomeStage", "taxireturn", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaCapRotatePackunExStage = {"CityWorldHomeStage", "kaitendokan", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaRadioControlExStage = {"CityWorldHomeStage", "car", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaElectricWireExStage = {"CityWorldHomeStage", "densendokan", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaTheater2DExStage = {"CityWorldHomeStage", "theater", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaDonsukeExStage = {"CityWorldHomeStage", "donsuke", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaSwingSteelExStage = {"CityWorldHomeStage", "gragrareturn", StageType::MULTI_WAY};
    Stage cityWorldHomeStageViaBikeSteelExStage = {"CityWorldHomeStage", "bikereturn", StageType::MULTI_WAY};
    Stage cityWorldMainTowerStageBottom = {"CityWorldMainTowerStage", "main_enter", StageType::MULTI_WAY};
    Stage cityWorldMainTowerStageTop = {"CityWorldMainTowerStage", "main_exit", StageType::MULTI_WAY};
    Stage cityWorldFactoryStage = {"CityWorldFactoryStage", "under001enter", StageType::ONE_WAY};
    Stage cityWorldShop01StageYellow = {"CityWorldShop01Stage", "shop_coin", StageType::MULTI_WAY};
    Stage cityWorldShop01StagePurple = {"CityWorldShop01Stage", "shop_correct", StageType::MULTI_WAY};
    Stage cityWorldSandSlotStage = {"CityWorldSandSlotStage", "Bonus", StageType::ONE_WAY};
    Stage cityPeopleRoadStageEntrance = {"CityPeopleRoadStage", "gunsyu", StageType::MULTI_WAY};
    Stage cityPeopleRoadStageExit = {"CityPeopleRoadStage", "gunsyudokan", StageType::MULTI_WAY};
    Stage poleGrabCeilExStage = {"PoleGrabCeilExStage", "tenjo", StageType::ONE_WAY};
    Stage trexBikeExStage = {"TrexBikeExStage", "bike02", StageType::MULTI_WAY};
    Stage poleKillerExStage = {"PoleKillerExStage", "bou", StageType::MULTI_WAY};
    Stage note2D3DRoomExStage = {"Note2D3DRoomExStage", "onpu", StageType::ONE_WAY};
    Stage shootingCityExStage = {"ShootingCityExStage", "taxi", StageType::MULTI_WAY};
    Stage capRotatePackunExStage = {"CapRotatePackunExStage", "kaitendokan", StageType::ONE_WAY};
    Stage radioControlExStage = {"RadioControlExStage", "car", StageType::ONE_WAY};
    Stage electricWireExStage = {"ElectricWireExStage", "densen", StageType::MULTI_WAY};
    Stage theater2DExStage = {"Theater2DExStage", "theater", StageType::ONE_WAY};
    Stage donsukeExStage = {"DonsukeExStage", "donsuke", StageType::ONE_WAY};
    Stage swingSteelExStage = {"SwingSteelExStage", "gragra", StageType::MULTI_WAY};
    Stage bikeSteelExStage = {"BikeSteelExStage", "bike", StageType::MULTI_WAY};

    // Snow
    Stage snowWorldHomeStageViaSnowWorldTownStage = {"SnowWorldHomeStage", "SnowUGExit", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaSnowWorldShopStage = {"SnowWorldHomeStage", "ShopDoor", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaSnowWorldCostumeStage = {"SnowWorldHomeStage", "SnowCostumeEx", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaSnowWorldCloudBonusExStage = {"SnowWorldHomeStage", "EX_SkyBonus", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaIceWalkerExStage = {"SnowWorldHomeStage", "FigureWalker", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaIceWaterBlockExStage = {"SnowWorldHomeStage", "EX_IceWater_Exit", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaByugoPuzzleExStage = {"SnowWorldHomeStage", "ByugoPuzzle", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaIceWaterDashExStage = {"SnowWorldHomeStage", "EX_IceWaterDash_Exit", StageType::MULTI_WAY};
    Stage snowWorldHomeStageViaKillerRailCollisionExStage = {"SnowWorldHomeStage", "EX_RailCol2_Exit", StageType::MULTI_WAY};
    Stage snowWorldTownStage = {"SnowWorldTownStage", "SnowUGEnt", StageType::MULTI_WAY};
    Stage snowWorldShopStage = {"SnowWorldShopStage", "ShopDoor", StageType::ONE_WAY};
    Stage snowWorldCostumeStage = {"SnowWorldCostumeStage", "SnowCostumeEx", StageType::ONE_WAY};
    Stage snowWorldCloudBonusExStage = {"SnowWorldCloudBonusExStage", "EX_SkyBonus", StageType::ONE_WAY};
    Stage iceWalkerExStage = {"IceWalkerExStage", "FigureWalker", StageType::ONE_WAY};
    Stage iceWaterBlockExStage = {"IceWaterBlockExStage", "EX_IceWater", StageType::MULTI_WAY};
    Stage byugoPuzzleExStage = {"ByugoPuzzleExStage", "ByugoPuzzle", StageType::ONE_WAY};
    Stage iceWaterDashExStage = {"IceWaterDashExStage", "EX_IceWaterDash", StageType::MULTI_WAY};
    Stage killerRailCollisionExStage = {"KillerRailCollisionExStage", "EX_RailCol2", StageType::MULTI_WAY};

    // Seaside
    Stage seaWorldHomeStageViaSeaWorldUtsuboCaveStage = {"SeaWorldHomeStage", "PukupukuCaveGoal", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaSeaWorldVibrationStage = {"SeaWorldHomeStage", "shindo_Lv2", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaSeaWorldSecretStage = {"SeaWorldHomeStage", "TreasureEventWorldSea", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaSeaWorldCostumeStage = {"SeaWorldHomeStage", "CostumeEventSeaWorld", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaSeaWorldSneakingManStage = {"SeaWorldHomeStage", "RoomEventWorldSea", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaSenobiTowerExStage = {"SeaWorldHomeStage", "SeaWorldEX3b", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaCloudExStage = {"SeaWorldHomeStage", "SeaWorldEX2Return", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaWaterValleyExStage = {"SeaWorldHomeStage", "SeaWorldEX1b", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaReflectBombExStage = {"SeaWorldHomeStage", "SeaWorldMoonEX1a", StageType::MULTI_WAY};
    Stage seaWorldHomeStageViaTogezoRotateExStage = {"SeaWorldHomeStage", "SeaWorldMoonEX2", StageType::MULTI_WAY};
    Stage seaWorldUtsuboCaveStage = {"SeaWorldUtsuboCaveStage", "PukupukuCaveStart", StageType::MULTI_WAY};
    Stage seaWorldVibrationStage = {"SeaWorldVibrationStage", "shindo_Lv2", StageType::ONE_WAY};
    Stage seaWorldSecretStage = {"SeaWorldSecretStage", "TreasureEventWorldSea", StageType::ONE_WAY};
    Stage seaWorldCostumeStage = {"SeaWorldCostumeStage", "CostumeEventSeaWorld", StageType::ONE_WAY};
    Stage seaWorldSneakingManStage = {"SeaWorldSneakingManStage", "RoomEventWorldSea", StageType::ONE_WAY};
    Stage senobiTowerExStage = {"SenobiTowerExStage", "SeaWorldEX3a", StageType::MULTI_WAY};
    Stage cloudExStage = {"CloudExStage", "SeaWorldEX2", StageType::MULTI_WAY};
    Stage waterValleyExStage = {"WaterValleyExStage", "SeaWorldEX1a", StageType::MULTI_WAY};
    Stage reflectBombExStage = {"ReflectBombExStage", "SeaWorldMoonEX1a", StageType::ONE_WAY};
    Stage togezoRotateExStage = {"TogezoRotateExStage", "SeaWorldMoonEX2", StageType::ONE_WAY};

    // Luncheon
    Stage lavaWorldHomeStageViaLavaWorldUpDownExStage = {"LavaWorldHomeStage", "KeyMoveExDokan", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaBonus1Zone = {"LavaWorldHomeStage", "town", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldShopStage = {"LavaWorldHomeStage", "shop", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldCostumeStage = {"LavaWorldHomeStage", "CostumeOut", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaForkExStage = {"LavaWorldHomeStage", "ForkEX", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldExcavationExStage = {"LavaWorldHomeStage", "MartinCubeEx", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldClockExStage = {"LavaWorldHomeStage", "BBQExDokan", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldBubbleLaneExStage = {"LavaWorldHomeStage", "PechoBubbleExDokan", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldTreasureStage = {"LavaWorldHomeStage", "TreasureEventWorldLava", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaGabuzouClockExStage = {"LavaWorldHomeStage", "GabuzouClockExdokan", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaCapAppearLavaLiftExStage = {"LavaWorldHomeStage", "LavaLiftExdokan", StageType::MULTI_WAY};
    Stage lavaWorldHomeStageViaLavaWorldFenceLiftExStage = {"LavaWorldHomeStage", "FenceLiftExdokan", StageType::MULTI_WAY};
    Stage lavaWorldUpDownExStage = {"LavaWorldUpDownExStage", "KeyMoveEx", StageType::MULTI_WAY};
    Stage lavaBonus1Zone = {"LavaBonus1Zone", "town", StageType::ONE_WAY};
    Stage lavaWorldShopStage = {"LavaWorldShopStage", "shop", StageType::ONE_WAY};
    Stage lavaWorldCostumeStage = {"LavaWorldCostumeStage", "CostumeEventWorldLava", StageType::MULTI_WAY};
    Stage forkExStage = {"ForkExStage", "ForkEX", StageType::ONE_WAY};
    Stage lavaWorldExcavationExStage = {"LavaWorldExcavationExStage", "MartinCubeEx", StageType::ONE_WAY};
    Stage lavaWorldClockExStage = {"LavaWorldClockExStage", "BBQEx", StageType::MULTI_WAY};
    Stage lavaWorldBubbleLaneExStage = {"LavaWorldBubbleLaneExStage", "PechoBubbleEx", StageType::MULTI_WAY};
    Stage lavaWorldTreasureStage = {"LavaWorldTreasureStage", "TreasureEventWorldLava", StageType::ONE_WAY};
    Stage gabuzouClockExStage = {"GabuzouClockExStage", "GabuzouClockEx", StageType::MULTI_WAY};
    Stage capAppearLavaLiftExStage = {"CapAppearLavaLiftExStage", "LavaLiftEx", StageType::MULTI_WAY};
    Stage lavaWorldFenceLiftExStage = {"LavaWorldFenceLiftExStage", "FenceLiftEx", StageType::MULTI_WAY};

    // Ruined
    Stage bossRaidWorldHomeStageViaDotTowerExStage = {"BossRaidWorldHomeStage", "BossRaidWorldEx01_Eixt", StageType::MULTI_WAY};
    Stage bossRaidWorldHomeStageViaBullRunExStage = {"BossRaidWorldHomeStage", "BossRaidWorldMoonEx02_Exit", StageType::MULTI_WAY};
    Stage dotTowerExStage = {"DotTowerExStage", "BossRaidWorldEx01_Eixt", StageType::ONE_WAY};
    Stage bullRunExStage = {"BullRunExStage", "BossRaidWorldMoonEx02_Enter", StageType::MULTI_WAY};

    // Bowsers
    Stage skyWorldHomeStageViaSkyWorldShopStage = {"SkyWorldHomeStage", "shop", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaSkyWorldCostumeStage = {"SkyWorldHomeStage", "byoubu", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaSkyWorldCloudBonusExStage = {"SkyWorldHomeStage", "sora001", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaSkyWorldTreasureStage = {"SkyWorldHomeStage", "shopdress", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaJizoSwitchExStage = {"SkyWorldHomeStage", "jizo01", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaTsukkunRotateExStage = {"SkyWorldHomeStage", "tukkun000_exit", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaKaronWingTowerStage = {"SkyWorldHomeStage", "Patakaron02", StageType::MULTI_WAY};
    Stage skyWorldHomeStageViaTsukkunClimbExStage = {"SkyWorldHomeStage", "tukkun001_exit", StageType::MULTI_WAY};
    Stage skyWorldShopStage = {"SkyWorldShopStage", "shop", StageType::ONE_WAY};
    Stage skyWorldCostumeStage = {"SkyWorldCostumeStage", "byoubu", StageType::ONE_WAY};
    Stage skyWorldCloudBonusExStage = {"SkyWorldCloudBonusExStage", "sora001", StageType::ONE_WAY};
    Stage skyWorldTreasureStage = {"SkyWorldTreasureStage", "shopdress", StageType::ONE_WAY};
    Stage jizoSwitchExStage = {"JizoSwitchExStage", "jizo01", StageType::ONE_WAY};
    Stage tsukkunRotateExStage = {"TsukkunRotateExStage", "tukkun000_enter", StageType::MULTI_WAY};
    Stage karonWingTowerStage = {"KaronWingTowerStage", "Patakaron02", StageType::ONE_WAY};
    Stage tsukkunClimbExStage = {"TsukkunClimbExStage", "tukkun001_enter", StageType::MULTI_WAY};

    // Mushroom
    Stage peachWorldHomeStageViaPeachWorldShopStage = {"PeachWorldHomeStage", "PeachWorldShopA", StageType::MULTI_WAY};
    Stage peachWorldHomeStageViaPeachWorldCostumeStage = {"PeachWorldHomeStage", "CostumeEventWorldPeach", StageType::MULTI_WAY};
    Stage peachWorldHomeStageViaFukuwaraiMarioStage = {"PeachWorldHomeStage", "Fukuwarai2", StageType::MULTI_WAY};
    Stage peachWorldHomeStageViaDotHardExStage = {"PeachWorldHomeStage", "PeachWorldEx2a", StageType::MULTI_WAY};
    Stage peachWorldHomeStageViaYoshiCloudExStage = {"PeachWorldHomeStage", "PeachWorldEx1a", StageType::MULTI_WAY};
    Stage peachWorldShopStage = {"PeachWorldShopStage", "PeachWorldShopA", StageType::ONE_WAY};
    Stage peachWorldCostumeStage = {"PeachWorldCostumeStage", "CostumeEventWorldPeach", StageType::ONE_WAY};
    Stage fukuwaraiMarioStage = {"FukuwaraiMarioStage", "Fukuwarai2", StageType::ONE_WAY};
    Stage dotHardExStage = {"DotHardExStage", "PeachWorldEx2a", StageType::ONE_WAY};
    Stage yoshiCloudExStage = {"YoshiCloudExStage", "PeachWorldEx1a", StageType::ONE_WAY};

    
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
