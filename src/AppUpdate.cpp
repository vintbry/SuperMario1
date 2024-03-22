//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "AnimatedCharacter.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

void App::callMarioForward(){
    m_Mario->SetVisible(true);
    m_Mario->SetLooping(false);
    m_Mario->SetPlaying();
}

void App::callMarioBackward(){
    m_MarioBack->SetVisible(true);
    m_MarioBack->SetLooping(false);
    m_MarioBack->SetPlaying();
}

void App::Update(){
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        //when mario jump he can also go to the right
        m_MarioBack->SetVisible(false);
        callMarioForward();
        if(m_Mario1->m_Jump){
            //mario only can run until the middle
            //else is the elements that move
            m_Mario->SetVisible(false);
            if(m_Mario1->GetPosition().x < 13.0f){
                m_Mario1->SetPosition({m_Mario1->GetPosition().x+3.0f,m_Mario1->GetPosition().y});
            }
            else{
                m_Mario1->SetPosition(m_Mario1->GetPosition());
            }

            m_Mario->SetPosition(m_Mario1->GetPosition());
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
        }
        //if not jumping than run
        else{
            callMarioForward();
            if(m_Mario->GetPosition().x < 13.0f){
                m_Mario->SetPosition({m_Mario->GetPosition().x+3.0f,m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }

            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }

        if(m_Mario1->GetPosition().x == 14.0f){
            m_Mushroom->SetPosition({m_Mushroom->GetPosition().x-3.0f, m_Mushroom->GetPosition().y});
        }

    }
    if(Util::Input::IsKeyDown(Util::Keycode::UP) && !m_Mario1->m_Jump){
        glm::vec2 newPos = m_Mario->GetPosition();

        m_Mario1->SetPosition(newPos);

        m_JumpBaseTime=Util::Time::GetElapsedTimeMs();
        LOG_DEBUG("Base");
        //LOG_DEBUG(BaseTime);
        m_Mario1->SetVisible(true);
        m_Mario1->Jump(m_JumpBaseTime);

        if(m_Mario->GetVisibility()){
            m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
        }
        else if (m_MarioBack->GetVisibility()){
            m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
        }
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);

    }
    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT)){

        callMarioBackward();
        m_Mario1->SetVisible(false);
        m_Mario->SetVisible(false);
        m_MarioBack->SetPosition({m_Mario1->GetPosition().x-3.0f, m_Mario1->GetPosition().y});

        m_Mario->SetPosition(m_MarioBack->GetPosition());
        m_Mario1->SetPosition(m_MarioBack->GetPosition());

        //when mario jump he can also go to the left
        m_Mario->SetVisible(false);
        callMarioBackward();
        if(m_Mario1->m_Jump){
            m_MarioBack->SetVisible(false);
        }
        else{
            callMarioBackward();
        }
        m_Mario->SetPosition(m_Mario1->GetPosition());
        m_MarioBack->SetPosition(m_Mario1->GetPosition());

    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;

    }
    LOG_DEBUG("Mariopos");
    LOG_DEBUG(m_Mario1->GetPosition().x);
    //jumping mario!
    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+5.0f});
        m_Mario1->Jump(m_JumpBaseTime);
    }
    else if (m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        if(m_Mario1->GetPosition().y>m_Mario1->GetLandPosition().y)
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y-5.0f});
        else{
            m_Mario1->m_Jump=false;

            if(m_Mario1->GetImagePath()==GA_RESOURCE_DIR"/Mario/mario_jump.png"){
                m_Mario1->SetVisible(false);
                m_Mario->SetVisible(true);
            }
            else if(m_Mario1->GetImagePath()==GA_RESOURCE_DIR"/Mario/mario_jumpBack.png"){
                m_Mario1->SetVisible(false);
                m_MarioBack->SetVisible(true);
            }

            m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario->SetPosition(m_Mario1->GetPosition());
        }
    }

    //update m_Time



    //moving mushroom


    /*
    //change Mario Image
    if(m_Mario->m_Jump){
        m_Mario->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    }
    */
    //m_Mario->SetPosition({m_Mario->GetPosition().x + 3.0f, m_Mario->GetPosition().y});
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}