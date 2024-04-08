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
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }

    for(int i=0;i<m_QuesVector.size();i++){
        auto tiles = m_QuesVector[i];
        //for(int j=0;j<tiles.size();j++){
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x/2)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y);
        bool collideY = ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 5.0f) && ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        if((collideX) && (collideY)){
            return {true, landPos};
        }

    }
    for(int i=0;i<m_Brick.size();i++){
        auto tiles = m_Brick[i];
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x/2)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y);
        bool collideY = ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 5.0f) && ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        if((collideX) && (collideY)){
            return {true, landPos};
            //return {true, {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y-1.0f}};
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        auto tiles = m_Tube[i];
        bool collideX = (m_Mario->GetPosition().x>=tiles->GetPosition().x-m_Mario->GetScaledSize().x/2)&&(m_Mario->GetPosition().x<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y);
        bool collideY = ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 5.0f) && ((m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        if((collideX) && (collideY)){
            return {true, landPos};
            //return {true, {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y-1.0f}};
        }

    }

    return {false,m_Mario->GetPosition()};
}

bool App::IsCollideRight(){
    for(int i=0;i<m_Brick.size();i++){
        //debugging
        auto tiles = m_Brick[i];
        bool collideX = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x+m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_QuesVector.size();i++){
        //debugging
        auto tiles = m_QuesVector[i];
        bool collideX = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x+m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Land.size();i++){
        //debugging
        auto tiles = m_Land[i];
        bool collideX = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x+m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        //debugging
        auto tiles = m_Tube[i];
        bool collideX = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x+m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
};

bool App::IsCollideLeft(){
    for(int i=0;i<m_Brick.size();i++){
        //debugging
        auto tiles = m_Brick[i];
        bool collideX = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_QuesVector.size();i++){
        //debugging
        auto tiles = m_QuesVector[i];
        bool collideX = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Land.size();i++){
        //debugging
        auto tiles = m_Land[i];
        bool collideX = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        //debugging
        auto tiles = m_Tube[i];
        bool collideX = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (m_Mario->GetPosition().y - m_Mario->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
};

void App::Update(){
    timenow = Util::Time::GetElapsedTimeMs();

    auto result = IsOnLand();

    if( std::get<0>(result) && !m_Mario1->m_Jump){
        //if on land then run
        position = std::get<1>(result);
        LOG_DEBUG("Msk");
        LOG_DEBUG(position.y);

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
    ///*
    else if(std::get<0>(IsOnLand()) && m_Mario1->m_Jump && m_Mario1->m_HasEnded){
        LOG_DEBUG("ifkedua");
        position = std::get<1>(IsOnLand());
        if(m_EnterRight){
            m_Mario1->SetVisible(false);
        }
        else{
            m_MarioBack->SetVisible(true);
        }
        m_Mario1->SetVisible(false);

        m_Mario->SetPosition(position);
        m_Mario1->SetPosition(position);
        m_MarioBack->SetPosition(position);

        m_Mario1->m_Jump=false;


    }
    //*/
    else{
        //make mario always fall is not on land
        ///*
        if(!m_Mario1->m_Jump){
            m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->GetPosition().y-5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);
        m_Mario1->SetVisible(true);
        //*/
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        m_EnterRight = true;
        m_EnterLeft = false;
        //when mario jump he can also go to the right
        m_MarioBack->SetVisible(false);
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
        callMarioForward();

        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand())){
            //change picture from running to jumping
            m_Mario->SetVisible(false);
            m_Mario1->SetVisible(true);
            //mario only can run until the middle
            //else is the elements that move


            //if(!IsCollide()){
                if(m_Mario1->GetPosition().x < 13.0f and !IsCollideRight()){
                    m_Mario1->SetPosition({m_Mario1->GetPosition().x+1.5f,m_Mario1->GetPosition().y});
                }
                else{
                    m_Mario1->SetPosition(m_Mario1->GetPosition());
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
                if(m_Mario->GetPosition().x < 13.0f and !IsCollideRight()){
                    m_Mario->SetPosition({m_Mario->GetPosition().x+5.0f,m_Mario->GetPosition().y});
                }
                else{
                    m_Mario->SetPosition(m_Mario->GetPosition());
                }

            //}
            

            //renew the other's position
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        //if mario more than middle than the background move
        if(m_Mario->GetPosition().x >= 13.0f and !IsCollideRight()){
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
        m_EnterLeft = true;
        callMarioBackward();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
        //make other invisible
        m_Mario1->SetVisible(false);
        m_Mario->SetVisible(false);

        //when mario jump he can also go to the left
        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand())){
            if(m_MarioBack->GetPosition().x > -340.0f and !IsCollideLeft()){ // and IsCollide()
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
            if(m_MarioBack->GetPosition().x > -340.0f and !IsCollideLeft()){
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
    ///*
    if(Util::Input::IsKeyUp(Util::Keycode::UP)){
        cnt=0;
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        cnt++;
    }

    unsigned int cnts= cnt/2.0;
    //*/
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario1->m_Jump){
        glm::vec2 newPos = m_Mario->GetPosition();
        m_audio_mario_small_jump.Play(1,1);
        LOG_DEBUG(m_audio_mario_small_jump.GetVolume());

        m_JumpBaseTime=Util::Time::GetElapsedTimeMs();
        m_Mario1->SetPosition(newPos);
        m_MarioBack->SetPosition(newPos);
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

    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump){
        float powerjump = (timenow - m_JumpBaseTime)/100.0f;
        if (powerjump>10) powerjump=10.0f;
        LOG_INFO("cntcntcnt");
        LOG_INFO(cnt);
        LOG_DEBUG("powerjump" );
        LOG_DEBUG(powerjump);
        if (cnts>5)cnts =5.0;
        m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+((7.0+cnts)-powerjump)});
        m_MarioBack->SetPosition(m_Mario1->GetPosition());
        m_Mario->SetPosition(m_Mario1->GetPosition());
        m_Mario1->Jump(m_JumpBaseTime);
    }
    else if (m_Mario1->m_HasEnded && m_Mario1->m_Jump && !std::get<0>(IsOnLand())){
        LOG_INFO("POSITION YYYYYYYY");
        LOG_INFO(position.y);
        float gravity = (timenow - m_JumpBaseTime)/200.0f;
        if (gravity>10) gravity=10.0;
        if(!std::get<0>(IsOnLand())) {
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y - (2.0+gravity)});
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario->SetPosition(m_Mario1->GetPosition());
        }
        else{
            m_Mario1->m_Jump=false;
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, position.y});
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
    //*/
    LOG_INFO("Mario POs");
    LOG_INFO(m_Mario1->GetPosition().x);
    LOG_INFO(m_Mario1->GetPosition().y);

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}