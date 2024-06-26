//
// Created by Felicia Rulita on 2024/5/7.
//
#include "App.h"
#include "MenuPhase.h"
#include "BeginningPhase.h"
#include "FirstWorldOne.h"
#include <iostream>

App::App(Phases Phase){
    m_Phase = Phase;
    m_CurrentPhase = std::make_shared<MenuPhase>();
}

void App::ChangePhase(Phases phase) {
    std::cout<<"change phase"<<std::endl;
    if(phase == Phases::MENU){
        m_CurrentPhase = std::make_shared<MenuPhase>();
    }
    else if(phase == Phases::BEGINNING){
        std::cout<<"change to beginning"<<std::endl;
        m_CurrentPhase = std::make_shared<BeginningPhase>();
        std::cout<<"success change to beginning"<<std::endl;
    }
    else if(phase == Phases::FIRST_WORLD_ONE){
        m_CurrentPhase = std::make_shared<FirstWorldOne>();
    }

}

void App::Update(){
    if(m_CurrentPhase){
        if(m_CurrentPhase->GetCurrentState() == Phase::State::START ) {
            m_CurrentPhase->Start(this);
        }
        else if(m_CurrentPhase->GetCurrentState() == Phase::State::UPDATE){
            m_CurrentPhase->Update(this);
        }
        else if(m_CurrentPhase->GetCurrentState() == Phase::State::END){
            m_CurrentPhase->End(this);
        }
    }
}

void App::SetPhase(Phases phase){
    m_Phase = phase;
}