#pragma once

#include "sead/heap/seadDisposer.h"
#include "heap/seadExpHeap.h"
#include "sead/container/seadTreeMap.h"
#include "sead/container/seadTreeNode.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include "game/GameData/GameDataHolderWriter.h"

enum StageType : unsigned int {
    ONE_WAY,
    MULTI_WAY
};

struct Stage {
    const char* name;
    const char* id;
    const StageType type;
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

    static constexpr Stage capWorldHomeStageViaCapWorldTowerStageBottom = {"CapWorldHomeStage", "Ex", StageType::MULTI_WAY};
    static constexpr Stage capWorldHomeStageViaCapWorldTowerStageTop = {"CapWorldHomeStage", "Goal", StageType::MULTI_WAY};
    static constexpr Stage capWorldHomeStageViaFrogSearchExStage = {"CapWorldHomeStage", "FrogSearchExStageEnt", StageType::MULTI_WAY};
    static constexpr Stage capWorldHomeStageViaPoisonWaveExStage = {"CapWorldHomeStage", "PoisonWaveExExit", StageType::MULTI_WAY};
    static constexpr Stage capWorldHomeStageViaPushBlockExStage = {"CapWorldHomeStage", "PushBlockExStageEntDokan", StageType::MULTI_WAY};
    static constexpr Stage capWorldHomeStageViaRollingExStage = {"CapWorldHomeStage", "rollinggoal", StageType::MULTI_WAY};
    static constexpr Stage capWorldTowerStageBottom = {"CapWorldTowerStage", "Ex", StageType::MULTI_WAY};
    static constexpr Stage capWorldTowerStageTop = {"CapWorldTowerStage", "Goal", StageType::MULTI_WAY};
    static constexpr Stage frogSearchExStage = {"FrogSearchExStage", "FrogSearchExStageEnt", StageType::ONE_WAY};
    static constexpr Stage poisonWaveExStage = {"PoisonWaveExStage", "PoisonWaveExEnt", StageType::MULTI_WAY};
    static constexpr Stage pushBlockExStage = {"PushBlockExStage", "PushBlockExStageEnt", StageType::MULTI_WAY};
    static constexpr Stage rollingExStage = {"RollingExStage", "rollingstart", StageType::MULTI_WAY};

    static constexpr Stage waterfallWorldHomeStageViaTrexPoppunExStage = {"WaterfallWorldHomeStage", "RexPoppunEx", StageType::MULTI_WAY};
    static constexpr Stage waterfallWorldHomeStageViaLift2DExStage = {"WaterfallWorldHomeStage", "Lift2DExit", StageType::MULTI_WAY};
    static constexpr Stage waterfallWorldHomeStageViaWanwanClashExStage = {"WaterfallWorldHomeStage", "WanwanExGoal", StageType::MULTI_WAY};
    static constexpr Stage waterfallWorldHomeStageViaCapAppearExStage = {"WaterfallWorldHomeStage", "CapAppearExExit", StageType::MULTI_WAY};
    static constexpr Stage waterfallWorldHomeStageViaWindBlowExStage = {"WaterfallWorldHomeStage", "WindBlowExGoal", StageType::MULTI_WAY};
    static constexpr Stage trexPoppunExStage = {"TrexPoppunExStage", "RexPoppunEx", StageType::ONE_WAY};
    static constexpr Stage lift2DExStage = {"Lift2DExStage", "Lift2D", StageType::MULTI_WAY};
    static constexpr Stage wanwanClashExStage = {"WanwanClashExStage", "WanwanExStart", StageType::MULTI_WAY};
    static constexpr Stage capAppearExStage = {"CapAppearExStage", "CapAppearExEnt", StageType::MULTI_WAY};
    static constexpr Stage windBlowExStage = {"WindBlowExStage", "WindBlowExStart", StageType::MULTI_WAY};

    static constexpr Stage sandWorldHomeStageViaSandWorldShopStageFront = {"SandWorldHomeStage", "bar1", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldShopStageBack = {"SandWorldHomeStage", "bar2", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldSlotStage = {"SandWorldHomeStage", "town", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldVibrationStage = {"SandWorldHomeStage", "shindo", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldSecretStage = {"SandWorldHomeStage", "hide", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldMeganeExStage = {"SandWorldHomeStage", "anki2", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldKillerExStage = {"SandWorldHomeStage", "doukutu2", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldPressExStage = {"SandWorldHomeStage", "arijigoku2", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldSphinxExStage = {"SandWorldHomeStage", "run00return", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldCostumeStage = {"SandWorldHomeStage", "abc", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldPyramid000Stage = {"SandWorldHomeStage", "pyramid02", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldPyramid001Stage = {"SandWorldHomeStage", "pyramid04", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldUnderground000Stage = {"SandWorldHomeStage", "Under01", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldUnderground001Stage = {"SandWorldHomeStage", "Out", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaSandWorldRotateExStage = {"SandWorldHomeStage", "birureturn", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaMeganeLiftExStage = {"SandWorldHomeStage", "meganelift02", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaRocketFlowerExStage = {"SandWorldHomeStage", "rocket", StageType::MULTI_WAY};
    static constexpr Stage sandWorldHomeStageViaWaterTubeExStage = {"SandWorldHomeStage", "EX_2DHosui_Exit", StageType::MULTI_WAY};
    static constexpr Stage sandWorldShopStageFront = {"SandWorldShopStage", "bar1", StageType::ONE_WAY};
    static constexpr Stage sandWorldShopStageBack = {"SandWorldShopStage", "bar2", StageType::ONE_WAY};
    static constexpr Stage sandWorldSlotStage = {"SandWorldSlotStage", "town", StageType::ONE_WAY};
    static constexpr Stage sandWorldVibrationStage = {"SandWorldVibrationStage", "shindo", StageType::ONE_WAY};
    static constexpr Stage sandWorldSecretStage = {"SandWorldSecretStage", "hide", StageType::ONE_WAY};
    static constexpr Stage sandWorldMeganeExStage = {"SandWorldMeganeExStage", "wall", StageType::MULTI_WAY};
    static constexpr Stage sandWorldKillerExStage = {"SandWorldKillerExStage", "doukutu1", StageType::MULTI_WAY};
    static constexpr Stage sandWorldPressExStage = {"SandWorldPressExStage", "arijigoku1", StageType::MULTI_WAY};
    static constexpr Stage sandWorldSphinxExStage = {"SandWorldSphinxExStage", "run00", StageType::MULTI_WAY};
    static constexpr Stage sandWorldCostumeStage = {"SandWorldCostumeStage", "abc", StageType::ONE_WAY};
    static constexpr Stage sandWorldPyramid000Stage = {"SandWorldPyramid000Stage", "pyramid01", StageType::MULTI_WAY};
    static constexpr Stage sandWorldPyramid001Stage = {"SandWorldPyramid001Stage", "pyramid03", StageType::MULTI_WAY};
    static constexpr Stage sandWorldUnderground000Stage = {"SandWorldUnderground000Stage", "icestart", StageType::MULTI_WAY};
    static constexpr Stage sandWorldUnderground001Stage = {"SandWorldUnderground001Stage", "Yadokari00", StageType::MULTI_WAY};
    static constexpr Stage sandWorldRotateExStage = {"SandWorldRotateExStage", "biru", StageType::MULTI_WAY};
    static constexpr Stage meganeLiftExStage = {"MeganeLiftExStage", "meganelift01", StageType::MULTI_WAY};
    static constexpr Stage rocketFlowerExStage = {"RocketFlowerExStage", "rocket", StageType::ONE_WAY};
    static constexpr Stage waterTubeExStage = {"WaterTubeExStage", "EX_2DHosui", StageType::MULTI_WAY};

    static constexpr Stage lakeWorldHomeStageViaLakeWorldShopStage = {"LakeWorldHomeStage", "LakeWorldShop", StageType::MULTI_WAY};
    static constexpr Stage lakeWorldHomeStageViaFastenerExStage = {"LakeWorldHomeStage", "FastenerEx", StageType::MULTI_WAY};
    static constexpr Stage lakeWorldHomeStageViaTrampolineWallCatchExStage = {"LakeWorldHomeStage", "CapTrampolineB", StageType::MULTI_WAY};
    static constexpr Stage lakeWorldHomeStageViaGotogotonExStage = {"LakeWorldHomeStage", "Goton", StageType::MULTI_WAY};
    static constexpr Stage lakeWorldHomeStageViaFrogPoisonExStage = {"LakeWorldHomeStage", "LakeWorldMoonEX1b", StageType::MULTI_WAY};
    static constexpr Stage lakeWorldShopStage = {"LakeWorldShopStage", "LakeWorldShop", StageType::ONE_WAY};
    static constexpr Stage fastenerExStage = {"FastenerExStage", "FastenerEx", StageType::ONE_WAY};
    static constexpr Stage trampolineWallCatchExStage = {"TrampolineWallCatchExStage", "CapTrampolineA", StageType::MULTI_WAY};
    static constexpr Stage gotogotonExStage = {"GotogotonExStage", "Goton", StageType::ONE_WAY};
    static constexpr Stage frogPoisonExStage = {"FrogPoisonExStage", "LakeWorldMoonEX1a", StageType::MULTI_WAY};

    static constexpr Stage forestWorldHomeStageViaForestWorldWaterExStage = {"ForestWorldHomeStage", "EX_Water_Exit", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldTowerStageBottom = {"ForestWorldHomeStage", "Tower001", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldTowerStageTop = {"ForestWorldHomeStage", "Tower002", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldBossStage = {"ForestWorldHomeStage", "boss002", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldBonusStage = {"ForestWorldHomeStage", "bonus2", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldCloudBonusExStage = {"ForestWorldHomeStage", "EXCloud", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaFogMountainExStage = {"ForestWorldHomeStage", "EX_Mist", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaRailCollisionExStage = {"ForestWorldHomeStage", "EX_RailCollision_Exit", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaShootingElevatorExStage = {"ForestWorldHomeStage", "EX_Tankuro_Exit", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldWoodsStageNearOdyssey = {"ForestWorldHomeStage", "Jyukai001v", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldWoodsStageNearFirebro = {"ForestWorldHomeStage", "Jyukai002", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldWoodsStageNearTalkatoo = {"ForestWorldHomeStage", "Jyukai003v", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldWoodsTreasureStage = {"ForestWorldHomeStage", "TreasureTree", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaForestWorldWoodsCostumeStage = {"ForestWorldHomeStage", "Explorer_Bonus", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaPackunPoisonExStage = {"ForestWorldHomeStage", "PoisonEx_Exit", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaAnimalChaseExStage = {"ForestWorldHomeStage", "EX_AnimalChase", StageType::MULTI_WAY};
    static constexpr Stage forestWorldHomeStageViaKillerRoadExStage = {"ForestWorldHomeStage", "KillerRoad", StageType::MULTI_WAY};
    static constexpr Stage forestWorldWaterExStage = {"ForestWorldWaterExStage", "EX_Water", StageType::MULTI_WAY};
    static constexpr Stage forestWorldTowerStageBottom = {"ForestWorldTowerStage", "Tower001", StageType::MULTI_WAY};
    static constexpr Stage forestWorldTowerStageTop = {"ForestWorldTowerStage", "Tower002", StageType::MULTI_WAY};
    static constexpr Stage forestWorldBossStage = {"ForestWorldBossStage", "boss001", StageType::MULTI_WAY};
    static constexpr Stage forestWorldBonusStage = {"ForestWorldBonusStage", "bonus1", StageType::MULTI_WAY};
    static constexpr Stage forestWorldCloudBonusExStage = {"ForestWorldCloudBonusExStage", "EXCloud", StageType::ONE_WAY};
    static constexpr Stage fogMountainExStage = {"FogMountainExStage", "EX_Mist", StageType::ONE_WAY};
    static constexpr Stage railCollisionExStage = {"RailCollisionExStage", "EX_RailCollision", StageType::MULTI_WAY};
    static constexpr Stage shootingElevatorExStage = {"ShootingElevatorExStage", "EX_Tankuro", StageType::MULTI_WAY};
    static constexpr Stage forestWorldWoodsStageNearOdyssey = {"ForestWorldWoodsStage", "Jyukai001", StageType::MULTI_WAY};
    static constexpr Stage forestWorldWoodsStageNearTalkatoo = {"ForestWorldWoodsStage", "Jyukai003", StageType::MULTI_WAY};
    static constexpr Stage forestWorldWoodsTreasureStage = {"ForestWorldWoodsTreasureStage", "TreasureTree", StageType::ONE_WAY};
    static constexpr Stage forestWorldWoodsCostumeStage = {"ForestWorldWoodsCostumeStage", "Explorer_Bonus", StageType::ONE_WAY};
    static constexpr Stage packunPoisonExStage = {"PackunPoisonExStage", "PoisonEx", StageType::MULTI_WAY};
    static constexpr Stage animalChaseExStage = {"AnimalChaseExStage", "EX_AnimalChase", StageType::ONE_WAY};
    static constexpr Stage killerRoadExStage = {"KillerRoadExStage", "KillerRoad", StageType::ONE_WAY};

    static constexpr Stage cloudWorldHomeStageViaFukuwaraiKuriboStage = {"CloudWorldHomeStage", "Fukuwarai", StageType::MULTI_WAY};
    static constexpr Stage cloudWorldHomeStageViaCube2DExStage = {"CloudWorldHomeStage", "cube", StageType::MULTI_WAY};
    static constexpr Stage fukuwaraiKuriboStage = {"FukuwaraiKuriboStage", "Fukuwarai", StageType::ONE_WAY};
    static constexpr Stage cube2DExStage = {"Cube2DExStage", "cube", StageType::ONE_WAY};

    static constexpr Stage clashWorldHomeStageViaClashWorldShopStage = {"ClashWorldHomeStage", "Kinopio", StageType::MULTI_WAY};
    static constexpr Stage clashWorldHomeStageViaImomuPoisonExStage = {"ClashWorldHomeStage", "imomu_02", StageType::MULTI_WAY};
    static constexpr Stage clashWorldHomeStageViaJangoExStage = {"ClashWorldHomeStage", "ClashWorldMoonEX2", StageType::MULTI_WAY};
    static constexpr Stage clashWorldShopStage = {"ClashWorldShopStage", "Kinopio", StageType::ONE_WAY};
    static constexpr Stage imomuPoisonExStage = {"ImomuPoisonExStage", "imomu_01", StageType::MULTI_WAY};
    static constexpr Stage jangoExStage = {"JangoExStage", "ClashWorldMoonEX2", StageType::ONE_WAY};

    static constexpr Stage cityWorldHomeStageViaCityWorldMainTowerStageBottom = {"CityWorldHomeStage", "main_enter", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityWorldMainTowerStageTop = {"CityWorldHomeStage", "main_exit", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityWorldFactoryStage = {"CityWorldHomeStage", "under001enter", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityWorldShop01StageYellow = {"CityWorldHomeStage", "shop_coin", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityWorldShop01StagePurple = {"CityWorldHomeStage", "shop_correct", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityWorldSandSlotStage = {"CityWorldHomeStage", "Bonus", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityPeopleRoadStagePrePeace = {"CityWorldHomeStage", "gunsyu", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCityPeopleRoadStagePostPeace = {"CityWorldHomeStage", "gunsyudokan", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaPoleGrabCeilExStage = {"CityWorldHomeStage", "tenjo", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaTrexBikeExStage = {"CityWorldHomeStage", "bike02return", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaPoleKillerExStage = {"CityWorldHomeStage", "boureturn", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaNote2D3DRoomExStage = {"CityWorldHomeStage", "onpu", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaShootingCityExStage = {"CityWorldHomeStage", "taxireturn", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaCapRotatePackunExStage = {"CityWorldHomeStage", "kaitendokan", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaRadioControlExStage = {"CityWorldHomeStage", "car", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaElectricWireExStage = {"CityWorldHomeStage", "densendokan", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaTheater2DExStage = {"CityWorldHomeStage", "theater", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaDonsukeExStage = {"CityWorldHomeStage", "donsuke", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaSwingSteelExStage = {"CityWorldHomeStage", "gragrareturn", StageType::MULTI_WAY};
    static constexpr Stage cityWorldHomeStageViaBikeSteelExStage = {"CityWorldHomeStage", "bikereturn", StageType::MULTI_WAY};
    static constexpr Stage cityWorldMainTowerStageBottom = {"CityWorldMainTowerStage", "main_enter", StageType::MULTI_WAY};
    static constexpr Stage cityWorldMainTowerStageTop = {"CityWorldMainTowerStage", "main_exit", StageType::MULTI_WAY};
    static constexpr Stage cityWorldFactoryStage = {"CityWorldFactoryStage", "under001enter", StageType::ONE_WAY};
    static constexpr Stage cityWorldShop01StageYellow = {"CityWorldShop01Stage", "shop_coin", StageType::MULTI_WAY};
    static constexpr Stage cityWorldShop01StagePurple = {"CityWorldShop01Stage", "shop_correct", StageType::MULTI_WAY};
    static constexpr Stage cityWorldSandSlotStage = {"CityWorldSandSlotStage", "Bonus", StageType::ONE_WAY};
    static constexpr Stage cityPeopleRoadStageEntrance = {"CityPeopleRoadStage", "gunsyu", StageType::MULTI_WAY};
    static constexpr Stage cityPeopleRoadStageExit = {"CityPeopleRoadStage", "gunsyudokan", StageType::MULTI_WAY};
    static constexpr Stage poleGrabCeilExStage = {"PoleGrabCeilExStage", "tenjo", StageType::ONE_WAY};
    static constexpr Stage trexBikeExStage = {"TrexBikeExStage", "bike02", StageType::MULTI_WAY};
    static constexpr Stage poleKillerExStage = {"PoleKillerExStage", "bou", StageType::MULTI_WAY};
    static constexpr Stage note2D3DRoomExStage = {"Note2D3DRoomExStage", "onpu", StageType::ONE_WAY};
    static constexpr Stage shootingCityExStage = {"ShootingCityExStage", "taxi", StageType::MULTI_WAY};
    static constexpr Stage capRotatePackunExStage = {"CapRotatePackunExStage", "kaitendokan", StageType::ONE_WAY};
    static constexpr Stage radioControlExStage = {"RadioControlExStage", "car", StageType::ONE_WAY};
    static constexpr Stage electricWireExStage = {"ElectricWireExStage", "densen", StageType::MULTI_WAY};
    static constexpr Stage theater2DExStage = {"Theater2DExStage", "theater", StageType::ONE_WAY};
    static constexpr Stage donsukeExStage = {"DonsukeExStage", "donsuke", StageType::ONE_WAY};
    static constexpr Stage swingSteelExStage = {"SwingSteelExStage", "gragra", StageType::MULTI_WAY};
    static constexpr Stage bikeSteelExStage = {"BikeSteelExStage", "bike", StageType::MULTI_WAY};

    static constexpr Stage snowWorldHomeStageViaSnowWorldTownStage = {"SnowWorldHomeStage", "SnowUGExit", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaSnowWorldShopStage = {"SnowWorldHomeStage", "ShopDoor", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaSnowWorldCostumeStage = {"SnowWorldHomeStage", "SnowCostumeEx", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaSnowWorldCloudBonusExStage = {"SnowWorldHomeStage", "EX_SkyBonus", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaIceWalkerExStage = {"SnowWorldHomeStage", "FigureWalker", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaIceWaterBlockExStage = {"SnowWorldHomeStage", "EX_IceWater_Exit", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaByugoPuzzleExStage = {"SnowWorldHomeStage", "ByugoPuzzle", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaIceWaterDashExStage = {"SnowWorldHomeStage", "EX_IceWaterDash_Exit", StageType::MULTI_WAY};
    static constexpr Stage snowWorldHomeStageViaKillerRailCollisionExStage = {"SnowWorldHomeStage", "EX_RailCol2_Exit", StageType::MULTI_WAY};
    static constexpr Stage snowWorldTownStage = {"SnowWorldTownStage", "SnowUGEnt", StageType::MULTI_WAY};
    static constexpr Stage snowWorldShopStage = {"SnowWorldShopStage", "ShopDoor", StageType::ONE_WAY};
    static constexpr Stage snowWorldCostumeStage = {"SnowWorldCostumeStage", "SnowCostumeEx", StageType::ONE_WAY};
    static constexpr Stage snowWorldCloudBonusExStage = {"SnowWorldCloudBonusExStage", "EX_SkyBonus", StageType::ONE_WAY};
    static constexpr Stage iceWalkerExStage = {"IceWalkerExStage", "FigureWalker", StageType::ONE_WAY};
    static constexpr Stage iceWaterBlockExStage = {"IceWaterBlockExStage", "EX_IceWater", StageType::MULTI_WAY};
    static constexpr Stage byugoPuzzleExStage = {"ByugoPuzzleExStage", "ByugoPuzzle", StageType::ONE_WAY};
    static constexpr Stage iceWaterDashExStage = {"IceWaterDashExStage", "EX_IceWaterDash", StageType::MULTI_WAY};
    static constexpr Stage killerRailCollisionExStage = {"KillerRailCollisionExStage", "EX_RailCol2", StageType::MULTI_WAY};

    static constexpr Stage seaWorldHomeStageViaSeaWorldUtsuboCaveStage = {"SeaWorldHomeStage", "PukupukuCaveGoal", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaSeaWorldVibrationStage = {"SeaWorldHomeStage", "shindo_Lv2", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaSeaWorldSecretStage = {"SeaWorldHomeStage", "TreasureEventWorldSea", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaSeaWorldCostumeStage = {"SeaWorldHomeStage", "CostumeEventSeaWorld", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaSeaWorldSneakingManStage = {"SeaWorldHomeStage", "RoomEventWorldSea", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaSenobiTowerExStage = {"SeaWorldHomeStage", "SeaWorldEX3b", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaCloudExStage = {"SeaWorldHomeStage", "SeaWorldEX2Return", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaWaterValleyExStage = {"SeaWorldHomeStage", "SeaWorldEX1b", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaReflectBombExStage = {"SeaWorldHomeStage", "SeaWorldMoonEX1a", StageType::MULTI_WAY};
    static constexpr Stage seaWorldHomeStageViaTogezoRotateExStage = {"SeaWorldHomeStage", "SeaWorldMoonEX2", StageType::MULTI_WAY};
    static constexpr Stage seaWorldUtsuboCaveStage = {"SeaWorldUtsuboCaveStage", "PukupukuCaveStart", StageType::MULTI_WAY};
    static constexpr Stage seaWorldVibrationStage = {"SeaWorldVibrationStage", "shindo_Lv2", StageType::ONE_WAY};
    static constexpr Stage seaWorldSecretStage = {"SeaWorldSecretStage", "TreasureEventWorldSea", StageType::ONE_WAY};
    static constexpr Stage seaWorldCostumeStage = {"SeaWorldCostumeStage", "CostumeEventSeaWorld", StageType::ONE_WAY};
    static constexpr Stage seaWorldSneakingManStage = {"SeaWorldSneakingManStage", "RoomEventWorldSea", StageType::ONE_WAY};
    static constexpr Stage senobiTowerExStage = {"SenobiTowerExStage", "SeaWorldEX3a", StageType::MULTI_WAY};
    static constexpr Stage cloudExStage = {"CloudExStage", "SeaWorldEX2", StageType::MULTI_WAY};
    static constexpr Stage waterValleyExStage = {"WaterValleyExStage", "SeaWorldEX1a", StageType::MULTI_WAY};
    static constexpr Stage reflectBombExStage = {"ReflectBombExStage", "SeaWorldMoonEX1a", StageType::ONE_WAY};
    static constexpr Stage togezoRotateExStage = {"TogezoRotateExStage", "SeaWorldMoonEX2", StageType::ONE_WAY};

    static constexpr Stage lavaWorldHomeStageViaLavaWorldUpDownExStage = {"LavaWorldHomeStage", "KeyMoveExDokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaBonus1Zone = {"LavaWorldHomeStage", "town", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldShopStage = {"LavaWorldHomeStage", "shop", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldCostumeStage = {"LavaWorldHomeStage", "CostumeOut", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaForkExStage = {"LavaWorldHomeStage", "ForkEX", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldExcavationExStage = {"LavaWorldHomeStage", "MartinCubeEx", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldClockExStage = {"LavaWorldHomeStage", "BBQExDokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldBubbleLaneExStage = {"LavaWorldHomeStage", "PechoBubbleExDokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldTreasureStage = {"LavaWorldHomeStage", "TreasureEventWorldLava", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaGabuzouClockExStage = {"LavaWorldHomeStage", "GabuzouClockExdokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaCapAppearLavaLiftExStage = {"LavaWorldHomeStage", "LavaLiftExdokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldHomeStageViaLavaWorldFenceLiftExStage = {"LavaWorldHomeStage", "FenceLiftExdokan", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldUpDownExStage = {"LavaWorldUpDownExStage", "KeyMoveEx", StageType::MULTI_WAY};
    static constexpr Stage lavaBonus1Zone = {"LavaBonus1Zone", "town", StageType::ONE_WAY};
    static constexpr Stage lavaWorldShopStage = {"LavaWorldShopStage", "shop", StageType::ONE_WAY};
    static constexpr Stage lavaWorldCostumeStage = {"LavaWorldCostumeStage", "CostumeEventWorldLava", StageType::MULTI_WAY};
    static constexpr Stage forkExStage = {"ForkExStage", "ForkEX", StageType::ONE_WAY};
    static constexpr Stage lavaWorldExcavationExStage = {"LavaWorldExcavationExStage", "MartinCubeEx", StageType::ONE_WAY};
    static constexpr Stage lavaWorldClockExStage = {"LavaWorldClockExStage", "BBQEx", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldBubbleLaneExStage = {"LavaWorldBubbleLaneExStage", "PechoBubbleEx", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldTreasureStage = {"LavaWorldTreasureStage", "TreasureEventWorldLava", StageType::ONE_WAY};
    static constexpr Stage gabuzouClockExStage = {"GabuzouClockExStage", "GabuzouClockEx", StageType::MULTI_WAY};
    static constexpr Stage capAppearLavaLiftExStage = {"CapAppearLavaLiftExStage", "LavaLiftEx", StageType::MULTI_WAY};
    static constexpr Stage lavaWorldFenceLiftExStage = {"LavaWorldFenceLiftExStage", "FenceLiftEx", StageType::MULTI_WAY};

    static constexpr Stage bossRaidWorldHomeStageViaDotTowerExStage = {"BossRaidWorldHomeStage", "BossRaidWorldEx01_Eixt", StageType::MULTI_WAY};
    static constexpr Stage bossRaidWorldHomeStageViaBullRunExStage = {"BossRaidWorldHomeStage", "BossRaidWorldMoonEx02_Exit", StageType::MULTI_WAY};
    static constexpr Stage dotTowerExStage = {"DotTowerExStage", "BossRaidWorldEx01_Eixt", StageType::ONE_WAY};
    static constexpr Stage bullRunExStage = {"BullRunExStage", "BossRaidWorldMoonEx02_Enter", StageType::MULTI_WAY};

    static constexpr Stage skyWorldHomeStageViaSkyWorldShopStage = {"SkyWorldHomeStage", "shop", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaSkyWorldCostumeStage = {"SkyWorldHomeStage", "byoubu", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaSkyWorldCloudBonusExStage = {"SkyWorldHomeStage", "sora001", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaSkyWorldTreasureStage = {"SkyWorldHomeStage", "shopdress", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaJizoSwitchExStage = {"SkyWorldHomeStage", "jizo01", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaTsukkunRotateExStage = {"SkyWorldHomeStage", "tukkun000_exit", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaKaronWingTowerStage = {"SkyWorldHomeStage", "Patakaron02", StageType::MULTI_WAY};
    static constexpr Stage skyWorldHomeStageViaTsukkunClimbExStage = {"SkyWorldHomeStage", "tukkun001_exit", StageType::MULTI_WAY};
    static constexpr Stage skyWorldShopStage = {"SkyWorldShopStage", "shop", StageType::ONE_WAY};
    static constexpr Stage skyWorldCostumeStage = {"SkyWorldCostumeStage", "byoubu", StageType::ONE_WAY};
    static constexpr Stage skyWorldCloudBonusExStage = {"SkyWorldCloudBonusExStage", "sora001", StageType::ONE_WAY};
    static constexpr Stage skyWorldTreasureStage = {"SkyWorldTreasureStage", "shopdress", StageType::ONE_WAY};
    static constexpr Stage jizoSwitchExStage = {"JizoSwitchExStage", "jizo01", StageType::ONE_WAY};
    static constexpr Stage tsukkunRotateExStage = {"TsukkunRotateExStage", "tukkun000_enter", StageType::MULTI_WAY};
    static constexpr Stage karonWingTowerStage = {"KaronWingTowerStage", "Patakaron02", StageType::ONE_WAY};
    static constexpr Stage tsukkunClimbExStage = {"TsukkunClimbExStage", "tukkun001_enter", StageType::MULTI_WAY};

    static constexpr Stage peachWorldHomeStageViaPeachWorldShopStage = {"PeachWorldHomeStage", "PeachWorldShopA", StageType::MULTI_WAY};
    static constexpr Stage peachWorldHomeStageViaPeachWorldCostumeStage = {"PeachWorldHomeStage", "CostumeEventWorldPeach", StageType::MULTI_WAY};
    static constexpr Stage peachWorldHomeStageViaFukuwaraiMarioStage = {"PeachWorldHomeStage", "Fukuwarai2", StageType::MULTI_WAY};
    static constexpr Stage peachWorldHomeStageViaDotHardExStage = {"PeachWorldHomeStage", "PeachWorldEx2a", StageType::MULTI_WAY};
    static constexpr Stage peachWorldHomeStageViaYoshiCloudExStage = {"PeachWorldHomeStage", "PeachWorldEx1a", StageType::MULTI_WAY};
    static constexpr Stage peachWorldShopStage = {"PeachWorldShopStage", "PeachWorldShopA", StageType::ONE_WAY};
    static constexpr Stage peachWorldCostumeStage = {"PeachWorldCostumeStage", "CostumeEventWorldPeach", StageType::ONE_WAY};
    static constexpr Stage fukuwaraiMarioStage = {"FukuwaraiMarioStage", "Fukuwarai2", StageType::ONE_WAY};
    static constexpr Stage dotHardExStage = {"DotHardExStage", "PeachWorldEx2a", StageType::ONE_WAY};
    static constexpr Stage yoshiCloudExStage = {"YoshiCloudExStage", "PeachWorldEx1a", StageType::ONE_WAY};


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