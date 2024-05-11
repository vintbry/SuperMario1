//
// Created by Felicia Rulita on 2024/5/9.
//
#include "FirstWorldOne.h"
#include <iostream>

FirstWorldOne::FirstWorldOne() {
    m_CurrentState = State::START;
}

void FirstWorldOne::End(App *app) {
    app->m_Root.RemoveAllChildren();
    SetState(State::EXIT);
}

void FirstWorldOne::Restart(App *app) {
    std::cout<<"msk restart"<<std::endl;
    app->m_Root.RemoveAllChildren();

    pressed1 =  false ;
    pressed2 = false;

    speed=2;
    powerjump =0.0f;
    t =0;

    m_BGMusic = nullptr;

    m_Mario_jump_audio = nullptr;
    m_Mario_dead_audio = nullptr;
    m_Mario_coin_audio = nullptr;
    m_Mario_stomp_audio = nullptr;
    m_Mario_bump_audio = nullptr;
    m_Mario_levelFinish_audio = nullptr;
    m_Mario_flagpole_audio = nullptr;

    m_title = nullptr;

    m_score = nullptr;
    m_coin = nullptr;
    m_world = nullptr;
    m_time = nullptr;
    m_popup = nullptr;

    m_Bg = nullptr;

    m_Bg2 = nullptr;
    m_Pillar = nullptr;
    m_Flag = nullptr;


    m_DeadQues.clear();
    m_Land.clear();
    m_Brick.clear();
    m_Tube.clear();
    m_Wood.clear();
    m_Castle.clear();

    m_YellowMushVec.clear();

    m_KoopaVec.clear();

    m_QuesVector.clear();

    m_Question = nullptr;

    m_MushVector.clear();

    m_Mario = nullptr;
    m_MarioPillar = nullptr;
    m_MarioBack = nullptr;

    m_Mushroom = nullptr;

    m_YellowMush = nullptr;

    m_Coins = nullptr;

    m_Koopa = nullptr;


    position = {0.0f,0.0f};
    positionLand = {0.0f,0.0f};

    m_PRM = nullptr;

    MarioRun.clear();
    MarioRunLvl2.clear();
    MarioRunBack.clear();
    MarioRunBackLvl2.clear();
    MarioPillar.clear();
    MarioShrink.clear();
    Mushroom1.clear();
    QuestionMark.clear();
    Coins.clear();
    KoopaPic.clear();
    levelUp.clear();
    levelUpBack.clear();
    MarioBigFront.clear();
    MarioBigBack.clear();
    MarioJump.clear();
    MarioJumpBack.clear();
    MarioJumpLvl2.clear();
    MarioJumpBackLvl2.clear();
    YellowMushroom.clear();
    MarioPillarEnd.clear();

    index=0;
    index2=0;
    indexTiles = 0;
    indexTiles2 = 0;
    indexMush = 0;
    countBlinkTime = 0;
    BlinkTime = 0;

    slideTime=0;
    SpeedInAir=0;
    y0= -172.0f;
    h=0 ;
    max_jump=0;

    cnt=0;
    cnts=0;
    time=1000 ;
    score=0 ;
    coin=0;

    timenow = 0;
    m_JumpBaseTime = 0;
    m_MarioDiesTime = 0;
    m_MarioStepTime = 0;
    m_MarioHeadTime = 0;
    m_MarioHeadTime2 = 0;
    m_MarioHeadTime_yelmush = 0;
    m_MarioShrinkTime = 0;

    m_EnterDown = false;
    m_EnterRight = true;
    m_EnterLeft = false;
    m_Collide = false;
    isBrick = true;
    isWinLevel = false;
    winSong = false;
    leftSlide = false;
    rightSlide = false;
    pressUp = false;

    SetState(State::START);
}