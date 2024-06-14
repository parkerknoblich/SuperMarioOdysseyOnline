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