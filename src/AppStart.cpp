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


    m_Mario1 = std::make_shared<Character>(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    m_Mario1->SetZIndex(50);
    m_Mario1->SetVisible(false);
    m_Root.AddChild(m_Mario1);


    std::vector<std::string> MarioJump;
    MarioJump.reserve(3);
    for(int i = 0; i < 3; i++){
        MarioJump.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }

    m_Mario= std::make_shared<AnimatedCharacter>(MarioJump);
    m_Mario->SetPosition({-400.0f, -200.5f});
    m_Mario->SetInterval(100);
    m_Mario->SetZIndex(5);
    m_Mario->SetVisible(true);
    m_Root.AddChild(m_Mario);

    m_PRM = std::make_shared<PhaseResourcesManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

    LOG_DEBUG("start!");

    m_CurrentState=State::UPDATE;

}