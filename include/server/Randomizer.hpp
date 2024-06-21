#pragma once

#include "sead/heap/seadDisposer.h"
#include "heap/seadExpHeap.h"
#include "sead/container/seadObjArray.h"
#include "sead/container/seadTList.h"
#include "sead/container/seadTreeMap.h"
#include "sead/container/seadTreeNode.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include "game/GameData/GameDataHolderWriter.h"
#include <utility>


enum StageType : unsigned int {
    OVER_WORLD,
    SUB_AREA
};

enum ExitType : unsigned int {
    ONE_WAY,
    MULTI_WAY
};

struct Transition {
    const char* overWorld;
    const char* subArea;
    const char* warpId;
};

struct TransitionPoint {
    const char* stage;
    const char* warpId;
};

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

    sead::TreeMap<const char*, StageType> stageTypeMap;
    sead::TreeMap<const char*, ExitType> exitTypeMap;
    sead::TList<std::pair<TransitionPoint, TransitionPoint>> transitionList;
    sead::ObjArray<std::pair<TransitionPoint, TransitionPoint>> transitionObjArray;

    // Cap
    static constexpr Transition capWorldHomeStageAndCapWorldTowerStageBottomTransition = {"CapWorldHomeStage", "CapWorldTowerStage", "Ex"};
    static constexpr Transition capWorldHomeStageAndCapWorldTowerStageTopTransition = {"CapWorldHomeStage", "CapWorldTowerStage", "Goal"};
    static constexpr Transition capWorldHomeStageAndFrogSearchExStageTransition = {"CapWorldHomeStage", "FrogSearchExStage", "FrogSearchExStageEnt"};
    static constexpr Transition capWorldHomeStageAndPoisonWaveExStageEntranceTransition = {"CapWorldHomeStage", "PoisonWaveExStage", "PoisonWaveExEnt"};
    static constexpr Transition capWorldHomeStageAndPoisonWaveExStageExitTransition = {"CapWorldHomeStage", "PoisonWaveExStage", "PoisonWaveExExit"};
    static constexpr Transition capWorldHomeStageAndPushBlockExStageEntranceTransition = {"CapWorldHomeStage", "PushBlockExStage", "PushBlockExStageEnt"};
    static constexpr Transition capWorldHomeStageAndPushBlockExStageExitTransition = {"CapWorldHomeStage", "PushBlockExStage", "PushBlockExStageEntDokan"};
    static constexpr Transition capWorldHomeStageAndRollingExStageEntranceTransition = {"CapWorldHomeStage", "RollingExStage", "rollingstart"};
    static constexpr Transition capWorldHomeStageAndRollingExStageExitTransition = {"CapWorldHomeStage", "RollingExStage", "rollinggoal"};

    // Cascade
    static constexpr Transition waterfallWorldHomeStageAndTrexPoppunExStageTransition = {"WaterfallWorldHomeStage", "TrexPoppunExStage", "RexPoppunEx"};
    static constexpr Transition waterfallWorldHomeStageAndLift2DExStageEntranceTransition = {"WaterfallWorldHomeStage", "Lift2DExStage", "Lift2D"};
    static constexpr Transition waterfallWorldHomeStageAndLift2DExStageExitTransition = {"WaterfallWorldHomeStage", "Lift2DExStage", "Lift2DExit"};
    static constexpr Transition waterfallWorldHomeStageAndWanwanClashExStageEntranceTransition = {"WaterfallWorldHomeStage", "WanwanClashExStage", "WanwanExStart"};
    static constexpr Transition waterfallWorldHomeStageAndWanwanClashExStageExitTransition = {"WaterfallWorldHomeStage", "WanwanClashExStage", "WanwanExGoal"};
    static constexpr Transition waterfallWorldHomeStageAndCapAppearExStageEntranceTransition = {"WaterfallWorldHomeStage", "CapAppearExStage", "CapAppearExEnt"};
    static constexpr Transition waterfallWorldHomeStageAndCapAppearExStageExitTransition = {"WaterfallWorldHomeStage", "CapAppearExStage", "CapAppearExExit"};
    static constexpr Transition waterfallWorldHomeStageAndWindBlowExStageEntranceTransition = {"WaterfallWorldHomeStage", "WindBlowExStage", "WindBlowExStart"};
    static constexpr Transition waterfallWorldHomeStageAndWindBlowExStageExitTransition = {"WaterfallWorldHomeStage", "WindBlowExStage", "WindBlowExGoal"};
    
    // Sand
    static constexpr Transition sandWorldHomeStageAndSandWorldShopStageFrontTransition = {"SandWorldHomeStage", "SandWorldShopStage", "bar1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldShopStageBackTransition = {"SandWorldHomeStage", "SandWorldShopStage", "bar2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSlotStageTransition = {"SandWorldHomeStage", "SandWorldSlotStage", "town"};
    static constexpr Transition sandWorldHomeStageAndSandWorldVibrationStageTransition = {"SandWorldHomeStage", "SandWorldVibrationStage", "shindo"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSecretStageTransition = {"SandWorldHomeStage", "SandWorldSecretStage", "hide"};
    static constexpr Transition sandWorldHomeStageAndSandWorldMeganeExStageEntranceTransition = {"SandWorldHomeStage", "SandWorldMeganeExStage", "anki2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldMeganeExStageExitTransition = {"SandWorldHomeStage", "SandWorldMeganeExStage", "wall"};
    static constexpr Transition sandWorldHomeStageAndSandWorldKillerExStageEntranceTransition = {"SandWorldHomeStage", "SandWorldKillerExStage", "doukutu1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldKillerExStageExitTransition = {"SandWorldHomeStage", "SandWorldKillerExStage", "doukutu2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPressExStageEntranceTransition = {"SandWorldHomeStage", "SandWorldPressExStage", "arijigoku1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPressExStageExitTransition = {"SandWorldHomeStage", "SandWorldPressExStage", "arijigoku2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSphinxExStageEntranceTransition = {"SandWorldHomeStage", "SandWorldSphinxExStage", "run00"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSphinxExStageExitTransition = {"SandWorldHomeStage", "SandWorldSphinxExStage", "run00return"};
    static constexpr Transition sandWorldHomeStageAndSandWorldCostumeStageTransition = {"SandWorldHomeStage", "SandWorldCostumeStage", "abc"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid000StageEntranceTransition = {"SandWorldHomeStage", "SandWorldPyramid000Stage", "pyramid01"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid000StageExitTransition = {"SandWorldHomeStage", "SandWorldPyramid000Stage", "pyramid02"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid001StageEntranceTransition = {"SandWorldHomeStage", "SandWorldPyramid001Stage", "pyramid03"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid001StageExitTransition = {"SandWorldHomeStage", "SandWorldPyramid001Stage", "pyramid04"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground000StageEntranceTransition = {"SandWorldHomeStage", "SandWorldUnderground000Stage", "icestart"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground000StageExitTransition = {"SandWorldHomeStage", "SandWorldUnderground000Stage", "Under01"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground001StageEntranceTransition = {"SandWorldHomeStage", "SandWorldUnderground001Stage", "Yadokari00"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground001StageExitTransition = {"SandWorldHomeStage", "SandWorldUnderground001Stage", "Out"};
    static constexpr Transition sandWorldHomeStageAndSandWorldRotateExStageEntranceTransition = {"SandWorldHomeStage", "SandWorldRotateExStage", "biru"};
    static constexpr Transition sandWorldHomeStageAndSandWorldRotateExStageExitTransition = {"SandWorldHomeStage", "SandWorldRotateExStage", "birureturn"};
    static constexpr Transition sandWorldHomeStageAndMeganeLiftExStageEntranceTransition = {"SandWorldHomeStage", "MeganeLiftExStage", "meganelift01"};
    static constexpr Transition sandWorldHomeStageAndMeganeLiftExStageExitTransition = {"SandWorldHomeStage", "MeganeLiftExStage", "meganelift02"};
    static constexpr Transition sandWorldHomeStageAndRocketFlowerExStageTransition = {"SandWorldHomeStage", "RocketFlowerExStage", "rocket"};
    static constexpr Transition sandWorldHomeStageAndWaterTubeExStageEntranceTransition = {"SandWorldHomeStage", "WaterTubeExStage", "EX_2DHosui"};
    static constexpr Transition sandWorldHomeStageAndWaterTubeExStageExitTransition = {"SandWorldHomeStage", "WaterTubeExStage", "EX_2DHosui_Exit"};
    
    // Lake
    static constexpr Transition lakeWorldHomeStageAndLakeWorldShopStageTransition = {"LakeWorldHomeStage", "LakeWorldHomeStage", "LakeWorldShop"};
    static constexpr Transition lakeWorldHomeStageAndFastenerExStageTransition = {"LakeWorldHomeStage", "FastenerExStage", "FastenerEx"};
    static constexpr Transition lakeWorldHomeStageAndTrampolineWallCatchExStageEntranceTransition = {"LakeWorldHomeStage", "TrampolineWallCatchExStage", "CapTrampolineA"};
    static constexpr Transition lakeWorldHomeStageAndTrampolineWallCatchExStageExitTransition = {"LakeWorldHomeStage", "TrampolineWallCatchExStage", "CapTrampolineB"};
    static constexpr Transition lakeWorldHomeStageAndGotogotonExStageTransition = {"LakeWorldHomeStage", "GotogotonExStage", "Goton"};
    static constexpr Transition lakeWorldHomeStageAndFrogPoisonExStageEntranceTransition = {"LakeWorldHomeStage", "FrogPoisonExStage", "LakeWorldMoonEX1a"};
    static constexpr Transition lakeWorldHomeStageAndFrogPoisonExStageExitTransition = {"LakeWorldHomeStage", "FrogPoisonExStage", "LakeWorldMoonEX1b"};
    
    // Wooded
    static constexpr Transition forestWorldHomeStageAndForestWorldWaterExStageEntranceTransition = {"ForestWorldHomeStage", "ForestWorldWaterExStage", "EX_Water"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWaterExStageExitTransition = {"ForestWorldHomeStage", "ForestWorldWaterExStage", "EX_Water_Exit"};
    static constexpr Transition forestWorldHomeStageAndForestWorldTowerStageBottomTransition = {"ForestWorldHomeStage", "ForestWorldTowerStage", "Tower001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldTowerStageTopTransition = {"ForestWorldHomeStage", "ForestWorldTowerStage", "Tower002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBossStageEntranceTransition = {"ForestWorldHomeStage", "ForestWorldBossStage", "boss001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBossStageExitTransition = {"ForestWorldHomeStage", "ForestWorldBossStage", "boss002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBonusStageEntranceTransition = {"ForestWorldHomeStage", "ForestWorldBonusStage", "bonus1"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBonusStageExitTransition = {"ForestWorldHomeStage", "ForestWorldBonusStage", "bonus2"};
    static constexpr Transition forestWorldHomeStageAndForestWorldCloudBonusExStageTransition = {"ForestWorldHomeStage", "ForestWorldCloudBonusExStage", "EXCloud"};
    static constexpr Transition forestWorldHomeStageAndFogMountainExStageTransition = {"ForestWorldHomeStage", "FogMountainExStage", "EX_Mist"};
    static constexpr Transition forestWorldHomeStageAndRailCollisionExStageEntranceTransition = {"ForestWorldHomeStage", "RailCollisionExStage", "EX_RailCollision"};
    static constexpr Transition forestWorldHomeStageAndRailCollisionExStageExitTransition = {"ForestWorldHomeStage", "RailCollisionExStage", "EX_RailCollision_Exit"};
    static constexpr Transition forestWorldHomeStageAndShootingElevatorExStageEntranceTransition = {"ForestWorldHomeStage", "ShootingElevatorExStage", "EX_Tankuro"};
    static constexpr Transition forestWorldHomeStageAndShootingElevatorExStageExitTransition = {"ForestWorldHomeStage", "ShootingElevatorExStage", "EX_Tankuro_Exit"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageOdysseyEntranceTransition = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageOdysseyExitTransition = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai001v"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageFirebroTransition = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageTalkatooEntranceTransition = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai003"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageTalkatooExitTransition = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai003v"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsTreasureStageTransition = {"ForestWorldHomeStage", "ForestWorldWoodsTreasureStage", "TreasureTree"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsCostumeStageTransition = {"ForestWorldHomeStage", "ForestWorldWoodsCostumeStage", "Explorer_Bonus"};
    static constexpr Transition forestWorldHomeStageAndPackunPoisonExStageEntranceTransition = {"ForestWorldHomeStage", "PackunPoisonExStage", "PoisonEx"};
    static constexpr Transition forestWorldHomeStageAndPackunPoisonExStageExitTransition = {"ForestWorldHomeStage", "PackunPoisonExStage", "PoisonEx_Exit"};
    static constexpr Transition forestWorldHomeStageAndAnimalChaseExStageTransition = {"ForestWorldHomeStage", "AnimalChaseExStage", "EX_AnimalChase"};
    static constexpr Transition forestWorldHomeStageAndKillerRoadExStageTransition = {"ForestWorldHomeStage", "KillerRoadExStage", "KillerRoad"};
    
    // Cloud
    static constexpr Transition cloudWorldHomeStageAndFukuwaraiKuriboStageTransition = {"CloudWorldHomeStage", "FukuwaraiKuriboStage", "Fukuwarai"};
    static constexpr Transition cloudWorldHomeStageAndCube2DExStageTransition = {"CloudWorldHomeStage", "Cube2DExStage", "cube"};
    
    // Lost
    static constexpr Transition clashWorldHomeStageAndClashWorldShopStageTransition = {"ClashWorldHomeStage", "ClashWorldShopStage", "Kinopio"};
    static constexpr Transition clashWorldHomeStageAndImomuPoisonExStageEntranceTransition = {"ClashWorldHomeStage", "ImomuPoisonExStage", "imomu_01"};
    static constexpr Transition clashWorldHomeStageAndImomuPoisonExStageExitTransition = {"ClashWorldHomeStage", "ImomuPoisonExStage", "imomu_02"};
    static constexpr Transition clashWorldHomeStageAndJangoExStageTransition = {"ClashWorldHomeStage", "JangoExStage", "ClashWorldMoonEX2"};
    
    // Metro
    static constexpr Transition cityWorldHomeStageAndCityWorldMainTowerStageBottomTransition = {"CityWorldHomeStage", "CityWorldMainTowerStage", "main_enter"};
    static constexpr Transition cityWorldHomeStageAndCityWorldMainTowerStageTopTransition = {"CityWorldHomeStage", "CityWorldMainTowerStage", "main_exit"};
    static constexpr Transition cityWorldHomeStageAndCityWorldFactoryStageTransition = {"CityWorldHomeStage", "CityWorldFactoryStage", "under001enter"};
    static constexpr Transition cityWorldHomeStageAndCityWorldShop01StageYellowTransition = {"CityWorldHomeStage", "CityWorldShop01Stage", "shop_coin"};
    static constexpr Transition cityWorldHomeStageAndCityWorldShop01StagePurpleTransition = {"CityWorldHomeStage", "CityWorldShop01Stage", "shop_correct"};
    static constexpr Transition cityWorldHomeStageAndCityWorldSandSlotStageTransition = {"CityWorldHomeStage", "CityWorldSandSlotStage", "Bonus"};
    static constexpr Transition cityWorldHomeStageAndCityPeopleRoadStageEntranceTransition = {"CityWorldHomeStage", "CityPeopleRoadStage", "gunsyu"};
    static constexpr Transition cityWorldHomeStageAndCityPeopleRoadStageExitTransition = {"CityWorldHomeStage", "CityPeopleRoadStage", "gunsyudokan"};
    static constexpr Transition cityWorldHomeStageAndPoleGrabCeilExStageTransition = {"CityWorldHomeStage", "PoleGrabCeilExStage", "tenjo"};
    static constexpr Transition cityWorldHomeStageAndTrexBikeExStageEntranceTransition = {"CityWorldHomeStage", "TrexBikeExStage", "bike02"};
    static constexpr Transition cityWorldHomeStageAndTrexBikeExStageExitTransition = {"CityWorldHomeStage", "TrexBikeExStage", "bike02return"};
    static constexpr Transition cityWorldHomeStageAndPoleKillerExStageEntranceTransition = {"CityWorldHomeStage", "PoleKillerExStage", "bou"};
    static constexpr Transition cityWorldHomeStageAndPoleKillerExStageExitTransition = {"CityWorldHomeStage", "PoleKillerExStage", "boureturn"};
    static constexpr Transition cityWorldHomeStageAndNote2D3DRoomExStageTransition = {"CityWorldHomeStage", "Note2D3DRoomExStage", "onpu"};
    static constexpr Transition cityWorldHomeStageAndShootingCityExStageEntranceTransition = {"CityWorldHomeStage", "ShootingCityExStage", "taxi"};
    static constexpr Transition cityWorldHomeStageAndShootingCityExStageExitTransition = {"CityWorldHomeStage", "ShootingCityExStage", "taxireturn"};
    static constexpr Transition cityWorldHomeStageAndCapRotatePackunExStageTransition = {"CityWorldHomeStage", "CapRotatePackunExStage", "kaitendokan"};
    static constexpr Transition cityWorldHomeStageAndRadioControlExStageTransition = {"CityWorldHomeStage", "RadioControlExStage", "car"};
    static constexpr Transition cityWorldHomeStageAndElectricWireExStageEntranceTransition = {"CityWorldHomeStage", "ElectricWireExStage", "densen"};
    static constexpr Transition cityWorldHomeStageAndElectricWireExStageExitTransition = {"CityWorldHomeStage", "ElectricWireExStage", "densendokan"};
    static constexpr Transition cityWorldHomeStageAndTheater2DExStageTransition = {"CityWorldHomeStage", "Theater2DExStage", "theater"};
    static constexpr Transition cityWorldHomeStageAndDonsukeExStageTransition = {"CityWorldHomeStage", "DonsukeExStage", "donsuke"};
    static constexpr Transition cityWorldHomeStageAndSwingSteelExStageEntranceTransition = {"CityWorldHomeStage", "SwingSteelExStage", "gragra"};
    static constexpr Transition cityWorldHomeStageAndSwingSteelExStageExitTransition = {"CityWorldHomeStage", "SwingSteelExStage", "gragrareturn"};
    static constexpr Transition cityWorldHomeStageAndBikeSteelExStageEntranceTransition = {"CityWorldHomeStage", "BikeSteelExStage", "bike"};
    static constexpr Transition cityWorldHomeStageAndBikeSteelExStageExitTransition = {"CityWorldHomeStage", "BikeSteelExStage", "bikereturn"};
    
    // Snow
    static constexpr Transition snowWorldHomeStageAndSnowWorldTownStageEntranceTransition = {"SnowWorldHomeStage", "SnowWorldTownStage", "SnowUGEnt"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldTownStageExitTransition = {"SnowWorldHomeStage", "SnowWorldTownStage", "SnowUGExit"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldShopStageTransition = {"SnowWorldHomeStage", "SnowWorldShopStage", "ShopDoor"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldCostumeStageTransition = {"SnowWorldHomeStage", "SnowWorldCostumeStage", "SnowCostumeEx"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldCloudBonusExStageTransition = {"SnowWorldHomeStage", "SnowWorldCloudBonusExStage", "EX_SkyBonus"};
    static constexpr Transition snowWorldHomeStageAndIceWalkerExStageTransition = {"SnowWorldHomeStage", "IceWalkerExStage", "FigureWalker"};
    static constexpr Transition snowWorldHomeStageAndIceWaterBlockExStageEntranceTransition = {"SnowWorldHomeStage", "IceWaterBlockExStage", "EX_IceWater"};
    static constexpr Transition snowWorldHomeStageAndIceWaterBlockExStageExitTransition = {"SnowWorldHomeStage", "IceWaterBlockExStage", "EX_IceWater_Exit"};
    static constexpr Transition snowWorldHomeStageAndByugoPuzzleExStageTransition = {"SnowWorldHomeStage", "ByugoPuzzleExStage", "ByugoPuzzle"};
    static constexpr Transition snowWorldHomeStageAndIceWaterDashExStageEntranceTransition = {"SnowWorldHomeStage", "IceWaterDashExStage", "EX_IceWaterDash"};
    static constexpr Transition snowWorldHomeStageAndIceWaterDashExStageExitTransition = {"SnowWorldHomeStage", "IceWaterDashExStage", "EX_IceWaterDash_Exit"};
    static constexpr Transition snowWorldHomeStageAndKillerRailCollisionExStageEntranceTransition = {"SnowWorldHomeStage", "KillerRailCollisionExStage", "EX_RailCol2"};
    static constexpr Transition snowWorldHomeStageAndKillerRailCollisionExStageExitTransition = {"SnowWorldHomeStage", "KillerRailCollisionExStage", "EX_RailCol2_Exit"};
    
    // Seaside
    static constexpr Transition seaWorldHomeStageAndSeaWorldUtsuboCaveStageEntranceTransition = {"SeaWorldHomeStage", "SeaWorldUtsuboCaveStage", "PukupukuCaveStart"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldUtsuboCaveStageExitTransition = {"SeaWorldHomeStage", "SeaWorldUtsuboCaveStage", "PukupukuCaveGoal"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldVibrationStageTransition = {"SeaWorldHomeStage", "SeaWorldVibrationStage", "shindo_Lv2"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldSecretStageTransition = {"SeaWorldHomeStage", "SeaWorldSecretStage", "TreasureEventWorldSea"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldCostumeStageTransition = {"SeaWorldHomeStage", "SeaWorldCostumeStage", "CostumeEventSeaWorld"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldSneakingManStageTransition = {"SeaWorldHomeStage", "SeaWorldSneakingManStage", "RoomEventWorldSea"};
    static constexpr Transition seaWorldHomeStageAndSenobiTowerExStageEntranceTransition = {"SeaWorldHomeStage", "SenobiTowerExStage", "SeaWorldEX3a"};
    static constexpr Transition seaWorldHomeStageAndSenobiTowerExStageExitTransition = {"SeaWorldHomeStage", "SenobiTowerExStage", "SeaWorldEX3b"};
    static constexpr Transition seaWorldHomeStageAndCloudExStageEntranceTransition = {"SeaWorldHomeStage", "CloudExStage", "SeaWorldEX2"};
    static constexpr Transition seaWorldHomeStageAndCloudExStageExitTransition = {"SeaWorldHomeStage", "CloudExStage", "SeaWorldEX2Return"};
    static constexpr Transition seaWorldHomeStageAndWaterValleyExStageEntranceTransition = {"SeaWorldHomeStage", "WaterValleyExStage", "SeaWorldEX1a"};
    static constexpr Transition seaWorldHomeStageAndWaterValleyExStageExitTransition = {"SeaWorldHomeStage", "WaterValleyExStage", "SeaWorldEX1b"};
    static constexpr Transition seaWorldHomeStageAndReflectBombExStageTransition = {"SeaWorldHomeStage", "ReflectBombExStage", "SeaWorldMoonEX1a"};
    static constexpr Transition seaWorldHomeStageAndTogezoRotateExStageTransition = {"SeaWorldHomeStage", "TogezoRotateExStage", "SeaWorldMoonEX2"};
    
    // Luncheon
    static constexpr Transition lavaWorldHomeStageAndLavaWorldUpDownExStageEntranceTransition = {"LavaWorldHomeStage", "LavaWorldUpDownExStage", "KeyMoveEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldUpDownExStageExitTransition = {"LavaWorldHomeStage", "LavaWorldUpDownExStage", "KeyMoveExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaBonus1ZoneTransition = {"LavaWorldHomeStage", "LavaBonus1Zone", "town"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldShopStageTransition = {"LavaWorldHomeStage", "LavaWorldShopStage", "shop"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldCostumeStageEntranceTransition = {"LavaWorldHomeStage", "LavaWorldCostumeStage", "CostumeEventWorldLava"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldCostumeStageExitTransition = {"LavaWorldHomeStage", "LavaWorldCostumeStage", "CostumeOut"};
    static constexpr Transition lavaWorldHomeStageAndForkExStageTransition = {"LavaWorldHomeStage", "ForkExStage", "ForkEX"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldExcavationExStageTransition = {"LavaWorldHomeStage", "LavaWorldExcavationExStage", "MartinCubeEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldClockExStageEntranceTransition = {"LavaWorldHomeStage", "LavaWorldClockExStage", "BBQEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldClockExStageExitTransition = {"LavaWorldHomeStage", "LavaWorldClockExStage", "BBQExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldBubbleLaneExStageEntranceTransition = {"LavaWorldHomeStage", "LavaWorldBubbleLaneExStage", "PechoBubbleEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldBubbleLaneExStageExitTransition = {"LavaWorldHomeStage", "LavaWorldBubbleLaneExStage", "PechoBubbleExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldTreasureStageTransition = {"LavaWorldHomeStage", "LavaWorldTreasureStage", "TreasureEventWorldLava"};
    static constexpr Transition lavaWorldHomeStageAndGabuzouClockExStageEntranceTransition = {"LavaWorldHomeStage", "GabuzouClockExStage", "GabuzouClockEx"};
    static constexpr Transition lavaWorldHomeStageAndGabuzouClockExStageExitTransition = {"LavaWorldHomeStage", "GabuzouClockExStage", "GabuzouClockExdokan"};
    static constexpr Transition lavaWorldHomeStageAndCapAppearLavaLiftExStageEntranceTransition = {"LavaWorldHomeStage", "CapAppearLavaLiftExStage", "LavaLiftEx"};
    static constexpr Transition lavaWorldHomeStageAndCapAppearLavaLiftExStageExitTransition = {"LavaWorldHomeStage", "CapAppearLavaLiftExStage", "LavaLiftExdokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldFenceLiftExStageEntranceTransition = {"LavaWorldHomeStage", "LavaWorldFenceLiftExStage", "FenceLiftEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldFenceLiftExStageExitTransition = {"LavaWorldHomeStage", "LavaWorldFenceLiftExStage", "FenceLiftExdokan"};
    
    // Ruined
    static constexpr Transition bossRaidWorldHomeStageAndDotTowerExStageTransition = {"BossRaidWorldHomeStage", "DotTowerExStage", "BossRaidWorldEx01_Eixt"};
    static constexpr Transition bossRaidWorldHomeStageAndBullRunExStageEntranceTransition = {"BossRaidWorldHomeStage", "BullRunExStage", "BossRaidWorldMoonEx02_Enter"};
    static constexpr Transition bossRaidWorldHomeStageAndBullRunExStageExitTransition = {"BossRaidWorldHomeStage", "BullRunExStage", "BossRaidWorldMoonEx02_Exit"};
    
    // Bowsers
    static constexpr Transition skyWorldHomeStageAndSkyWorldShopStageTransition = {"SkyWorldHomeStage", "SkyWorldShopStage", "shop"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldCostumeStageTransition = {"SkyWorldHomeStage", "SkyWorldCostumeStage", "byoubu"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldCloudBonusExStageTransition = {"SkyWorldHomeStage", "SkyWorldCloudBonusExStage", "sora001"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldTreasureStageTransition = {"SkyWorldHomeStage", "SkyWorldTreasureStage", "shopdress"};
    static constexpr Transition skyWorldHomeStageAndJizoSwitchExStageTransition = {"SkyWorldHomeStage", "JizoSwitchExStage", "jizo01"};
    static constexpr Transition skyWorldHomeStageAndTsukkunRotateExStageEntranceTransition = {"SkyWorldHomeStage", "TsukkunRotateExStage", "tukkun000_enter"};
    static constexpr Transition skyWorldHomeStageAndTsukkunRotateExStageExitTransition = {"SkyWorldHomeStage", "TsukkunRotateExStage", "tukkun000_exit"};
    static constexpr Transition skyWorldHomeStageAndKaronWingTowerStageTransition = {"SkyWorldHomeStage", "KaronWingTowerStage", "Patakaron02"};
    static constexpr Transition skyWorldHomeStageAndTsukkunClimbExStageEntranceTransition = {"SkyWorldHomeStage", "TsukkunClimbExStage", "tukkun001_enter"};
    static constexpr Transition skyWorldHomeStageAndTsukkunClimbExStageExitTransition = {"SkyWorldHomeStage", "TsukkunClimbExStage", "tukkun001_exit"};
    
    // Mushroom
    static constexpr Transition peachWorldHomeStageAndPeachWorldShopStageTransition = {"PeachWorldHomeStage", "PeachWorldShopStage", "PeachWorldShopA"};
    static constexpr Transition peachWorldHomeStageAndPeachWorldCostumeStageTransition = {"PeachWorldHomeStage", "PeachWorldCostumeStage", "CostumeEventWorldPeach"};
    static constexpr Transition peachWorldHomeStageAndFukuwaraiMarioStageTransition = {"PeachWorldHomeStage", "FukuwaraiMarioStage", "Fukuwarai2"};
    static constexpr Transition peachWorldHomeStageAndDotHardExStageTransition = {"PeachWorldHomeStage", "DotHardExStage", "PeachWorldEx2a"};
    static constexpr Transition peachWorldHomeStageAndYoshiCloudExStageTransition = {"PeachWorldHomeStage", "YoshiCloudExStage", "PeachWorldEx1a"};

private:
    sead::ExpHeap *mHeap = nullptr;

    int mSeed;
    static void randomize();

    int mDebugAmount;
    int mDebugCounter;
    
    sead::FixedSafeString<0x80> mDebugString;
    int mDebugStringCounter;
};

// Cap
// 	(Multi-Way) CapWorldHomeStage
// 		CapWorldTowerStage
// 			Bottom = Ex
// 	    	Top = Goal
// 		FrogSearchExStage = FrogSearchExStageEnt
// 		PoisonWaveExStage = PoisonWaveExExit
// 		PushBlockExStage = PushBlockExStageEntDokan
// 		RollingExStage = rollinggoal
// 	(Multi-Way) CapWorldTowerStage
// 		Bottom = Ex
// 		Top = Goal
// 	(One-Way) FrogSearchExStage = FrogSearchExStageEnt
// 	(Multi-Way) PoisonWaveExStage = PoisonWaveExEnt
//     (Multi-Way) PushBlockExStage = PushBlockExStageEnt
//     (Multi-Way) RollingExStage = rollingstart

// Cascade
// 	(Multi-Way) WaterfallWorldHomeStage
// 		TrexPoppunExStage = RexPoppunEx
// 		Lift2DExStage = Lift2DExit
// 		WanwanClashExStage = WanwanExGoal
// 		CapAppearExStage = CapAppearExExit
// 		WindBlowExStage = WindBlowExGoal
// 	(One-Way) TrexPoppunExStage = RexPoppunEx
//     (Multi-Way) Lift2DExStage = Lift2D
//     (Multi-Way) WanwanClashExStage = WanwanExStart
//     (Multi-Way) CapAppearExStage = CapAppearExEnt
//     (Multi-Way) WindBlowExStage = WindBlowExStart

// Sand
// 	(Multi-Way) SandWorldHomeStage
// 		SandWorldShopStage
//             Front = bar1
//             Back = bar2
// 		SandWorldSlotStage = town
// 		SandWorldVibrationStage = shindo
// 		SandWorldSecretStage = hide
// 		SandWorldMeganeExStage = anki2
// 		SandWorldKillerExStage = doukutu2
// 		SandWorldPressExStage = arijigoku2
// 		SandWorldSphinxExStage = run00return
// 		SandWorldCostumeStage = abc
// 		SandWorldPyramid000Stage = pyramid02
// 		SandWorldPyramid001Stage = pyramid04
// 		SandWorldUnderground000Stage = Under01
// 		SandWorldUnderground001Stage = Out
// 		SandWorldRotateExStage = birureturn
// 		MeganeLiftExStage = meganelift02
// 		RocketFlowerExStage = rocket
// 		WaterTubeExStage = EX_2DHosui_Exit
//     (One-Way) SandWorldShopStage
//         Front = bar1
//         Back = bar2
//     (One-Way) SandWorldSlotStage = town
//     (One-Way) SandWorldVibrationStage = shindo
//     (One-Way) SandWorldSecretStage = hide
//     (Multi-Way) SandWorldMeganeExStage = wall
//     (Multi-Way) SandWorldKillerExStage = doukutu1
//     (Multi-Way) SandWorldPressExStage = arijigoku1
//     (Multi-Way) SandWorldSphinxExStage = run00
//     (One-Way) SandWorldCostumeStage = abc
//     (Multi-Way) SandWorldPyramid000Stage = pyramid01
//     (Multi-Way) SandWorldPyramid001Stage = pyramid03
//     (Multi-Way) SandWorldUnderground000Stage = icestart
//     (Multi-Way) SandWorldUnderground001Stage = Yadokari00
//     (Multi-Way) SandWorldRotateExStage = biru
//     (Multi-Way) MeganeLiftExStage = meganelift01
//     (One-Way) RocketFlowerExStage = rocket
//     (Multi-Way) WaterTubeExStage = EX_2DHosui

// Lake
// 	(Multi-Way) LakeWorldHomeStage
// 		LakeWorldShopStage = LakeWorldShop
// 		FastenerExStage = FastenerEx
// 		TrampolineWallCatchExStage = CapTrampolineB
// 		GotogotonExStage = Goton
// 		FrogPoisonExStage = LakeWorldMoonEX1b
//     (One-Way) LakeWorldShopStage = LakeWorldShop
//     (One-Way) FastenerExStage = FastenerEx
//     (Multi-Way) TrampolineWallCatchExStage = CapTrampolineA
//     (One-Way) GotogotonExStage = Goton
//     (Multi-Way) FrogPoisonExStage = LakeWorldMoonEX1a

// Wooded
// 	(Multi-Way) ForestWorldHomeStage
// 		ForestWorldWaterExStage = EX_Water_Exit
// 		ForestWorldTowerStage
// 			Bottom = Tower001
// 			Top = Tower002
// 		ForestWorldBossStage = boss002
// 		ForestWorldBonusStage = bonus2
// 		ForestWorldCloudBonusExStage = EXCloud
// 		FogMountainExStage = EX_Mist
// 		RailCollisionExStage = EX_RailCollision_Exit
// 		ShootingElevatorExStage = EX_Tankuro_Exit
// 		ForestWorldWoodsStage
// 			Near Odyssey = Jyukai001v
// 			Near Firebro = Jyukai002
// 			Near Talkatoo = Jyukai003v
// 		ForestWorldWoodsTreasureStage = TreasureTree
// 		ForestWorldWoodsCostumeStage = Explorer_Bonus
// 		PackunPoisonExStage = PoisonEx_Exit
// 		AnimalChaseExStage = EX_AnimalChase
// 		KillerRoadExStage = KillerRoad
//     (Multi-Way) ForestWorldWaterExStage = EX_Water
//     (Multi-Way) ForestWorldTowerStage
//         Bottom = Tower001
//         Top = Tower002
//     (Multi-Way) ForestWorldBossStage = boss001
//     (Multi-Way) ForestWorldBonusStage = bonus1
//     (One-Way) ForestWorldCloudBonusExStage = EXCloud
//     (One-Way) FogMountainExStage = EX_Mist
//     (Multi-Way) RailCollisionExStage = EX_RailCollision
//     (Multi-Way) ShootingElevatorExStage = EX_Tankuro
//     (Multi-Way) ForestWorldWoodsStage
//         Near Odyssey = Jyukai001 (also Jyukai002v)
//         Near Talkatoo = Jyukai003
//     (One-Way) ForestWorldWoodsTreasureStage = TreasureTree
//     (One-Way) ForestWorldWoodsCostumeStage = Explorer_Bonus
//     (Multi-Way) PackunPoisonExStage = PoisonEx
//     (One-Way) AnimalChaseExStage = EX_AnimalChase
//     (One-Way) KillerRoadExStage = KillerRoad

// Cloud
// 	(Multi-Way) CloudWorldHomeStage
// 		FukuwaraiKuriboStage = Fukuwarai
// 		Cube2DExStage = cube
//     (One-Way) FukuwaraiKuriboStage = Fukuwarai
//     (One-Way) Cube2DExStage = cube

// Lost
// 	(Multi-Way) ClashWorldHomeStage
// 		ClashWorldShopStage = Kinopio
// 		ImomuPoisonExStage = imomu_02
// 		JangoExStage = ClashWorldMoonEX2
//     (One-Way) ClashWorldShopStage = Kinopio
//     (Multi-Way) ImomuPoisonExStage = imomu_01
//     (One-Way) JangoExStage = ClashWorldMoonEX2

// Metro
// 	(Multi-Way) CityWorldHomeStage
// 		CityWorldMainTowerStage
// 			Bottom = main_enter
// 			Top = main_exit
// 		CityWorldFactoryStage = under001enter
// 		CityWorldShop01Stage
// 			Yellow = shop_coin
// 			Purple = shop_correct
// 		CityWorldSandSlotStage = Bonus
// 		CityPeopleRoadStage
// 			Pre-Peace = gunsyu
// 			Post-Peace = gunsyudokan
// 		PoleGrabCeilExStage = tenjo
// 		TrexBikeExStage = bike02return
// 		PoleKillerExStage = boureturn
// 		Note2D3DRoomExStage = onpu
// 		ShootingCityExStage = taxireturn
// 		CapRotatePackunExStage = kaitendokan
// 		RadioControlExStage = car
// 		ElectricWireExStage = densendokan
// 		Theater2DExStage = theater
// 		DonsukeExStage = donsuke
// 		SwingSteelExStage = gragrareturn
// 		BikeSteelExStage = bikereturn
//     (Multi-Way) CityWorldMainTowerStage
//         Bottom = main_enter
//         Top = main_exit
//     (One-Way) CityWorldFactoryStage = under001enter
//     (Multi-Way) CityWorldShop01Stage
//         Yellow = shop_coin
//         Purple = shop_correct
//     (One-Way) CityWorldSandSlotStage = Bonus
//     (One/Multi-Way) CityPeopleRoadStage
//         Entrance = gunsyu
//         Exit over to rocket = gunsyudokan
//     (One-Way) PoleGrabCeilExStage = tenjo
//     (Multi-Way) TrexBikeExStage = bike02
//     (Multi-Way) PoleKillerExStage = bou
//     (One-Way) Note2D3DRoomExStage = onpu
//     (Multi-Way) ShootingCityExStage = taxi
//     (One-Way) CapRotatePackunExStage = kaitendokan
//     (One-Way) RadioControlExStage = car
//     (Multi-Way) ElectricWireExStage = densen
//     (One-Way) Theater2DExStage = theater
//     (One-Way) DonsukeExStage = donsuke
//     (Multi-Way) SwingSteelExStage = gragra
//     (Multi-Way) BikeSteelExStage = bike

// Snow
// 	(Multi-Way) SnowWorldHomeStage
// 		SnowWorldTownStage = SnowUGExit
// 		SnowWorldShopStage = ShopDoor
// 		SnowWorldCostumeStage = SnowCostumeEx
// 		SnowWorldCloudBonusExStage = EX_SkyBonus
// 		IceWalkerExStage = FigureWalker
// 		IceWaterBlockExStage = EX_IceWater_Exit
// 		ByugoPuzzleExStage = ByugoPuzzle
// 		IceWaterDashExStage = EX_IceWaterDash_Exit
// 		KillerRailCollisionExStage = EX_RailCol2_Exit
//     (Multi-Way) SnowWorldTownStage = SnowUGEnt
//     (One-Way) SnowWorldShopStage = ShopDoor
//     (One-Way) SnowWorldCostumeStage = SnowCostumeEx
//     (One-Way) SnowWorldCloudBonusExStage = EX_SkyBonus
//     (One-Way) IceWalkerExStage = FigureWalker
//     (Multi-Way) IceWaterBlockExStage = EX_IceWater
//     (One-Way) ByugoPuzzleExStage = ByugoPuzzle
//     (Multi-Way) IceWaterDashExStage = EX_IceWaterDash
//     (Multi-Way) KillerRailCollisionExStage = EX_RailCol2

// Seaside
// 	(Multi-Way) SeaWorldHomeStage
// 		SeaWorldUtsuboCaveStage = PukupukuCaveGoal
// 		SeaWorldVibrationStage = shindo_Lv2
// 		SeaWorldSecretStage = TreasureEventWorldSea
// 		SeaWorldCostumeStage = CostumeEventSeaWorld
// 		SeaWorldSneakingManStage = RoomEventWorldSea
// 		SenobiTowerExStage = SeaWorldEX3b
// 		CloudExStage = SeaWorldEX2Return
// 		WaterValleyExStage = SeaWorldEX1b
// 		ReflectBombExStage = SeaWorldMoonEX1a
// 		TogezoRotateExStage = SeaWorldMoonEX2
//     (Multi-Way) SeaWorldUtsuboCaveStage = PukupukuCaveStart
//     (One-Way) SeaWorldVibrationStage = shindo_Lv2
//     (One-Way) SeaWorldSecretStage = TreasureEventWorldSea
//     (One-Way) SeaWorldCostumeStage = CostumeEventSeaWorld
//     (One-Way) SeaWorldSneakingManStage = RoomEventWorldSea
//     (Multi-Way) SenobiTowerExStage = SeaWorldEX3a
//     (Multi-Way) CloudExStage = SeaWorldEX2
//     (Multi-Way) WaterValleyExStage = SeaWorldEX1a
//     (One-Way) ReflectBombExStage = SeaWorldMoonEX1a
//     (One-Way) TogezoRotateExStage = SeaWorldMoonEX2

// Luncheon
// 	(Multi-Way) LavaWorldHomeStage
// 		LavaWorldUpDownExStage = KeyMoveExDokan
// 		LavaBonus1Zone = town
// 		LavaWorldShopStage = shop
// 		LavaWorldCostumeStage = CostumeOut
// 		ForkExStage = ForkEX
// 		LavaWorldExcavationExStage = MartinCubeEx
// 		LavaWorldClockExStage = BBQExDokan
// 		LavaWorldBubbleLaneExStage = PechoBubbleExDokan
// 		LavaWorldTreasureStage = TreasureEventWorldLava
// 		GabuzouClockExStage = GabuzouClockExdokan
// 		CapAppearLavaLiftExStage = LavaLiftExdokan
// 		LavaWorldFenceLiftExStage = FenceLiftExdokan (warping here manually does not work)
//     (Multi-Way) LavaWorldUpDownExStage = KeyMoveEx
//     (One-Way) LavaBonus1Zone = town
//     (One-Way) LavaWorldShopStage = shop
//     (Multi-Way) LavaWorldCostumeStage = CostumeEventWorldLava
//     (One-Way) ForkExStage = ForkEX
//     (One-Way) LavaWorldExcavationExStage = MartinCubeEx
//     (Multi-Way) LavaWorldClockExStage = BBQEx
//     (Multi-Way) LavaWorldBubbleLaneExStage = PechoBubbleEx
//     (One-Way) LavaWorldTreasureStage = TreasureEventWorldLava
//     (Multi-Way) GabuzouClockExStage = GabuzouClockEx
//     (Multi-Way) CapAppearLavaLiftExStage = LavaLiftEx
//     (Multi-Way) LavaWorldFenceLiftExStage = FenceLiftEx

// Ruined
// 	(Multi-Way) BossRaidWorldHomeStage
// 		DotTowerExStage = BossRaidWorldEx01_Eixt
// 		BullRunExStage = BossRaidWorldMoonEx02_Exit
//     (One-Way) DotTowerExStage = BossRaidWorldEx01_Eixt
//     (Multi-Way) BullRunExStage = BossRaidWorldMoonEx02_Enter

// Bowsers
// 	(Multi-Way) SkyWorldHomeStage
// 		SkyWorldShopStage = shop
// 		SkyWorldCostumeStage = byoubu
// 		SkyWorldCloudBonusExStage = sora001
// 		SkyWorldTreasureStage = shopdress
// 		JizoSwitchExStage = jizo01
// 		TsukkunRotateExStage = tukkun000_exit (cannot spawn here, trapped unless ogre opens door)
// 		KaronWingTowerStage = Patakaron02
// 		TsukkunClimbExStage = tukkun001_exit
//     (One-Way) SkyWorldShopStage = shop
//     (One-Way) SkyWorldCostumeStage = byoubu
//     (One-Way) SkyWorldCloudBonusExStage = sora001
//     (One-Way) SkyWorldTreasureStage = shopdress
//     (One-Way) JizoSwitchExStage = jizo01
//     (Multi-Way) TsukkunRotateExStage = tukkun000_enter
//     (One-Way) KaronWingTowerStage = Patakaron02
//     (Multi-Way) TsukkunClimbExStage = tukkun001_enter

// Mushroom
// 	(Multi-Way) PeachWorldHomeStage
// 		PeachWorldShopStage = PeachWorldShopA
// 		PeachWorldCostumeStage = CostumeEventWorldPeach
// 		FukuwaraiMarioStage = Fukuwarai2
// 		DotHardExStage = PeachWorldEx2a
// 		YoshiCloudExStage = PeachWorldEx1a
//     (One-Way) PeachWorldShopStage = PeachWorldShopA
//     (One-Way) PeachWorldCostumeStage = CostumeEventWorldPeach
//     (One-Way) FukuwaraiMarioStage = Fukuwarai2
//     (One-Way) DotHardExStage = PeachWorldEx2a
//     (One-Way) YoshiCloudExStage = PeachWorldEx1a