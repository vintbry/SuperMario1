//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

void App::moveQuestionBox() {
    //after inputting all the flying object, should use this
    for(int i=0;i<m_QuesVector.size();i++){
        m_QuesVector[i]->SetPosition({m_QuesVector[i]->GetPosition().x-5.0f, m_QuesVector[i]->GetPosition().y});
    }

    //m_QuesVector[0]->SetPosition({m_QuesVector[0]->GetPosition().x-5.0f, m_QuesVector[0]->GetPosition().y});
}

void App::moveBrick() {
    //after inputting all the flying object, should use this
    for(int i=0;i<m_Brick.size();i++){
        m_Brick[i]->SetPosition({m_Brick[i]->GetPosition().x-5.0f, m_Brick[i]->GetPosition().y});
    }

    //m_QuesVector[0]->SetPosition({m_QuesVector[0]->GetPosition().x-5.0f, m_QuesVector[0]->GetPosition().y});
}

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

std::tuple<bool,glm::vec2 > App::IsOnLand(){
    for(int i=0;i<m_Land.size();i++){
        auto tiles = m_Land[i];
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x-((tiles->GetScaledSize().x)/2));
        bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));

        if((collideX) && (collideY)){
            return {true,m_Mario->GetPosition()};
        }
    }

    for(int i=0;i<m_QuesVector.size();i++){
        auto tiles = m_QuesVector[i];
        //for(int j=0;j<tiles.size();j++){
            bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x+10.0f)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x-5.0f);
            bool collideY = m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y;

            if((collideX) && (collideY)){
                return {true,m_Mario->GetPosition()};
            }

    }
    for(int i=0;i<m_Brick.size();i++){
        auto tiles = m_Brick[i];
        //for(int j=0;j<tiles.size();j++){
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x+10.0f)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x-5.0f);
        bool collideY = m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y;

        if((collideX) && (collideY)){
            return {true,m_Mario->GetPosition()};
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        auto tiles = m_Tube[i];
        //for(int j=0;j<tiles.size();j++){
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x+10.0f)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x-5.0f);
        bool collideY = m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y;

        if((collideX) && (collideY)){
            return {true,m_Mario->GetPosition()};
        }

    }

    return {false,m_Mario->GetPosition()};
}

bool App::IsCollide(){
    for(int i=0;i<m_QuesVector.size();i++){
        auto object = m_QuesVector[i];
        if(m_Mario1->IfCollides(object)){
            m_Collide = true;
            return m_Collide;
        }
    }
    for(int i=0;i<m_Brick.size();i++){
        auto object = m_Brick[i];
        if(m_Mario1->IfCollides(object)){
            m_Collide = true;
            return m_Collide;
        }
    }
    for(int i=0;i<m_Tube.size();i++){
        auto object = m_Tube[i];
        LOG_DEBUG("tube");
        LOG_DEBUG(object->GetPosition().x);
        LOG_DEBUG(object->GetPosition().y);
        if(m_Mario1->IfCollides(object)){
            LOG_DEBUG("msk");
            m_Collide = true;
            return m_Collide;
        }
    }
    m_Collide = false;
    return m_Collide;
}

void App::Update(){
    timenow = Util::Time::GetElapsedTimeMs();
    if(std::get<0>(IsOnLand()) && !m_Mario1->m_Jump){
        //if on land then run
        position = std::get<1>(IsOnLand());

        if(m_EnterRight){
            m_Mario->SetVisible(true);
        }
        else{
            m_MarioBack->SetVisible(true);
        }
        m_Mario1->SetVisible(false);

        m_Mario->SetPosition(position);
        m_Mario1->SetPosition(position);
        m_MarioBack->SetPosition(position);
    }
    else{
        //make mario always fall is not on land
        if(!m_Mario1->m_Jump){
            m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->GetPosition().y-5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }

    }

    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        m_EnterRight = true;
        //when mario jump he can also go to the right
        m_MarioBack->SetVisible(false);
        callMarioForward();

        if(m_Mario1->m_Jump){
            //change picture from running to jumping
            m_Mario->SetVisible(false);
            m_Mario1->SetVisible(true);
            //mario only can run until the middle
            //else is the elements that move


            //if(!IsCollide()){
                if(m_Mario1->GetPosition().x < 13.0f){
                    m_Mario1->SetPosition({m_Mario1->GetPosition().x+1.5f,m_Mario1->GetPosition().y});
                }
            //}

            m_Mario->SetPosition(m_Mario1->GetPosition());
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
        }
        //if not jumping than run
        else{
            callMarioForward();
            m_Mario1->SetVisible(false);
            //mario only can run until the middle
            //else is the elements that move
            //if(!IsCollide()){
                if(m_Mario->GetPosition().x < 13.0f){
                    m_Mario->SetPosition({m_Mario->GetPosition().x+5.0f,m_Mario->GetPosition().y});
                }

            //}

            //renew the other's position
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        //if mario more than middle than the background move
        if(m_Mario->GetPosition().x >= 13.0f && !IsCollide()){
            m_Mushroom->SetPosition({m_Mushroom->GetPosition().x-5.0f, m_Mushroom->GetPosition().y});
            //NEED TO EDIT!
            for(int i=0; i<m_Land.size(); i++){
                m_Land[i]->SetPosition({m_Land[i]->GetPosition().x-5.0f,m_Land[i]->GetPosition().y});
            }
            for(int j=0; j<m_Tube.size(); j++){
                m_Tube[j]->SetPosition({m_Tube[j]->GetPosition().x-5.0f,m_Tube[j]->GetPosition().y});
            }
            moveQuestionBox();
            moveBrick();
        }

    }

    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT)){
        m_EnterRight = false;
        callMarioBackward();
        //make other invisible
        m_Mario1->SetVisible(false);
        m_Mario->SetVisible(false);

        //when mario jump he can also go to the left
        if(m_Mario1->m_Jump){
            if(m_MarioBack->GetPosition().x > -340.0f){
                m_MarioBack->SetPosition({m_Mario1->GetPosition().x-1.5f, m_Mario1->GetPosition().y});
            }
            else{
                m_MarioBack->SetPosition(m_Mario1->GetPosition());
            }

            //renew position
            m_Mario->SetPosition(m_MarioBack->GetPosition());
            m_Mario1->SetPosition(m_MarioBack->GetPosition());
            m_MarioBack->SetVisible(false);
            m_Mario1->SetVisible(true);
        }
        else{ //if not jump
            callMarioBackward();
            if(m_MarioBack->GetPosition().x > -340.0f){
                m_MarioBack->SetPosition({m_Mario->GetPosition().x-5.0f, m_Mario->GetPosition().y});
            }
            else{
                m_MarioBack->SetPosition(m_Mario->GetPosition());
            }

            //renew position
            m_Mario->SetPosition(m_MarioBack->GetPosition());
            m_Mario1->SetPosition(m_MarioBack->GetPosition());
        }
        //renew position
        m_Mario->SetPosition(m_Mario1->GetPosition());
        m_MarioBack->SetPosition(m_Mario1->GetPosition());

    }

    if(Util::Input::IsKeyUp(Util::Keycode::UP)){
        cnt=0;
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        cnt++;
    }

    unsigned int cnts= cnt/2.0;
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario1->m_Jump){
        glm::vec2 newPos = m_Mario->GetPosition();

        m_JumpBaseTime=Util::Time::GetElapsedTimeMs();
        m_Mario1->SetPosition(newPos);
        m_Mario1->SetVisible(true);

        m_Mario1->Jump(m_JumpBaseTime);

        //change the jump mario picture
        if(m_Mario->GetVisibility()){
            m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
        }
        else if (m_MarioBack->GetVisibility()){
            m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
        }
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);

    }

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;

    }
    LOG_DEBUG("Mariopos");
    LOG_DEBUG(m_Mario1->GetPosition().x);
    LOG_DEBUG(m_Mario1->GetPosition().y);

    /*
    //jumping mario!
    if(m_Mario1->m_Jump && IsCollide()){
        m_Mario1->m_HasEnded=true;
        m_Mario1->m_maxJump=true;
    }

    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        //unsigned gravity = (timeNow - m_JumpBaseTime) / 100;

        //if not maxJump yet
        if(m_Mario1->GetPosition().y < m_Mario1->GetLandPosition().y+200.0f){
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+5.0f});
            //m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+(6.0-gravity)});
            m_Mario->SetPosition(m_Mario1->GetPosition());
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario1->Jump(m_JumpBaseTime);
            m_Mario1->m_maxJump=false;
        }
        else{ //max jump than go down

            m_Mario1->m_HasEnded=true;
            m_Mario1->m_maxJump=true;
        }
    }

    if (m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        m_Mario1->m_Jump=false;
        m_Mario1->m_maxJump=false;

        m_MarioBack->SetPosition(m_Mario1->GetPosition());
        m_Mario->SetPosition(m_Mario1->GetPosition());
    }
    */
    //change mario picture if fall
    if(!std::get<0>(IsOnLand()) && !m_Mario1->m_Jump){
        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);
    }

    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        float powerjump = (timenow - m_JumpBaseTime)/100;
        if (cnts>4)cnts =4.0;
        m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+((5.0+cnts)-powerjump)});
        m_Mario1->Jump(m_JumpBaseTime);
    }
    else if (m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        float gravity = (timenow - m_JumpBaseTime)/200;
        if (gravity>5) gravity=5.0;
        if(m_Mario1->GetPosition().y>= position.y)
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y-(gravity)});
        else{
            m_Mario1->m_Jump=false;
            m_Mario1->SetPosition({m_Mario->GetPosition().x, position.y});
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

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}