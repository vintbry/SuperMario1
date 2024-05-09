//
// Created by Felicia Rulita on 2024/5/8.
//
#include "BeginningPhase.h"
#include <iostream>

BeginningPhase::BeginningPhase(){
    m_CurrentState = State::START;
}

void BeginningPhase::Start(App *app){
    std::cout<<"beginning"<<std::endl;

    m_Bg = std::make_shared<BackgroundImage>(GA_RESOURCE_DIR"/Background/PhaseBeginning.png");

    std::cout<<"success change bg"<<std::endl;
    app->m_Root.AddChild(m_Bg);
    app->m_Root.Update();
    SetState(State::UPDATE);
}

void BeginningPhase::Update(App *app){
    app->m_Root.Update();
    if(Util::Input::IsKeyDown(Util::Keycode::ESCAPE)){
        SetState(State::END);
    }
    else if(Util::Input::IsKeyDown(Util::Keycode::RETURN)){
        app->SetPhase(App::Phases::FIRST_WORLD_ONE);
        app->ChangePhase(App::Phases::FIRST_WORLD_ONE);
    }
}

void BeginningPhase::End(App *app) {
    m_Bg = nullptr;
    app->m_Root.RemoveAllChildren();
    SetState(State::EXIT);
}
