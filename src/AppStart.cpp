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
    for(int i = 0; i < 3; i++){
        MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move2.png");

    m_Mario= std::make_shared<AnimatedCharacter>(MarioRun);
    m_Mario->SetPosition({-400.0f, -200.5f});
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
    m_MarioBack->SetPosition({-400.0f, -200.5f});
    m_MarioBack->SetInterval(100);
    m_MarioBack->SetZIndex(5);
    m_MarioBack->SetVisible(false);
    m_Root.AddChild(m_MarioBack);

    //try moving element
    m_Mushroom = std::make_shared<Character>(GA_RESOURCE_DIR"/images/goombas_0.png");
    m_Mushroom->SetPosition({2000.0f,-200.5f});
    m_Mushroom->SetZIndex(5);
    m_Mushroom->SetVisible(true);
    m_Root.AddChild(m_Mushroom);

    m_PRM = std::make_shared<PhaseResourcesManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

    m_CurrentState=State::UPDATE;

}