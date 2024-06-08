#include "main.hpp"
#include <cmath>
#include <math.h>
#include "al/execute/ExecuteOrder.h"
#include "al/execute/ExecuteTable.h"
#include "al/execute/ExecuteTableHolderDraw.h"
#include "al/util/GraphicsUtil.h"
#include "container/seadSafeArray.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include "game/Player/PlayerActorBase.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/Player/PlayerHackKeeper.h"
#include "heap/seadHeap.h"
#include "math/seadVector.h"
#include "server/Client.hpp"
#include "puppets/PuppetInfo.h"
#include "actors/PuppetActor.h"
#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/util/AudioUtil.h"
#include "al/util/CameraUtil.h"
#include "al/util/ControllerUtil.h"
#include "al/util/LiveActorUtil.h"
#include "al/util/NerveUtil.h"
#include "debugMenu.hpp"
#include "game/GameData/GameDataFunction.h"
#include "game/HakoniwaSequence/HakoniwaSequence.h"
#include "game/Player/PlayerFunction.h"
#include "game/StageScene/StageScene.h"
#include "helpers.hpp"
#include "layouts/HideAndSeekIcon.h"
#include "logger.hpp"
#include "rs/util.hpp"
#include "server/gamemode/GameModeBase.hpp"
#include "server/hns/HideAndSeekMode.hpp"
#include "server/gamemode/GameModeManager.hpp"

static int pInfSendTimer = 0;
static int gameInfSendTimer = 0;

void updatePlayerInfo(GameDataHolderAccessor holder, PlayerActorBase* playerBase, bool isYukimaru) {
    
    if (pInfSendTimer >= 3) {

        Client::sendPlayerInfPacket(playerBase, isYukimaru);

        if (!isYukimaru) {
            Client::sendHackCapInfPacket(((PlayerActorHakoniwa*)playerBase)->mHackCap);

            Client::sendCaptureInfPacket((PlayerActorHakoniwa*)playerBase);
        }

        pInfSendTimer = 0;
    }

    if (gameInfSendTimer >= 60) {

        if (isYukimaru) {
            Client::sendGameInfPacket(holder);
        } else {
            Client::sendGameInfPacket((PlayerActorHakoniwa*)playerBase, holder);
        }
        
        gameInfSendTimer = 0;
    }

    pInfSendTimer++;
    gameInfSendTimer++;
}

// ------------- Hooks -------------

int debugPuppetIndex = 0;
int debugCaptureIndex = 0;
static int pageIndex = 0;

static const int maxPages = 3;

void drawMainHook(HakoniwaSequence *curSequence, sead::Viewport *viewport, sead::DrawContext *drawContext) {

    // sead::FrameBuffer *frameBuffer;
    // __asm ("MOV %[result], X21" : [result] "=r" (frameBuffer));

    // if(Application::sInstance->mFramework) {
    //     Application::sInstance->mFramework->mGpuPerf->drawResult((agl::DrawContext *)drawContext, frameBuffer);
    // }

    Time::calcTime();  // this needs to be ran every frame, so running it here works

    if(!debugMode) {
        al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");
        return;
    }

    // int dispWidth = al::getLayoutDisplayWidth();
    int dispHeight = al::getLayoutDisplayHeight();

    gTextWriter->mViewport = viewport;

    gTextWriter->mColor = sead::Color4f(1.f, 1.f, 1.f, 0.8f);

    drawBackground((agl::DrawContext *)drawContext);

    gTextWriter->beginDraw();
    gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, 10.f));

    gTextWriter->printf("FPS: %d\n", static_cast<int>(round(Application::sInstance->mFramework->calcFps())));

    gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, (dispHeight / 3) + 30.f));
    gTextWriter->setScaleFromFontHeight(20.f);

    sead::Heap* clientHeap = Client::getClientHeap();
    sead::Heap *gmHeap = GameModeManager::instance()->getHeap();

    if (clientHeap) {
        gTextWriter->printf("Client Heap Free Size: %f/%f\n", clientHeap->getFreeSize() * 0.001f, clientHeap->getSize() * 0.001f);
        gTextWriter->printf("Gamemode Heap Free Size: %f/%f\n", gmHeap->getFreeSize() * 0.001f, gmHeap->getSize()* 0.001f);
    }

    gTextWriter->printf("Client Socket Connection Status: %s\n", Client::instance()->mSocket->getStateChar());
	gTextWriter->printf("Udp socket status: %s\n", Client::instance()->mSocket->getUdpStateChar());
    //gTextWriter->printf("nn::socket::GetLastErrno: 0x%x\n", Client::instance()->mSocket->socket_errno);
    gTextWriter->printf("Connected Players: %d/%d\n", Client::getConnectCount() + 1, Client::getMaxPlayerCount());
    
    gTextWriter->printf("Send Queue Count: %d/%d\n", Client::instance()->mSocket->getSendCount(), Client::instance()->mSocket->getSendMaxCount());
    gTextWriter->printf("Recv Queue Count: %d/%d\n", Client::instance()->mSocket->getRecvCount(), Client::instance()->mSocket->getRecvMaxCount());

    al::Scene *curScene = curSequence->curScene;

    if(curScene && isInGame) {

        sead::LookAtCamera *cam = al::getLookAtCamera(curScene, 0);
        sead::Projection* projection = al::getProjectionSead(curScene, 0);

        PlayerActorBase* playerBase = rs::getPlayerActor(curScene);

        PuppetActor* curPuppet = Client::getPuppet(debugPuppetIndex);

        PuppetActor *debugPuppet = Client::getDebugPuppet();

        if (debugPuppet) {
            curPuppet = debugPuppet;
        }

        sead::PrimitiveRenderer *renderer = sead::PrimitiveRenderer::instance();
        renderer->setDrawContext(drawContext);
        renderer->setCamera(*cam);
        renderer->setProjection(*projection);

        gTextWriter->printf("----------- Page %d ------------\n", pageIndex);
        switch (pageIndex)
        {
        case 0:
            {
                // PuppetActor *curPuppet = Client::getDebugPuppet();

                if(curPuppet) {

                    al::LiveActor* curModel = curPuppet->getCurrentModel();

                    PuppetInfo* curPupInfo = curPuppet->getInfo();

                    if (curModel && curPupInfo) {
                        // al::LiveActor *curCapture = curPuppet->getCapture(debugCaptureIndex);

                        gTextWriter->printf("Puppet Index: %d\n", debugPuppetIndex);
                        gTextWriter->printf("Player Name: %s\n", curPupInfo->puppetName);
                        gTextWriter->printf("Connection Status: %s\n", curPupInfo->isConnected ? "Online" : "Offline");
                        gTextWriter->printf("Is in Same Stage: %s\n", curPupInfo->isInSameStage ? "True" : "False");
                        gTextWriter->printf("Is in Capture: %s\n", curPupInfo->isCaptured ? "True" : "False");
                        gTextWriter->printf("Puppet Stage: %s\n", curPupInfo->stageName);
                        gTextWriter->printf("Puppet Scenario: %u\n", curPupInfo->scenarioNo);
                        gTextWriter->printf("Puppet Costume: H: %s B: %s\n", curPupInfo->costumeHead, curPupInfo->costumeBody);
                        //gTextWriter->printf("Packet Coords:\nX: %f\nY: %f\nZ: %f\n", curPupInfo->playerPos.x, curPupInfo->playerPos.y, curPupInfo->playerPos.z);
                        // if (curModel) {
                        //     sead::Vector3f* pupPos = al::getTrans(curModel);
                        //     gTextWriter->printf("In-Game Coords:\nX: %f\nY: %f\nZ: %f\n", pupPos->x, pupPos->y, pupPos->z);
                        // }

                        if(curPupInfo->isCaptured) {
                            gTextWriter->printf("Current Capture: %s\n", curPupInfo->curHack);
                            gTextWriter->printf("Current Packet Animation: %s\n", curPupInfo->curAnimStr);
                            gTextWriter->printf("Animation Index: %d\n", curPupInfo->curAnim);
                        }else {
                            gTextWriter->printf("Current Packet Animation: %s\n", curPupInfo->curAnimStr);
                            gTextWriter->printf("Animation Index: %d\n", curPupInfo->curAnim);
                            if (curModel) {
                                gTextWriter->printf("Current Animation: %s\n", al::getActionName(curModel));
                            }
                        }
                        gTextWriter->printf("Debug Amount: %d (%d)\n", Client::getDebugAmount(), Client::getDebugCounter());
                    }
                }
            }
            break;
        case 1:
            {
                PuppetActor* debugPuppet = Client::getDebugPuppet();
                PuppetInfo* debugInfo = Client::getDebugPuppetInfo();

                if (debugPuppet && debugInfo) {

                    al::LiveActor *curModel = debugPuppet->getCurrentModel();

                    gTextWriter->printf("Is Debug Puppet Tagged: %s\n", BTOC(debugInfo->isIt));

                }
            }
            break;
        case 2:
            {
            PlayerHackKeeper* hackKeeper = playerBase->getPlayerHackKeeper();

            if (hackKeeper) {

                PlayerActorHakoniwa *p1 = (PlayerActorHakoniwa*)playerBase; // its safe to assume that we're using a playeractorhakoniwa if the hack keeper isnt null

                if(hackKeeper->currentHackActor) {

                    al::LiveActor *curHack = hackKeeper->currentHackActor;

                    gTextWriter->printf("Current Hack Animation: %s\n", al::getActionName(curHack));
                    gTextWriter->printf("Current Hack Name: %s\n",
                                        hackKeeper->getCurrentHackName());
                    sead::Quatf captureRot = curHack->mPoseKeeper->getQuat();
                    gTextWriter->printf("Current Hack Rot: %f %f %f %f\n", captureRot.x,
                                        captureRot.y, captureRot.z, captureRot.w);
                    sead::Quatf calcRot;
                    al::calcQuat(&calcRot, curHack);
                    gTextWriter->printf("Calc Hack Rot: %f %f %f %f\n", calcRot.x,
                                        calcRot.y, calcRot.z, calcRot.w);
                } else { 
                    gTextWriter->printf("Cur Action: %s\n", p1->mPlayerAnimator->mAnimFrameCtrl->getActionName());
                    gTextWriter->printf("Cur Sub Action: %s\n", p1->mPlayerAnimator->curSubAnim.cstr());
                    gTextWriter->printf("Is Cappy Flying? %s\n", BTOC(p1->mHackCap->isFlying()));
                    if(p1->mHackCap->isFlying()) {
                        gTextWriter->printf("Cappy Action: %s\n", al::getActionName(p1->mHackCap));
                        sead::Vector3f *capTrans = al::getTransPtr(p1->mHackCap);
                        sead::Vector3f *capRot = &p1->mHackCap->mJointKeeper->mJointRot;
                        gTextWriter->printf("Cap Coords:\nX: %f\nY: %f\nZ: %f\n", capTrans->x, capTrans->y, capTrans->z);
                        gTextWriter->printf("Cap Rot:\nX: %f\nY: %f\nZ: %f\n", capRot->x, capRot->y, capRot->z);
                        gTextWriter->printf("Cap Skew: %f\n", p1->mHackCap->mJointKeeper->mSkew);
                    }
                }
            }
            
            }
            break;
        default:
            break;
        }

        renderer->begin();

        //sead::Matrix34f mat = sead::Matrix34f::ident;
        //mat.setBase(3, sead::Vector3f::zero); // Sets the position of the matrix.
                             // For cubes, you need to put this at the location.
                             // For spheres, you can leave this at 0 0 0 since you set it in its draw function.
        renderer->setModelMatrix(sead::Matrix34f::ident);

        if (curPuppet) {
            renderer->drawSphere4x8(curPuppet->getInfo()->playerPos, 20, sead::Color4f(1.f, 0.f, 0.f, 0.25f));
            renderer->drawSphere4x8(al::getTrans(curPuppet), 20, sead::Color4f(0.f, 0.f, 1.f, 0.25f));
        }

        renderer->end();

        isInGame = false;
    }

    gTextWriter->endDraw();

    al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");

}

void sendShinePacket(GameDataHolderAccessor thisPtr, Shine* curShine) {

    if (!curShine->isGot()) {

        GameDataFile::HintInfo* curHintInfo =
            &thisPtr.mData->mGameDataFile->mShineHintList[curShine->mShineIdx];

        Client::sendShineCollectPacket(curHintInfo->mUniqueID);
    }

    GameDataFunction::setGotShine(thisPtr, curShine->curShineInfo);
}

void stageInitHook(al::ActorInitInfo *info, StageScene *curScene, al::PlacementInfo const *placement, al::LayoutInitInfo const *lytInfo, al::ActorFactory const *factory, al::SceneMsgCtrl *sceneMsgCtrl, al::GameDataHolderBase *dataHolder) {

    al::initActorInitInfo(info, curScene, placement, lytInfo, factory, sceneMsgCtrl,
                          dataHolder);

    Client::clearArrays();

    Client::setSceneInfo(*info, curScene);

    if (GameModeManager::instance()->getGameMode() != NONE) {
        GameModeInitInfo initModeInfo(info, curScene);
        initModeInfo.initServerInfo(GameModeManager::instance()->getGameMode(), Client::getPuppetHolder());

        GameModeManager::instance()->initScene(initModeInfo);
    }

    Client::sendGameInfPacket(info->mActorSceneInfo.mSceneObjHolder);

}

PlayerCostumeInfo *setPlayerModel(al::LiveActor *player, const al::ActorInitInfo &initInfo, const char *bodyModel, const char *capModel, al::AudioKeeper *keeper, bool isCloset) {
    Client::sendCostumeInfPacket(bodyModel, capModel);
    return PlayerFunction::initMarioModelActor(player, initInfo, bodyModel, capModel, keeper, isCloset);
}

al::SequenceInitInfo* initInfo;

ulong constructHook() {  // hook for constructing anything we need to globally be accesible

    __asm("STR X21, [X19,#0x208]"); // stores WorldResourceLoader into HakoniwaSequence

    __asm("MOV %[result], X20"
          : [result] "=r"(
              initInfo));  // Save our scenes init info to a gloabl ptr so we can access it later

    Client::createInstance(al::getCurrentHeap());
    GameModeManager::createInstance(al::getCurrentHeap()); // Create the GameModeManager on the current al heap

    return 0x20;
}

bool threadInit(HakoniwaSequence *mainSeq) {  // hook for initializing client class

    al::LayoutInitInfo lytInfo = al::LayoutInitInfo();

    al::initLayoutInitInfo(&lytInfo, mainSeq->mLytKit, 0, mainSeq->mAudioDirector, initInfo->mSystemInfo->mLayoutSys, initInfo->mSystemInfo->mMessageSys, initInfo->mSystemInfo->mGamePadSys);

    Client::instance()->init(lytInfo, mainSeq->mGameDataHolder);

    return GameDataFunction::isPlayDemoOpening(mainSeq->mGameDataHolder);
}

bool hakoniwaSequenceHook(HakoniwaSequence* sequence) {
    StageScene* stageScene = (StageScene*)sequence->curScene;

    static bool isCameraActive = false;

    bool isFirstStep = al::isFirstStep(sequence);

    al::PlayerHolder *pHolder = al::getScenePlayerHolder(stageScene);
    PlayerActorBase* playerBase = al::tryGetPlayerActor(pHolder, 0);
    
    bool isYukimaru = !playerBase->getPlayerInfo();

    isInGame = !stageScene->isPause();

    GameModeManager::instance()->setPaused(stageScene->isPause());
    Client::setStageInfo(stageScene->mHolder);

    Client::update();

    updatePlayerInfo(stageScene->mHolder, playerBase, isYukimaru);

    static bool isDisableMusic = false;

    if (al::isPadHoldZR(-1)) {
        if (al::isPadTriggerUp(-1)) debugMode = !debugMode;
        if (al::isPadTriggerLeft(-1)) pageIndex--;
        if (al::isPadTriggerRight(-1)) pageIndex++;
        if(pageIndex < 0) {
            pageIndex = maxPages - 1;
        }
        if(pageIndex >= maxPages) pageIndex = 0;

    } else if (al::isPadHoldZL(-1)) {

        if (debugMode) {
            if (al::isPadTriggerLeft(-1)) debugPuppetIndex--;
            if (al::isPadTriggerRight(-1)) debugPuppetIndex++;

            if(debugPuppetIndex < 0) {
                debugPuppetIndex = Client::getMaxPlayerCount() - 2;
            }
            if (debugPuppetIndex >= Client::getMaxPlayerCount() - 1)
                debugPuppetIndex = 0;
        }

    } else if (al::isPadHoldL(-1)) {
        if (al::isPadTriggerLeft(-1)) GameModeManager::instance()->toggleActive();
        if (al::isPadTriggerRight(-1)) {
            if (debugMode) {
                
                PuppetInfo* debugPuppet = Client::getDebugPuppetInfo();
                
                if (debugPuppet) {

                    debugPuppet->playerPos = al::getTrans(playerBase);
                    al::calcQuat(&debugPuppet->playerRot, playerBase);

                    PlayerHackKeeper* hackKeeper = playerBase->getPlayerHackKeeper();

                    if (hackKeeper) {
                        const char *hackName = hackKeeper->getCurrentHackName();
                        debugPuppet->isCaptured = hackName != nullptr;
                        if (debugPuppet->isCaptured) {
                            strcpy(debugPuppet->curHack, hackName);
                        } else {
                            strcpy(debugPuppet->curHack, "");
                        }
                    }
                    
                }
            }
        }
        if (al::isPadTriggerUp(-1)) {
            if (debugMode) {
                PuppetActor* debugPuppet = Client::getDebugPuppet();
                if (debugPuppet) {
                    PuppetInfo *info = debugPuppet->getInfo();
                    // info->isIt = !info->isIt;

                    debugPuppet->emitJoinEffect();
                    
                }
            } else {
                isDisableMusic = !isDisableMusic;
            }
        }
    }

    if (isDisableMusic) {
        if (al::isPlayingBgm(stageScene)) {
            al::stopAllBgm(stageScene, 0);
        }
    }

    return isFirstStep;

}

void seadPrintHook(const char *fmt, ...)
{
    va_list args;
	va_start(args, fmt);

    Logger::log(fmt, args);

    va_end(args);
}



bool tryChangeNextStageHijack(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo, int n) {
    Client::setDebugAmount(n);
    return GameDataFunction::tryChangeNextStage(thisPtr, changeStageInfo);
}

bool tryChangeNextStageHijack1(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 1);
}
bool tryChangeNextStageHijack2(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 2);
}
bool tryChangeNextStageHijack3(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 3);
}
bool tryChangeNextStageHijack4(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 4);
}
bool tryChangeNextStageHijack5(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 5);
}
bool tryChangeNextStageHijack6(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 6);
}
bool tryChangeNextStageHijack7(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 7);
}
bool tryChangeNextStageHijack8(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 8);
}
bool tryChangeNextStageHijack9(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 9);
}
bool tryChangeNextStageHijack10(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 10);
}
bool tryChangeNextStageHijack11(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 11);
}
bool tryChangeNextStageHijack12(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 12);
}
bool tryChangeNextStageHijack13(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 13);
}
bool tryChangeNextStageHijack14(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 14);
}
bool tryChangeNextStageHijack15(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 15);
}
bool tryChangeNextStageHijack16(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 16);
}
bool tryChangeNextStageHijack17(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 17);
}
bool tryChangeNextStageHijack18(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 18);
}
bool tryChangeNextStageHijack19(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 19);
}
bool tryChangeNextStageHijack20(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 20);
}
bool tryChangeNextStageHijack21(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 21);
}
bool tryChangeNextStageHijack22(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 22);
}
bool tryChangeNextStageHijack23(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 23);
}
bool tryChangeNextStageHijack24(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 24);
}
bool tryChangeNextStageHijack25(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 25);
}
bool tryChangeNextStageHijack26(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 26);
}
bool tryChangeNextStageHijack27(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 27);
}
bool tryChangeNextStageHijack28(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 28);
}
bool tryChangeNextStageHijack29(GameDataHolderWriter thisPtr, const ChangeStageInfo *changeStageInfo) {
    return tryChangeNextStageHijack(thisPtr, changeStageInfo, 29);
}

void changeNextStageHijack(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i, int n) {
    Client::setDebugAmount(n);
    thisPtr->changeNextStage(changeStageInfo, i);
}

void changeNextStageHijack30(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 30);
}

void changeNextStageHijack31(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 31);
}

void changeNextStageHijack32(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 32);
}

void changeNextStageHijack33(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 33);
}

void changeNextStageHijack34(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 34);
}

void changeNextStageHijack35(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 35);
}

void changeNextStageHijack36(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 36);
}

void changeNextStageHijack37(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 37);
}

void changeNextStageHijack38(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 38);
}

void changeNextStageHijack39(GameDataHolder *thisPtr, const ChangeStageInfo *changeStageInfo, int i) {
    changeNextStageHijack(thisPtr, changeStageInfo, i, 39);
}