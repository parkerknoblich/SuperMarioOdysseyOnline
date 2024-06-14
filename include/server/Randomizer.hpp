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

// Cap
//     CapWorldTowerStage
//         Bottom Entrance/Exit = Ex
//         Top Entrance/Exit = Goal
//     FrogSearchExStage
//         Entrance/Exit = FrogSearchExStageEnt
//     PoisonWaveExStage
//         Entrance = PoisonWaveExEnt
//         Exit = PoisonWaveExExit
//     PushBlockExStage
//         Entrance = PushBlockExStageEnt
//         Exit = PushBlockExStageEntDokan
//     RollingExStage
//         Entrance = rollingstart
//         Exit = rollinggoal

// Cascade
//     TrexPoppunExStage
//         Entrance/Exit = RexPoppunEx
//     Lift2DExStage
//         Entrance = Lift2D
//         Exit = Lift2DExit
//     WanwanClashExStage
//         Entrance = WanwanExStart
//         Exit = WanwanExGoal
//     CapAppearExStage
//         Entrance = CapAppearExEnt
//         Exit = CapAppearExExit
//     WindBlowExStage
//         Entrance = WindBlowExStart
//         Exit = WindBlowExGoal

// Sand
//     SandWorldShopStage
//         Front Entrance = bar1
//         Back Entrance = bar2
//     SandWorldSlotStage
//         Entrance/Exit = town
//     SandWorldVibrationStage
//         Entrance/Exit = shindo
//     SandWorldSecretStage
//         Entrance/Exit = hide
//     SandWorldMeganeExStage
//         Entrance = wall
//         Exit = anki2
//     SandWorldKillerExStage
//         Entrance = doukutu1
//         Exit = doukutu2
//     SandWorldPressExStage
//         Entrance = arijigoku1
//         Exit = arijigoku2
//     SandWorldSphinxExStage
//         Entrance = run00
//         Exit = run00return
//     SandWorldCostumeStage
//         Entrance/Exit = abc
//     SandWorldPyramid000Stage
//         Entrance = pyramid01
//         Exit = pyramid02
//     SandWorldPyramid001Stage
//         Entrance = pyramid03
//         Exit = pyramid04
//     SandWorldUnderground000Stage
//         Entrance = icestart
//         Leave from Entrance = Under01
//     SandWorldUnderground001Stage
//         Entrance = Yadokari00
//         Exit = Out
//     SandWorldRotateExStage
//         Entrance = biru
//         Exit = birureturn
//     MeganeLiftExStage
//         Entrance = meganelift01
//         Exit = meganelift02
//     RocketFlowerExStage
//         Entrance/Exit = rocket
//     WaterTubeExStage
//         Entrance = EX_2DHosui
//         Exit = EX_2DHosui_Exit

// Lake
//     LakeWorldShopStage
//         Entrance/Exit = LakeWorldShop
//     FastenerExStage
//         Entrance/Exit = FastenerEx
//     TrampolineWallCatchExStage
//         Entrance = CapTrampolineA
//         Exit = CapTrampolineB
//     GotogotonExStage
//         Entrance/Exit = Goton
//     FrogPoisonExStage
//         Entrance = LakeWorldMoonEX1a
//         Exit = LakeWorldMoonEX1b

// Wooded
//     ForestWorldWaterExStage
//         Entrance = EX_Water
//         Exit = EX_Water_Exit
//     ForestWorldTowerStage
//         Bottom Entrance/Exit = Tower001
//         Top Entrance/Exit = Tower002
//     ForestWorldBossStage
//         Entrance = boss001
//         Exit = boss002
//     ForestWorldBonusStage
//         Entrance = bonus1
//         Exit = bonus2
//     ForestWorldCloudBonusExStage
//         Entrance = EXCloud
//         Exit = EXCloud
//     FogMountainExStage
//         Entrance/Exit = EX_Mist
//     RailCollisionExStage
//         Entrance = EX_RailCollision_Exit
//         Exit = EX_RailCollision
//     ShootingElevatorExStage
//         Entrance = EX_Tankuro
//         Exit = EX_Tankuro_Exit
//     ForestWorldWoodsStage
//         Entrance near Odyssey = Jyukai001 (also Jyukai002v)
//         Exit near Odyssey = Jyukai001v
//         Exit near Firebro = Jyukai002
//         Entrance near Talkatoo = Jyukai003
//         Exit near Talkatoo = Jyukai003v
//     ForestWorldWoodsTreasureStage
//         Entrance/Exit = TreasureTree
//     ForestWorldWoodsCostumeStage
//         Entrance/Exit = Explorer_Bonus
//     PackunPoisonExStage
//         Entrance = PoisonEx
//         Exit = PoisonEx_Exit
//     AnimalChaseExStage
//         Entrance/Exit = EX_AnimalChase
//     KillerRoadExStage
//         Entrance/Exit = KillerRoad

// Cloud
//     FukuwaraiKuriboStage
//         Entrance/Exit = Fukuwarai
//     Cube2DExStage
//         Entrance/Exit = cube

// Lost
//     ClashWorldShopStage
//         Entrance/Exit = Kinopio
//     ImomuPoisonExStage
//         Entrance = imomu_01
//         Exit = imomu_02
//     JangoExStage
//         Entrance/Exit = ClashWorldMoonEX2

// Metro
//     CityWorldMainTowerStage
//         Bottom Entrance = main_enter
//         Top Entrance = main_exit
//     CityWorldFactoryStage
//         Entrance/Exit = under001enter
//     CityWorldShop01Stage
//         Yellow Entrance = shop_coin
//         Purple Entrance = shop_correct
//     CityWorldSandSlotStage
//         Entrance/Exit = Bonus
//     CityPeopleRoadStage
//         Entrance = gunsyu
//         Exit over to rocket = gunsyudokan
//     PoleGrabCeilExStage
//         Entrance/Exit = tenjo
//     TrexBikeExStage
//         Entrance = bike02
//         Exit = bike02return
//     PoleKillerExStage
//         Entrance = bou
//         Exit = boureturn
//     Note2D3DRoomExStage
//         Entrance/Exit = onpu
//     ShootingCityExStage
//         Entrance = taxi
//         Exit = taxireturn
//     CapRotatePackunExStage
//         Entrance/Exit = kaitendokan
//     RadioControlExStage
//         Entrance/Exit = car
//     ElectricWireExStage
//         Entrance = densen
//         Exit = densendokan
//     Theater2DExStage
//         Entrance/Exit = theater
//     DonsukeExStage
//         Entrance/Exit = donsuke
//     SwingSteelExStage
//         Entrance = gragra
//         Exit = gragrareturn
//     BikeSteelExStage
//         Entrance = bike
//         Exit = bikereturn

// Snow
//     SnowWorldTownStage
//         Entrance = SnowUGEnt
//         Exit = SnowUGExit
//     SnowWorldShopStage
//         Entrance/Exit = ShopDoor
//     For Snow Race Lobbies, allow player to enter there naturally
//     SnowWorldCostumeStage
//         Entrance/Exit = SnowCostumeEx
//     SnowWorldCloudBonusExStage
//         Entrance/Exit = EX_SkyBonus
//     IceWalkerExStage
//         Entrance/Exit = FigureWalker
//     IceWaterBlockExStage
//         Entrance = EX_IceWater
//         Exit = EX_IceWater_Exit
//     ByugoPuzzleExStage
//         Entrance/Exit = ByugoPuzzle
//     IceWaterDashExStage
//         Entrance = EX_IceWaterDash
//         Exit = EX_IceWaterDash_Exit
//     KillerRailCollisionExStage
//         Entrance = EX_RailCol2
//         Exit = EX_RailCol2_Exit

// Seaside
//     SeaWorldUtsuboCaveStage
//         Entrance = PukupukuCaveStart
//         Exit = PukupukuCaveGoal
//     SeaWorldVibrationStage
//         Entrance/Exit = shindo_Lv2
//     SeaWorldSecretStage
//         Entrance/Exit = TreasureEventWorldSea
//     SeaWorldCostumeStage
//         Entrance/Exit = CostumeEventSeaWorld
//     SeaWorldSneakingManStage
//         Entrance/Exit = RoomEventWorldSea
//     SenobiTowerExStage
//         Entrance = SeaWorldEX3a
//         Exit = SeaWorldEX3b
//     CloudExStage
//         Entrance = SeaWorldEX2
//         Exit = SeaWorldEX2Return
//     WaterValleyExStage
//         Entrance = SeaWorldEX1a
//         Exit = SeaWorldEX1b
//     ReflectBombExStage
//         Entrance/Exit = SeaWorldMoonEX1a
//     TogezoRotateExStage
//         Entrance/Exit = SeaWorldMoonEX2

// Luncheon
//     LavaWorldUpDownExStage
//         Entrance = KeyMoveEx
//         Exit = KeyMoveExDokan
//     LavaBonus1Zone
//         Entrance/Exit = town
//     LavaWorldShopStage
//         Entrance/Exit = shop
//     LavaWorldCostumeStage
//         Entrance = CostumeEventWorldLava
//         Exit = CostumeOut
//     ForkExStage
//         Entrance/Exit = ForkEX
//     LavaWorldExcavationExStage
//         Entrance/Exit = MartinCubeEx
//     LavaWorldClockExStage
//         Entrance = BBQEx
//         Exit = BBQExDokan
//     LavaWorldBubbleLaneExStage
//         Entrance = PechoBubbleEx
//         Exit = PechoBubbleExDokan
//     LavaWorldTreasureStage
//         Entrance/Exit = TreasureEventWorldLava
//     GabuzouClockExStage
//         Entrance = GabuzouClockEx
//         Exit = GabuzouClockExdokan
//     CapAppearLavaLiftExStage
//         Entrance = LavaLiftEx
//         Exit = LavaLiftExdokan
//     LavaWorldFenceLiftExStage
//         Entrance = FenceLiftEx
//         Exit = FenceLiftExdokan (warping here manually does not work)

// Ruined
//     DotTowerExStage
//         Entrance/Exit = BossRaidWorldEx01_Eixt
//     BullRunExStage
//         Entrance = BossRaidWorldMoonEx02_Enter
//         Exit = BossRaidWorldMoonEx02_Exit

// Bowsers
//     SkyWorldShopStage
//         Entrance/Exit = shop
//     SkyWorldCostumeStage
//         Entrance/Exit = byoubu
//     SkyWorldCloudBonusExStage
//         Entrance/Exit = sora001
//     SkyWorldTreasureStage
//         Entrance/Exit = shopdress
//     JizoSwitchExStage
//         Entrance/Exit = jizo01
//     TsukkunRotateExStage
//         Entrance = tukkun000_enter
//         Exit = tukkun000_exit (cannot spawn here, trapped unless ogre opens door)
//     KaronWingTowerStage
//         Entrance/Exit = Patakaron02
//     TsukkunClimbExStage
//         Entrance = tukkun001_enter
//         Exit = tukkun001_exit

// Mushroom
//     PeachWorldShopStage
//         Entrance/Exit = PeachWorldShopA
//     PeachWorldCostumeStage
//         Entrance/Exit = CostumeEventWorldPeach
//     FukuwaraiMarioStage
//         Entrance/Exit = Fukuwarai2
//     DotHardExStage
//         Entrance/Exit = PeachWorldEx2a
//     YoshiCloudExStage
//         Entrance/Exit = PeachWorldEx1a