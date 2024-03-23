//
// Created by Felicia Rulita on 2024/3/12.
//

#include "AnimatedCharacter.h"
#include "App.h"

#include "Character.h"
#include "Util/Logger.hpp"
#include "PhaseResourcesManager.h"


void App::Start(){
    LOG_TRACE("Start!");

    //Mario Jump forward
    m_Mario1 = std::make_shared<Character>(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    m_Mario1->SetZIndex(50);
    m_Mario1->SetVisible(false);
    m_Root.AddChild(m_Mario1);

    //Mario Jump Backward
    /*
    m_Mario2 = std::make_shared<Character>(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
    m_Mario2->SetZIndex(50);
    m_Mario2->SetVisible(false);
    m_Root.AddChild(m_Mario2);
    */
    //Mario run forward
    std::vector<std::string> MarioRun;
    MarioRun.reserve(4);
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move2.png");
    for(int i = 0; i < 3; i++){
        MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }


    m_Mario= std::make_shared<AnimatedCharacter>(MarioRun);
    m_Mario->SetPosition({-300.0f, -172.0f});
    m_Mario->SetInterval(100);
    m_Mario->SetZIndex(5);
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
    m_MarioBack->SetZIndex(5);
    m_MarioBack->SetVisible(false);
    m_Root.AddChild(m_MarioBack);

    //try moving element
    m_Mushroom = std::make_shared<Character>(GA_RESOURCE_DIR"/images/goombas_0.png");
    m_Mushroom->SetPosition({200.0f,-200.5f});
    m_Mushroom->SetZIndex(5);
    m_Mushroom->SetVisible(true);
    m_Root.AddChild(m_Mushroom);

    //Background tiles
    //none in the 41,40
    std::vector <int> vec = {45};

    for(int i = 0;i < 300 ;i++){
        auto it = find(vec.begin(), vec.end(), i);
        m_Land.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tiles2.png"));

        if (it != vec.end()){
            LOG_DEBUG("msk");
            m_Land[i]->SetPosition({-345.0f + (32.0f * float(i)), -300.0f});
        }
        else{
            m_Land[i]->SetPosition({-345.0f + (32.0f * float(i)),-218.0f});
        }
        m_Land[i]->SetZIndex(5);
        m_Land[i]->SetVisible(true);
        LOG_DEBUG(i);


        m_Root.AddChild(m_Land[i]);
    }

    //In Air Tile
    //Question Mark
    std::vector<std::string> QuestionMark;
    QuestionMark.reserve(3);
    for(int i = 0;i < 3; i++){
        QuestionMark.emplace_back(GA_RESOURCE_DIR"/images/question"+std::to_string(i)+".png");
    }

    m_Question = std::make_shared<AnimatedCharacter>(QuestionMark);
    m_Question->SetLooping(true);
    m_Question->SetPlaying();
    m_Question->SetZIndex(5);
    m_Question->SetVisible(true);

    for(int i=0;i<13;i++){
        m_QuesVector.push_back(m_Question);
        m_QuesVector[i]->SetZIndex(5);
        m_QuesVector[i]->SetVisible(true);
        //should define the position one by one
        m_Root.AddChild(m_QuesVector[i]);
    }

    //defining question position
    m_QuesVector[0]->SetPosition({160.0f,-100.0f});

    //putting type of tiles into the vector
    saveTilesChar.push_back(m_Land);

    saveTilesAnimated.push_back(m_QuesVector);


    m_PRM = std::make_shared<PhaseResourcesManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

    m_CurrentState=State::UPDATE;

}