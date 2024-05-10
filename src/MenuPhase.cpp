//
// Created by Felicia Rulita on 2024/5/7.
//
#include "MenuPhase.h"
#include <iostream>

MenuPhase::MenuPhase(){
    m_CurrentState = State::START;
}

void MenuPhase::Start(App *app) {
    m_Bg = std::make_shared<BackgroundImage>(GA_RESOURCE_DIR"/Background/PhaseMenu.png");

    app->m_Root.AddChild(m_Bg);
    app->m_Root.Update();
    SetState(State::UPDATE);
}

void MenuPhase::Update(App *app) {
    app->m_Root.Update();
    if(Util::Input::IsKeyDown(Util::Keycode::ESCAPE)){
        SetState(State::END);
    }
    else if(Util::Input::IsKeyDown(Util::Keycode::RETURN)){
        app->m_CurrentPhase = nullptr;
        std::cout<<"change to begin";
        if(m_Bg){
            std::cout<<"mbg not null";
        }
        else{
            std::cout<<"mbg null";
        }
        app->SetPhase(App::Phases::BEGINNING);
        std::cout<<"set phase success";
        app->ChangePhase(App::Phases::BEGINNING);
    }
}

void MenuPhase::End(App *app){
    std::cout<<"end"<<std::endl;
    m_Bg = nullptr;
    app->m_Root.RemoveAllChildren();
    SetState(State::EXIT);
}
