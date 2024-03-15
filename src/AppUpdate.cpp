//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "AnimatedCharacter.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

void App::Update(){
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        if(m_Mario1->m_Jump){
            LOG_DEBUG("yes");
            m_Mario1->SetPosition({m_Mario1->GetPosition().x+3.0f,m_Mario1->GetPosition().y});
            m_Mario->SetPosition(m_Mario1->GetPosition());
        }
        else{
            m_Mario->SetLooping(false);
            m_Mario->SetPlaying();
            m_Mario->SetPosition({m_Mario->GetPosition().x+3.0f, m_Mario->GetPosition().y});
            m_Mario1->SetPosition(m_Mario->GetPosition());
        }

    }
    else if(Util::Input::IsKeyUp(Util::Keycode::UP) && !m_Mario1->m_Jump){
        glm::vec2 newPos = m_Mario->GetPosition();

        m_Mario1->SetPosition(newPos);
        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        m_JumpBaseTime=Util::Time::GetElapsedTimeMs();
        LOG_DEBUG("Base");
        //LOG_DEBUG(BaseTime);
        m_Mario1->Jump(m_JumpBaseTime);

    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;

    }
    LOG_DEBUG("Mariopos");
    LOG_DEBUG(m_Mario1->GetPosition().y);
    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+3.0f});
        m_Mario1->Jump(m_JumpBaseTime);
    }
    else if (m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        if(m_Mario1->GetPosition().y>m_Mario1->GetLandPosition().y)
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y-3.0f});
        else{
            m_Mario1->m_Jump=false;
            m_Mario1->SetVisible(false);
            m_Mario->SetVisible(true);
            m_Mario->SetPosition(m_Mario1->GetPosition());
        }
    }
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