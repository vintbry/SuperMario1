//
// Created by Felicia Rulita on 2024/3/12.
//

#include "AnimatedCharacter.h"
#include "App.h"
#include "Character.h"
#include "Util/SFX.hpp"
#include "Util/Logger.hpp"
#include "PhaseResourcesManager.h"


void App::Start(){
    LOG_TRACE("Start!");
    //Mario Jump
    m_Mario1 = std::make_shared<Character>(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    m_Mario1->SetZIndex(50);
    m_Mario1->SetVisible(false);
   // m_audio_mario_small_jump.LoadMedia(GA_RESOURCE_DIR"/Audio/small_mario_jump.wav");


    m_Root.AddChild(m_Mario1);

    //Mario run forward
    std::vector<std::string> MarioRun;
    MarioRun.reserve(4);
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move2.png");
    for(int i = 0; i < 3; i++){
        MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }


    m_Mario= std::make_shared<AnimatedCharacter>(MarioRun);
    m_Mario->SetPosition({-300.0f, -168.0f});
    m_Mario->SetInterval(100);
    m_Mario->SetZIndex(50);
    m_Mario->SetVisible(true);
    m_Root.AddChild(m_Mario);

    //Mario run backward
    std::vector<std::string> MarioRunBack;
    MarioRunBack.reserve(3);
    for(int i=0; i < 3; i++){
        MarioRunBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+std::to_string(i)+"_back.png");
    }
    MarioRunBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move2_back.png");

    m_MarioBack = std::make_shared<AnimatedCharacter>(MarioRunBack);
    m_MarioBack->SetInterval(100);
    m_MarioBack->SetZIndex(50);
    m_MarioBack->SetVisible(false);
    m_Root.AddChild(m_MarioBack);

    //try moving element
    m_Mushroom = std::make_shared<Character>(GA_RESOURCE_DIR"/images/goombas_0.png");
    m_Mushroom->SetPosition({200.0f,-200.5f});
    m_Mushroom->SetZIndex(50);
    m_Mushroom->SetVisible(true);
    m_Root.AddChild(m_Mushroom);

    //Background tiles
    for(int i = 0; i < 4; i++){
        m_Land.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tilesLong"+std::to_string(i)+".png"));
        m_Land[i]->SetZIndex(5);
        m_Land[i]->SetVisible(true);
        m_Root.AddChild(m_Land[i]);
    }
    m_Land[0]->SetPosition({740.0f,-220.0f});
    m_Land[1]->SetPosition({2150.0f,-220.0f});
    m_Land[2]->SetPosition({3538.0f,-220.0f});
    m_Land[3]->SetPosition({5746.0f,-220.0f});

    //In Air Tile
    //Question Mark
    std::vector<std::string> QuestionMark;
    QuestionMark.reserve(3);
    for(int i = 0;i < 3; i++){
        QuestionMark.emplace_back(GA_RESOURCE_DIR"/images/question"+std::to_string(i)+".png");
    }

    for(int i=0;i<14;i++){
        m_Question = std::make_shared<AnimatedCharacter>(QuestionMark);
        m_Question->SetLooping(true);
        m_Question->SetPlaying();
        m_Question->SetZIndex(5);
        m_Question->SetVisible(true);
        m_QuesVector.push_back(m_Question);

        m_QuesVector[i]->SetZIndex(5);
        m_QuesVector[i]->SetVisible(true);


    }
    //set position
    m_QuesVector[0]->SetPosition({163.0f,-82.0f});
    m_QuesVector[1]->SetPosition({323.0f,-82.0f});
    m_QuesVector[2]->SetPosition({355.0f,40.0f});
    m_QuesVector[3]->SetPosition({387.0f,-82.0f});
    m_QuesVector[4]->SetPosition({1696.0f,-82.0f});

    m_QuesVector[5]->SetPosition({2144.0f,-82.0f});

    m_QuesVector[6]->SetPosition({2675.0f,40.0f});
    m_QuesVector[7]->SetPosition({3059.0f,-82.0f});
    m_QuesVector[8]->SetPosition({3155.0f,-82.0f});
    m_QuesVector[9]->SetPosition({3155.0f,40.0f});
    m_QuesVector[10]->SetPosition({3251.0f,-82.0f});
    m_QuesVector[11]->SetPosition({3795.0f,40.0f});
    m_QuesVector[12]->SetPosition({3827.0f,40.0f});
    m_QuesVector[13]->SetPosition({5139.0f,-82.0f});

    for(int i=0;i<14;i++){
        m_Root.AddChild(m_QuesVector[i]);
    }

    //brick
    for(int i = 0;i<30;i++){
        m_Brick.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/inAir1.png"));
        m_Brick[i]->SetZIndex(5);
        m_Brick[i]->SetVisible(true);
        m_Root.AddChild(m_Brick[i]);
    }
    m_Brick[0]->SetPosition({291.0f,-82.0f});
    m_Brick[1]->SetPosition({355.0f,-82.0f});
    m_Brick[2]->SetPosition({419.0f,-82.0f});
    m_Brick[3]->SetPosition({2112.0f,-82.0f});
    m_Brick[4]->SetPosition({2176.0f,-82.0f});
    m_Brick[5]->SetPosition({2208.0f,40.0f});
    m_Brick[6]->SetPosition({2240.0f,40.0f});
    m_Brick[7]->SetPosition({2272.0f,40.0f});
    m_Brick[8]->SetPosition({2304.0f,40.0f});
    m_Brick[9]->SetPosition({2336.0f,40.0f});
    m_Brick[10]->SetPosition({2368.0f,40.0f});
    m_Brick[11]->SetPosition({2400.0f,40.0f});
    m_Brick[12]->SetPosition({2432.0f,40.0f});
    m_Brick[13]->SetPosition({2464.0f,40.0f});

    m_Brick[14]->SetPosition({2579.0f,40.0f});
    m_Brick[15]->SetPosition({2611.0f,40.0f});
    m_Brick[16]->SetPosition({2643.0f,40.0f});
    m_Brick[17]->SetPosition({2675.0f,-82.0f});
    m_Brick[18]->SetPosition({2867.0f,-82.0f});
    m_Brick[19]->SetPosition({2899.0f,-82.0f});
    m_Brick[20]->SetPosition({3443.0f,-82.0f});
    m_Brick[20]->SetPosition({3539.0f,40.0f});
    m_Brick[21]->SetPosition({3571.0f,40.0f});
    m_Brick[22]->SetPosition({3763.0f,40.0f});
    m_Brick[23]->SetPosition({3859.0f,40.0f});
    m_Brick[24]->SetPosition({3795.0f,-82.0f});
    m_Brick[25]->SetPosition({3827.0f,-82.0f});
    m_Brick[26]->SetPosition({5075.0f,-82.0f});
    m_Brick[27]->SetPosition({5107.0f,-82.0f});
    m_Brick[28]->SetPosition({5171.0f,-82.0f});

    m_Brick[29]->SetPosition({291.0f,-170.0f});

    for(int i = 0;i<30;i++){
        m_Root.AddChild(m_Brick[i]);
    }
    //Tube
    /*
    for(int i=0;i<1;i++){
        m_Tube.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tube.png"));
        m_Tube[i]->SetZIndex(2);
        m_Tube[i]->SetVisible(true);

    }
    m_Tube[0]->SetPosition({565.0f,-380.0f});

    for(int i=0;i<1;i++){
        m_Root.AddChild(m_Tube[i]);
    }
     */

    m_PRM = std::make_shared<PhaseResourcesManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

    m_CurrentState=State::UPDATE;

}