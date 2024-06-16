#pragma once

#include "sead/heap/seadDisposer.h"
#include "heap/seadExpHeap.h"
#include "sead/container/seadTreeMap.h"
#include "sead/container/seadTreeNode.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include "game/GameData/GameDataHolderWriter.h"

struct Transition {
    const char* overWorld;
    const char* subArea;
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

    // Cap
    static constexpr Transition capWorldHomeStageAndCapWorldTowerStageBottom = {"CapWorldHomeStage", "CapWorldTowerStage", "Ex"};
    static constexpr Transition capWorldHomeStageAndCapWorldTowerStageTop = {"CapWorldHomeStage", "CapWorldTowerStage", "Goal"};
    static constexpr Transition capWorldHomeStageAndFrogSearchExStage = {"CapWorldHomeStage", "FrogSearchExStage", "FrogSearchExStageEnt"};
    static constexpr Transition capWorldHomeStageAndPoisonWaveExStageEntrance = {"CapWorldHomeStage", "PoisonWaveExStage", "PoisonWaveExEnt"};
    static constexpr Transition capWorldHomeStageAndPoisonWaveExStageExit = {"CapWorldHomeStage", "PoisonWaveExStage", "PoisonWaveExExit"};
    static constexpr Transition capWorldHomeStageAndPushBlockExStageEntrance = {"CapWorldHomeStage", "PushBlockExStage", "PushBlockExStageEnt"};
    static constexpr Transition capWorldHomeStageAndPushBlockExStageExit = {"CapWorldHomeStage", "PushBlockExStage", "PushBlockExStageEntDokan"};
    static constexpr Transition capWorldHomeStageAndRollingExStageEntrance = {"CapWorldHomeStage", "RollingExStage", "rollingstart"};
    static constexpr Transition capWorldHomeStageAndRollingExStageExit = {"CapWorldHomeStage", "RollingExStage", "rollinggoal"};

    // Cascade
    static constexpr Transition waterfallWorldHomeStageAndTrexPoppunExStage = {"WaterfallWorldHomeStage", "TrexPoppunExStage", "RexPoppunEx"};
    static constexpr Transition waterfallWorldHomeStageAndLift2DExStageEntrance = {"WaterfallWorldHomeStage", "Lift2DExStage", "Lift2D"};
    static constexpr Transition waterfallWorldHomeStageAndLift2DExStageExit = {"WaterfallWorldHomeStage", "Lift2DExStage", "Lift2DExit"};
    static constexpr Transition waterfallWorldHomeStageAndWanwanClashExStageEntrance = {"WaterfallWorldHomeStage", "WanwanClashExStage", "WanwanExStart"};
    static constexpr Transition waterfallWorldHomeStageAndWanwanClashExStageExit = {"WaterfallWorldHomeStage", "WanwanClashExStage", "WanwanExGoal"};
    static constexpr Transition waterfallWorldHomeStageAndCapAppearExStageEntrance = {"WaterfallWorldHomeStage", "CapAppearExStage", "CapAppearExEnt"};
    static constexpr Transition waterfallWorldHomeStageAndCapAppearExStageExit = {"WaterfallWorldHomeStage", "CapAppearExStage", "CapAppearExExit"};
    static constexpr Transition waterfallWorldHomeStageAndWindBlowExStageEntrance = {"WaterfallWorldHomeStage", "WindBlowExStage", "WindBlowExStart"};
    static constexpr Transition waterfallWorldHomeStageAndWindBlowExStageExit = {"WaterfallWorldHomeStage", "WindBlowExStage", "WindBlowExGoal"};
    
    // Sand
    static constexpr Transition sandWorldHomeStageAndSandWorldShopStageFront = {"SandWorldHomeStage", "SandWorldShopStage", "bar1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldShopStageBack = {"SandWorldHomeStage", "SandWorldShopStage", "bar2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSlotStage = {"SandWorldHomeStage", "SandWorldSlotStage", "town"};
    static constexpr Transition sandWorldHomeStageAndSandWorldVibrationStage = {"SandWorldHomeStage", "SandWorldVibrationStage", "shindo"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSecretStage = {"SandWorldHomeStage", "SandWorldSecretStage", "hide"};
    static constexpr Transition sandWorldHomeStageAndSandWorldMeganeExStageEntrance = {"SandWorldHomeStage", "SandWorldMeganeExStage", "anki2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldMeganeExStageExit = {"SandWorldHomeStage", "SandWorldMeganeExStage", "wall"};
    static constexpr Transition sandWorldHomeStageAndSandWorldKillerExStageEntrance = {"SandWorldHomeStage", "SandWorldKillerExStage", "doukutu1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldKillerExStageExit = {"SandWorldHomeStage", "SandWorldKillerExStage", "doukutu2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPressExStageEntrance = {"SandWorldHomeStage", "SandWorldPressExStage", "arijigoku1"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPressExStageExit = {"SandWorldHomeStage", "SandWorldPressExStage", "arijigoku2"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSphinxExStageEntrance = {"SandWorldHomeStage", "SandWorldSphinxExStage", "run00"};
    static constexpr Transition sandWorldHomeStageAndSandWorldSphinxExStageExit = {"SandWorldHomeStage", "SandWorldSphinxExStage", "run00return"};
    static constexpr Transition sandWorldHomeStageAndSandWorldCostumeStage = {"SandWorldHomeStage", "SandWorldCostumeStage", "abc"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid000StageEntrance = {"SandWorldHomeStage", "SandWorldPyramid000Stage", "pyramid01"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid000StageExit = {"SandWorldHomeStage", "SandWorldPyramid000Stage", "pyramid02"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid001StageEntrance = {"SandWorldHomeStage", "SandWorldPyramid001Stage", "pyramid03"};
    static constexpr Transition sandWorldHomeStageAndSandWorldPyramid001StageExit = {"SandWorldHomeStage", "SandWorldPyramid001Stage", "pyramid04"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground000StageEntrance = {"SandWorldHomeStage", "SandWorldUnderground000Stage", "icestart"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground000StageExit = {"SandWorldHomeStage", "SandWorldUnderground000Stage", "Under01"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground001StageEntrance = {"SandWorldHomeStage", "SandWorldUnderground001Stage", "Yadokari00"};
    static constexpr Transition sandWorldHomeStageAndSandWorldUnderground001StageExit = {"SandWorldHomeStage", "SandWorldUnderground001Stage", "Out"};
    static constexpr Transition sandWorldHomeStageAndSandWorldRotateExStageEntrance = {"SandWorldHomeStage", "SandWorldRotateExStage", "biru"};
    static constexpr Transition sandWorldHomeStageAndSandWorldRotateExStageExit = {"SandWorldHomeStage", "SandWorldRotateExStage", "birureturn"};
    static constexpr Transition sandWorldHomeStageAndMeganeLiftExStageEntrance = {"SandWorldHomeStage", "MeganeLiftExStage", "meganelift01"};
    static constexpr Transition sandWorldHomeStageAndMeganeLiftExStageExit = {"SandWorldHomeStage", "MeganeLiftExStage", "meganelift02"};
    static constexpr Transition sandWorldHomeStageAndRocketFlowerExStage = {"SandWorldHomeStage", "RocketFlowerExStage", "rocket"};
    static constexpr Transition sandWorldHomeStageAndWaterTubeExStageEntrance = {"SandWorldHomeStage", "WaterTubeExStage", "EX_2DHosui"};
    static constexpr Transition sandWorldHomeStageAndWaterTubeExStageExit = {"SandWorldHomeStage", "WaterTubeExStage", "EX_2DHosui_Exit"};
    
    // Lake
    static constexpr Transition lakeWorldHomeStageAndLakeWorldShopStage = {"LakeWorldHomeStage", "LakeWorldHomeStage", "LakeWorldShop"};
    static constexpr Transition lakeWorldHomeStageAndFastenerExStage = {"LakeWorldHomeStage", "FastenerExStage", "FastenerEx"};
    static constexpr Transition lakeWorldHomeStageAndTrampolineWallCatchExStageEntrance = {"LakeWorldHomeStage", "TrampolineWallCatchExStage", "CapTrampolineA"};
    static constexpr Transition lakeWorldHomeStageAndTrampolineWallCatchExStageExit = {"LakeWorldHomeStage", "TrampolineWallCatchExStage", "CapTrampolineB"};
    static constexpr Transition lakeWorldHomeStageAndGotogotonExStage = {"LakeWorldHomeStage", "GotogotonExStage", "Goton"};
    static constexpr Transition lakeWorldHomeStageAndFrogPoisonExStageEntrance = {"LakeWorldHomeStage", "FrogPoisonExStage", "LakeWorldMoonEX1a"};
    static constexpr Transition lakeWorldHomeStageAndFrogPoisonExStageExit = {"LakeWorldHomeStage", "FrogPoisonExStage", "LakeWorldMoonEX1b"};
    
    // Wooded
    static constexpr Transition forestWorldHomeStageAndForestWorldWaterExStageEntrance = {"ForestWorldHomeStage", "ForestWorldWaterExStage", "EX_Water"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWaterExStageExit = {"ForestWorldHomeStage", "ForestWorldWaterExStage", "EX_Water_Exit"};
    static constexpr Transition forestWorldHomeStageAndForestWorldTowerStageBottom = {"ForestWorldHomeStage", "ForestWorldTowerStage", "Tower001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldTowerStageTop = {"ForestWorldHomeStage", "ForestWorldTowerStage", "Tower002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBossStageEntrance = {"ForestWorldHomeStage", "ForestWorldBossStage", "boss001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBossStageExit = {"ForestWorldHomeStage", "ForestWorldBossStage", "boss002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBonusStageEntrance = {"ForestWorldHomeStage", "ForestWorldBonusStage", "bonus1"};
    static constexpr Transition forestWorldHomeStageAndForestWorldBonusStageExit = {"ForestWorldHomeStage", "ForestWorldBonusStage", "bonus2"};
    static constexpr Transition forestWorldHomeStageAndForestWorldCloudBonusExStage = {"ForestWorldHomeStage", "ForestWorldCloudBonusExStage", "EXCloud"};
    static constexpr Transition forestWorldHomeStageAndFogMountainExStage = {"ForestWorldHomeStage", "FogMountainExStage", "EX_Mist"};
    static constexpr Transition forestWorldHomeStageAndRailCollisionExStageEntrance = {"ForestWorldHomeStage", "RailCollisionExStage", "EX_RailCollision"};
    static constexpr Transition forestWorldHomeStageAndRailCollisionExStageExit = {"ForestWorldHomeStage", "RailCollisionExStage", "EX_RailCollision_Exit"};
    static constexpr Transition forestWorldHomeStageAndShootingElevatorExStageEntrance = {"ForestWorldHomeStage", "ShootingElevatorExStage", "EX_Tankuro"};
    static constexpr Transition forestWorldHomeStageAndShootingElevatorExStageExit = {"ForestWorldHomeStage", "ShootingElevatorExStage", "EX_Tankuro_Exit"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageNearOdysseyEntrance = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai001"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageNearOdysseyExit = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai001v"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageNearFirebro = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai002"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageNearTalkatooEntrance = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai003"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsStageNearTalkatooExit = {"ForestWorldHomeStage", "ForestWorldWoodsStage", "Jyukai003v"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsTreasureStage = {"ForestWorldHomeStage", "ForestWorldWoodsTreasureStage", "TreasureTree"};
    static constexpr Transition forestWorldHomeStageAndForestWorldWoodsCostumeStage = {"ForestWorldHomeStage", "ForestWorldWoodsCostumeStage", "Explorer_Bonus"};
    static constexpr Transition forestWorldHomeStageAndPackunPoisonExStageEntrance = {"ForestWorldHomeStage", "PackunPoisonExStage", "PoisonEx"};
    static constexpr Transition forestWorldHomeStageAndPackunPoisonExStageExit = {"ForestWorldHomeStage", "PackunPoisonExStage", "PoisonEx_Exit"};
    static constexpr Transition forestWorldHomeStageAndAnimalChaseExStage = {"ForestWorldHomeStage", "AnimalChaseExStage", "EX_AnimalChase"};
    static constexpr Transition forestWorldHomeStageAndKillerRoadExStage = {"ForestWorldHomeStage", "KillerRoadExStage", "KillerRoad"};
    
    // Cloud
    static constexpr Transition cloudWorldHomeStageAndFukuwaraiKuriboStage = {"CloudWorldHomeStage", "FukuwaraiKuriboStage", "Fukuwarai"};
    static constexpr Transition cloudWorldHomeStageAndCube2DExStage = {"CloudWorldHomeStage", "Cube2DExStage", "cube"};
    
    // Lost
    static constexpr Transition clashWorldHomeStageAndClashWorldShopStage = {"ClashWorldHomeStage", "ClashWorldShopStage", "Kinopio"};
    static constexpr Transition clashWorldHomeStageAndImomuPoisonExStageEntrance = {"ClashWorldHomeStage", "ImomuPoisonExStage", "imomu_01"};
    static constexpr Transition clashWorldHomeStageAndImomuPoisonExStageExit = {"ClashWorldHomeStage", "ImomuPoisonExStage", "imomu_02"};
    static constexpr Transition clashWorldHomeStageAndJangoExStage = {"ClashWorldHomeStage", "JangoExStage", "ClashWorldMoonEX2"};
    
    // Metro
    static constexpr Transition cityWorldHomeStageAndCityWorldMainTowerStageBottom = {"CityWorldHomeStage", "CityWorldMainTowerStage", "main_enter"};
    static constexpr Transition cityWorldHomeStageAndCityWorldMainTowerStageTop = {"CityWorldHomeStage", "CityWorldMainTowerStage", "main_exit"};
    static constexpr Transition cityWorldHomeStageAndCityWorldFactoryStage = {"CityWorldHomeStage", "CityWorldFactoryStage", "under001enter"};
    static constexpr Transition cityWorldHomeStageAndCityWorldShop01StageYellow = {"CityWorldHomeStage", "CityWorldShop01Stage", "shop_coin"};
    static constexpr Transition cityWorldHomeStageAndCityWorldShop01StagePurple = {"CityWorldHomeStage", "CityWorldShop01Stage", "shop_correct"};
    static constexpr Transition cityWorldHomeStageAndCityWorldSandSlotStage = {"CityWorldHomeStage", "CityWorldSandSlotStage", "Bonus"};
    static constexpr Transition cityWorldHomeStageAndCityPeopleRoadStageEntrance = {"CityWorldHomeStage", "CityPeopleRoadStage", "gunsyu"};
    static constexpr Transition cityWorldHomeStageAndCityPeopleRoadStageExit = {"CityWorldHomeStage", "CityPeopleRoadStage", "gunsyudokan"};
    static constexpr Transition cityWorldHomeStageAndPoleGrabCeilExStage = {"CityWorldHomeStage", "PoleGrabCeilExStage", "tenjo"};
    static constexpr Transition cityWorldHomeStageAndTrexBikeExStageEntrance = {"CityWorldHomeStage", "TrexBikeExStage", "bike02"};
    static constexpr Transition cityWorldHomeStageAndTrexBikeExStageExit = {"CityWorldHomeStage", "TrexBikeExStage", "bike02return"};
    static constexpr Transition cityWorldHomeStageAndPoleKillerExStageEntrance = {"CityWorldHomeStage", "PoleKillerExStage", "bou"};
    static constexpr Transition cityWorldHomeStageAndPoleKillerExStageExit = {"CityWorldHomeStage", "PoleKillerExStage", "boureturn"};
    static constexpr Transition cityWorldHomeStageAndNote2D3DRoomExStage = {"CityWorldHomeStage", "Note2D3DRoomExStage", "onpu"};
    static constexpr Transition cityWorldHomeStageAndShootingCityExStageEntrance = {"CityWorldHomeStage", "ShootingCityExStage", "taxi"};
    static constexpr Transition cityWorldHomeStageAndShootingCityExStageExit = {"CityWorldHomeStage", "ShootingCityExStage", "taxireturn"};
    static constexpr Transition cityWorldHomeStageAndCapRotatePackunExStage = {"CityWorldHomeStage", "CapRotatePackunExStage", "kaitendokan"};
    static constexpr Transition cityWorldHomeStageAndRadioControlExStage = {"CityWorldHomeStage", "RadioControlExStage", "car"};
    static constexpr Transition cityWorldHomeStageAndElectricWireExStageEntrance = {"CityWorldHomeStage", "ElectricWireExStage", "densen"};
    static constexpr Transition cityWorldHomeStageAndElectricWireExStageExit = {"CityWorldHomeStage", "ElectricWireExStage", "densendokan"};
    static constexpr Transition cityWorldHomeStageAndTheater2DExStage = {"CityWorldHomeStage", "Theater2DExStage", "theater"};
    static constexpr Transition cityWorldHomeStageAndDonsukeExStage = {"CityWorldHomeStage", "DonsukeExStage", "donsuke"};
    static constexpr Transition cityWorldHomeStageAndSwingSteelExStageEntrance = {"CityWorldHomeStage", "SwingSteelExStage", "gragra"};
    static constexpr Transition cityWorldHomeStageAndSwingSteelExStageExit = {"CityWorldHomeStage", "SwingSteelExStage", "gragrareturn"};
    static constexpr Transition cityWorldHomeStageAndBikeSteelExStageEntrance = {"CityWorldHomeStage", "BikeSteelExStage", "bike"};
    static constexpr Transition cityWorldHomeStageAndBikeSteelExStageExit = {"CityWorldHomeStage", "BikeSteelExStage", "bikereturn"};
    
    // Snow
    static constexpr Transition snowWorldHomeStageAndSnowWorldTownStageEntrance = {"SnowWorldHomeStage", "SnowWorldTownStage", "SnowUGEnt"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldTownStageExit = {"SnowWorldHomeStage", "SnowWorldTownStage", "SnowUGExit"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldShopStage = {"SnowWorldHomeStage", "SnowWorldShopStage", "ShopDoor"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldCostumeStage = {"SnowWorldHomeStage", "SnowWorldCostumeStage", "SnowCostumeEx"};
    static constexpr Transition snowWorldHomeStageAndSnowWorldCloudBonusExStage = {"SnowWorldHomeStage", "SnowWorldCloudBonusExStage", "EX_SkyBonus"};
    static constexpr Transition snowWorldHomeStageAndIceWalkerExStage = {"SnowWorldHomeStage", "IceWalkerExStage", "FigureWalker"};
    static constexpr Transition snowWorldHomeStageAndIceWaterBlockExStageEntrance = {"SnowWorldHomeStage", "IceWaterBlockExStage", "EX_IceWater"};
    static constexpr Transition snowWorldHomeStageAndIceWaterBlockExStageExit = {"SnowWorldHomeStage", "IceWaterBlockExStage", "EX_IceWater_Exit"};
    static constexpr Transition snowWorldHomeStageAndByugoPuzzleExStage = {"SnowWorldHomeStage", "ByugoPuzzleExStage", "ByugoPuzzle"};
    static constexpr Transition snowWorldHomeStageAndIceWaterDashExStageEntrance = {"SnowWorldHomeStage", "IceWaterDashExStage", "EX_IceWaterDash"};
    static constexpr Transition snowWorldHomeStageAndIceWaterDashExStageExit = {"SnowWorldHomeStage", "IceWaterDashExStage", "EX_IceWaterDash_Exit"};
    static constexpr Transition snowWorldHomeStageAndKillerRailCollisionExStageEntrance = {"SnowWorldHomeStage", "KillerRailCollisionExStage", "EX_RailCol2"};
    static constexpr Transition snowWorldHomeStageAndKillerRailCollisionExStageExit = {"SnowWorldHomeStage", "KillerRailCollisionExStage", "EX_RailCol2_Exit"};
    
    // Seaside
    static constexpr Transition seaWorldHomeStageAndSeaWorldUtsuboCaveStageEntrance = {"SeaWorldHomeStage", "SeaWorldUtsuboCaveStage", "PukupukuCaveStart"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldUtsuboCaveStageExit = {"SeaWorldHomeStage", "SeaWorldUtsuboCaveStage", "PukupukuCaveGoal"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldVibrationStage = {"SeaWorldHomeStage", "SeaWorldVibrationStage", "shindo_Lv2"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldSecretStage = {"SeaWorldHomeStage", "SeaWorldSecretStage", "TreasureEventWorldSea"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldCostumeStage = {"SeaWorldHomeStage", "SeaWorldCostumeStage", "CostumeEventSeaWorld"};
    static constexpr Transition seaWorldHomeStageAndSeaWorldSneakingManStage = {"SeaWorldHomeStage", "SeaWorldSneakingManStage", "RoomEventWorldSea"};
    static constexpr Transition seaWorldHomeStageAndSenobiTowerExStageEntrance = {"SeaWorldHomeStage", "SenobiTowerExStage", "SeaWorldEX3a"};
    static constexpr Transition seaWorldHomeStageAndSenobiTowerExStageExit = {"SeaWorldHomeStage", "SenobiTowerExStage", "SeaWorldEX3b"};
    static constexpr Transition seaWorldHomeStageAndCloudExStageEntrance = {"SeaWorldHomeStage", "CloudExStage", "SeaWorldEX2"};
    static constexpr Transition seaWorldHomeStageAndCloudExStageExit = {"SeaWorldHomeStage", "CloudExStage", "SeaWorldEX2Return"};
    static constexpr Transition seaWorldHomeStageAndWaterValleyExStageEntrance = {"SeaWorldHomeStage", "WaterValleyExStage", "SeaWorldEX1a"};
    static constexpr Transition seaWorldHomeStageAndWaterValleyExStageExit = {"SeaWorldHomeStage", "WaterValleyExStage", "SeaWorldEX1b"};
    static constexpr Transition seaWorldHomeStageAndReflectBombExStage = {"SeaWorldHomeStage", "ReflectBombExStage", "SeaWorldMoonEX1a"};
    static constexpr Transition seaWorldHomeStageAndTogezoRotateExStage = {"SeaWorldHomeStage", "TogezoRotateExStage", "SeaWorldMoonEX2"};
    
    // Luncheon
    static constexpr Transition lavaWorldHomeStageAndLavaWorldUpDownExStageEntrance = {"LavaWorldHomeStage", "LavaWorldUpDownExStage", "KeyMoveEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldUpDownExStageExit = {"LavaWorldHomeStage", "LavaWorldUpDownExStage", "KeyMoveExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaBonus1Zone = {"LavaWorldHomeStage", "LavaBonus1Zone", "town"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldShopStage = {"LavaWorldHomeStage", "LavaWorldShopStage", "shop"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldCostumeStageEntrance = {"LavaWorldHomeStage", "LavaWorldCostumeStage", "CostumeEventWorldLava"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldCostumeStageExit = {"LavaWorldHomeStage", "LavaWorldCostumeStage", "CostumeOut"};
    static constexpr Transition lavaWorldHomeStageAndForkExStage = {"LavaWorldHomeStage", "ForkExStage", "ForkEX"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldExcavationExStage = {"LavaWorldHomeStage", "LavaWorldExcavationExStage", "MartinCubeEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldClockExStageEntrance = {"LavaWorldHomeStage", "LavaWorldClockExStage", "BBQEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldClockExStageExit = {"LavaWorldHomeStage", "LavaWorldClockExStage", "BBQExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldBubbleLaneExStageEntrance = {"LavaWorldHomeStage", "LavaWorldBubbleLaneExStage", "PechoBubbleEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldBubbleLaneExStageExit = {"LavaWorldHomeStage", "LavaWorldBubbleLaneExStage", "PechoBubbleExDokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldTreasureStage = {"LavaWorldHomeStage", "LavaWorldTreasureStage", "TreasureEventWorldLava"};
    static constexpr Transition lavaWorldHomeStageAndGabuzouClockExStageEntrance = {"LavaWorldHomeStage", "GabuzouClockExStage", "GabuzouClockEx"};
    static constexpr Transition lavaWorldHomeStageAndGabuzouClockExStageExit = {"LavaWorldHomeStage", "GabuzouClockExStage", "GabuzouClockExdokan"};
    static constexpr Transition lavaWorldHomeStageAndCapAppearLavaLiftExStageEntrance = {"LavaWorldHomeStage", "CapAppearLavaLiftExStage", "LavaLiftEx"};
    static constexpr Transition lavaWorldHomeStageAndCapAppearLavaLiftExStageExit = {"LavaWorldHomeStage", "CapAppearLavaLiftExStage", "LavaLiftExdokan"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldFenceLiftExStageEntrance = {"LavaWorldHomeStage", "LavaWorldFenceLiftExStage", "FenceLiftEx"};
    static constexpr Transition lavaWorldHomeStageAndLavaWorldFenceLiftExStageExit = {"LavaWorldHomeStage", "LavaWorldFenceLiftExStage", "FenceLiftExdokan"};
    
    // Ruined
    static constexpr Transition bossRaidWorldHomeStageAndDotTowerExStage = {"BossRaidWorldHomeStage", "DotTowerExStage", "BossRaidWorldEx01_Eixt"};
    static constexpr Transition bossRaidWorldHomeStageAndBullRunExStageEntrance = {"BossRaidWorldHomeStage", "BullRunExStage", "BossRaidWorldMoonEx02_Enter"};
    static constexpr Transition bossRaidWorldHomeStageAndBullRunExStageExit = {"BossRaidWorldHomeStage", "BullRunExStage", "BossRaidWorldMoonEx02_Exit"};
    
    // Bowsers
    static constexpr Transition skyWorldHomeStageAndSkyWorldShopStage = {"SkyWorldHomeStage", "SkyWorldShopStage", "shop"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldCostumeStage = {"SkyWorldHomeStage", "SkyWorldCostumeStage", "byoubu"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldCloudBonusExStage = {"SkyWorldHomeStage", "SkyWorldCloudBonusExStage", "sora001"};
    static constexpr Transition skyWorldHomeStageAndSkyWorldTreasureStage = {"SkyWorldHomeStage", "SkyWorldTreasureStage", "shopdress"};
    static constexpr Transition skyWorldHomeStageAndJizoSwitchExStage = {"SkyWorldHomeStage", "JizoSwitchExStage", "jizo01"};
    static constexpr Transition skyWorldHomeStageAndTsukkunRotateExStageEntrance = {"SkyWorldHomeStage", "TsukkunRotateExStage", "tukkun000_enter"};
    static constexpr Transition skyWorldHomeStageAndTsukkunRotateExStageExit = {"SkyWorldHomeStage", "TsukkunRotateExStage", "tukkun000_exit"};
    static constexpr Transition skyWorldHomeStageAndKaronWingTowerStage = {"SkyWorldHomeStage", "KaronWingTowerStage", "Patakaron02"};
    static constexpr Transition skyWorldHomeStageAndTsukkunClimbExStageEntrance = {"SkyWorldHomeStage", "TsukkunClimbExStage", "tukkun001_enter"};
    static constexpr Transition skyWorldHomeStageAndTsukkunClimbExStageExit = {"SkyWorldHomeStage", "TsukkunClimbExStage", "tukkun001_exit"};
    
    // Mushroom
    static constexpr Transition peachWorldHomeStageAndPeachWorldShopStage = {"PeachWorldHomeStage", "PeachWorldShopStage", "PeachWorldShopA"};
    static constexpr Transition peachWorldHomeStageAndPeachWorldCostumeStage = {"PeachWorldHomeStage", "PeachWorldCostumeStage", "CostumeEventWorldPeach"};
    static constexpr Transition peachWorldHomeStageAndFukuwaraiMarioStage = {"PeachWorldHomeStage", "FukuwaraiMarioStage", "Fukuwarai2"};
    static constexpr Transition peachWorldHomeStageAndDotHardExStage = {"PeachWorldHomeStage", "DotHardExStage", "PeachWorldEx2a"};
    static constexpr Transition peachWorldHomeStageAndYoshiCloudExStage = {"PeachWorldHomeStage", "YoshiCloudExStage", "PeachWorldEx1a"};

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