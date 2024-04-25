//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

void App::moveBackground(float position) {
    m_Mushroom->SetPosition({m_Mushroom->GetPosition().x-position, m_Mushroom->GetPosition().y});
    m_Bg->SetPosition({m_Bg->GetPosition().x-position,m_Bg->GetPosition().y});

    for(const auto & i : m_Land){
        i->SetPosition({i->GetPosition().x-position,i->GetPosition().y});
    }
    for(const auto & j : m_Tube){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_Wood){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    //m_MushVector[0]->SetPosition({m_MushVector[0]->GetPosition().x - 5.0f,m_MushVector[0]->GetPosition().y});
    for(const auto & j : m_MushVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_QuesVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_Brick){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_Castle){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_DeadQues){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    m_Pillar->SetPosition({m_Pillar->GetPosition().x-position,m_Pillar->GetPosition().y});
    m_Flag->SetPosition({m_Flag->GetPosition().x-position,m_Flag->GetPosition().y});
    m_Coins->SetPosition({m_Coins->GetPosition().x-position,m_Coins->GetPosition().y});
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

std::tuple<bool,glm::vec2 > App::IsOnLand(std::shared_ptr<AnimatedCharacter> Object){
    for(int i=0;i<m_Land.size();i++){
        auto tiles = m_Land[i];
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }

    for(int i=0;i<m_QuesVector.size();i++){
        auto tiles = m_QuesVector[i];
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(int i=0;i<m_Brick.size();i++){
        auto tiles = m_Brick[i];
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(int i=0;i<m_Tube.size();i++){
        auto tiles = m_Tube[i];
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(int i=0;i<m_Wood.size();i++){
        auto tiles = m_Wood[i];
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }


    return {false,Object->GetPosition()};
}

bool App::IsCollideRight(std::shared_ptr<AnimatedCharacter> Object){
    for(int i=0;i<m_Brick.size();i++){
        //debugging
        auto tiles = m_Brick[i];
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_QuesVector.size();i++){
        //debugging
        auto tiles = m_QuesVector[i];
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Land.size();i++){
        //debugging
        auto tiles = m_Land[i];
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        //debugging
        auto tiles = m_Tube[i];
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Wood.size();i++){
        //debugging
        auto tiles = m_Wood[i];
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2-2.0f) && Object->GetPosition().y-Object->GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
};

bool App::IsCollideLeft(std::shared_ptr<AnimatedCharacter> Object){
    for(int i=0;i<m_Brick.size();i++){
        //debugging
        auto tiles = m_Brick[i];
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_QuesVector.size();i++){
        //debugging
        auto tiles = m_QuesVector[i];
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Land.size();i++){
        //debugging
        auto tiles = m_Land[i];
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        //debugging
        auto tiles = m_Tube[i];
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(int i=0;i<m_Wood.size();i++){
        //debugging
        auto tiles = m_Wood[i];
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2-2.0f) && Object->GetPosition().y-Object->GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
};

bool App::IsCollideUp(){
    for(int i=0;i<m_Brick.size();i++){
        //debugging
        auto tiles = m_Brick[i];
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            LOG_DEBUG("msk sini");
            return true;
        }

    }
    for(int i=0;i<m_QuesVector.size();i++){
        //debugging
        auto tiles = m_QuesVector[i];
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            LOG_DEBUG("msk sini");
            return true;
        }

    }
    for(int i=0;i<m_Tube.size();i++){
        //debugging
        auto tiles = m_Tube[i];
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            LOG_DEBUG("msk sini");
            return true;
        }

    }
    return false;
}

void App::Update(){
    timenow = Util::Time::GetElapsedTimeMs();

    auto result = IsOnLand(m_Mario);

    if( std::get<0>(result) && !m_Mario1->m_Jump && !m_Mario->MarioDie){
        //if on land then run
        position = std::get<1>(result);

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
    else if(std::get<0>(IsOnLand(m_Mario)) && m_Mario1->m_Jump && m_Mario1->m_HasEnded && !m_Mario->MarioDie){
        position = std::get<1>(IsOnLand(m_Mario));
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
    else if(!m_Mario->MarioDie && !m_Mario->MarioStep){
        //make mario always fall is not on land
        ///*
        if(!m_Mario1->m_Jump){
            m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->GetPosition().y-8.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
            m_MarioPillar->SetPosition(m_Mario->GetPosition());
        }
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);
        m_Mario1->SetVisible(true);
        //*/
    }

    //press F to go to next 部分 of map
    if(Util::Input::IsKeyDown(Util::Keycode::F)){
        moveBackground(2400.0f);

        m_Mario->SetPosition({m_Mario->GetPosition().x,100.0f});
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_EnterRight = true;
        m_EnterLeft = false;
        //when mario jump he can also go to the right
        m_MarioBack->SetVisible(false);
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
        callMarioForward();

        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand(m_Mario))){
            //change picture from running to jumping
            m_Mario->SetVisible(false);
            m_Mario1->SetVisible(true);
            //mario only can run until the middle
            //else is the elements that move


            if(m_Mario1->GetPosition().x < 13.0f and !IsCollideRight(m_Mario)){
                m_Mario1->SetPosition({m_Mario1->GetPosition().x+4.0f,m_Mario1->GetPosition().y});
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
            m_Mario1->SetVisible(false);
            //mario only can run until the middle
            //else is the elements that move

            if(m_Mario->GetPosition().x < 13.0f and !IsCollideRight(m_Mario)){
                m_Mario->SetPosition({m_Mario->GetPosition().x+8.0f,m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }

            

            //renew the other's position
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        //if mario more than middle than the background move
        if(m_Mario->GetPosition().x >= 13.0f and !IsCollideRight(m_Mario)){
            moveBackground(8.0f);
        }

    }

    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_EnterRight = false;
        m_EnterLeft = true;
        callMarioBackward();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
        //make other invisible
        m_Mario1->SetVisible(false);
        m_Mario->SetVisible(false);

        //when mario jump he can also go to the left
        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand(m_Mario))){
            if(m_MarioBack->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){ // and IsCollide()
                m_MarioBack->SetPosition({m_Mario1->GetPosition().x-4.0f, m_Mario1->GetPosition().y});
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
            if(m_MarioBack->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){
                m_MarioBack->SetPosition({m_Mario->GetPosition().x-8.0f, m_Mario->GetPosition().y});
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
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario1->m_Jump && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        glm::vec2 newPos = m_Mario->GetPosition();

        m_Mario_jump_audio->SetVolume(75);
        //m_Mario_jump_audio->SetVolume(0);
        m_Mario_jump_audio->Play();

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

    if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump ){
        if(!IsCollideUp()){
            float powerjump = (timenow - m_JumpBaseTime)/100.0f;
            if (powerjump>10) powerjump=10.0f;
            if (cnts>5)cnts =5.0;
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y+((7.0+cnts)-powerjump)});
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario->SetPosition(m_Mario1->GetPosition());
            m_Mario1->Jump(m_JumpBaseTime);
        }
        else{
            m_Mario1->m_HasEnded = true;
        }

    }
    else if (m_Mario1->m_HasEnded && m_Mario1->m_Jump && !std::get<0>(IsOnLand(m_Mario))){
        float gravity = (timenow - m_JumpBaseTime)/200.0f;
        if (gravity>10) gravity=10.0;
        if(!std::get<0>(IsOnLand(m_Mario))) {
            m_Mario1->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y - (3.0+gravity)});
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

    //enemy moving
    for(const auto & i : m_MushVector){
        //gravity if fall
        if(i->GetPosition().x<=370.0f){
            i->isActive = true;
        }

        if(!std::get<0> (IsOnLand(i)) && i->isActive){
            i->SetPosition({i->GetPosition().x-1.0f,i->GetPosition().y-5.0f});
        }
        else if(i->isActive && !i->EnemyDie){
            if(i->IsCollideLeft(m_Tube)){
                i->direction = 1.0f;
            }
            else if(i->IsCollideRight(m_Tube)){
                i->direction = -1.0f;
            }
            i->SetPosition({i->GetPosition().x+(2.0f* i->direction ),i->GetPosition().y});
        }
    }
    auto stepOn = m_Mario->IsStepOn(m_MushVector);

    //if mario kills enemy
    if(std::get<0>(stepOn) && !m_Mario->MarioStep && !m_Mario->MarioDie){
        m_Mario_stomp_audio->SetVolume(75);
        //m_Mario_stomp_audio->SetVolume(0);
        m_Mario_stomp_audio->Play();
        m_Mario->MarioStep = true;
        m_MarioStepTime = Util::Time::GetElapsedTimeMs();
        index = std::get<1>(stepOn);
        m_MushVector[index]->SetImage(GA_RESOURCE_DIR"/images/goombas_dead.png");

        m_MushVector[index]->EnemyDie = true;
        m_Mario1->SetPosition(m_Mario->GetPosition());
        m_MarioBack->SetPosition(m_Mario->GetPosition());

    }
    if(m_Mario->MarioStep){

        unsigned long now1 = Util::Time::GetElapsedTimeMs();
        if(now1-m_MarioStepTime<=300){
            if(m_Mario1->m_Jump) {
                m_Mario->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y + 11.0f});
            }
            else{
                m_Mario->SetPosition({m_Mario1->GetPosition().x, m_Mario1->GetPosition().y + 4.0f});
            }
        }
        else{
            m_MushVector[index]->SetPosition({m_MushVector[index]->GetPosition().x,m_MushVector[index]->GetPosition().y-2000});
            m_Mario->MarioStep = false;
        }

        m_Mario1->SetPosition(m_Mario->GetPosition());
        m_MarioBack->SetPosition(m_Mario->GetPosition());
    }
    //if mario collide enemy
    if((m_Mario->IsCollideRight(m_MushVector) || m_Mario->IsCollideLeft(m_MushVector)) && !m_Mario->MarioDie && !m_Mario->MarioStep){
        m_Mario_dead_audio->SetVolume(50);
        //m_Mario_dead_audio->SetVolume(0);
        m_Mario_dead_audio->Play();
        m_MarioDiesTime = Util::Time::GetElapsedTimeMs();
        m_Mario->MarioDie = true;
        m_BGMusic->Pause();

    }
    if(m_Mario->MarioDie){
        unsigned long now = Util::Time::GetElapsedTimeMs();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_death.png");

        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        m_MarioBack->SetVisible(false);
        if(now-m_MarioDiesTime<=300){
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        else{
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioBack->SetPosition(m_Mario->GetPosition());
            /*
            if(m_Mario->GetPosition().y<-400.0f){
                Restart();
            }
             */
        }

    }

    //if mario heading tiles
    auto headOnBrick = m_Mario->IsHeading(m_Brick);
    auto headOnQues = m_Mario->IsHeading(m_QuesVector);
    if(std::get<0>(headOnBrick)){
        m_Mario->MarioHead = true;
        m_MarioHeadTime = Util::Time::GetElapsedTimeMs();
        indexTiles = std::get<1>(headOnBrick);
        m_Brick[30]->SetPosition(m_Brick[indexTiles]->GetPosition());
        isBrick = true;
        m_Mario_bump_audio->SetVolume(75);
        //m_Mario_bump_audio->SetVolume(0);
        m_Mario_bump_audio->Play();
    }
    else if(std::get<0>(headOnQues)){
        m_Mario->MarioHead = true;
        m_MarioHeadTime = Util::Time::GetElapsedTimeMs();
        indexTiles = std::get<1>(headOnQues);
        m_DeadQues[indexTiles]->SetPosition(m_QuesVector[indexTiles]->GetPosition());
        isBrick = false;
        m_Mario_bump_audio->SetVolume(75);
        //m_Mario_bump_audio->SetVolume(0);
        m_Mario_bump_audio->Play();

        //coins came out
        //need to initiate which ques come out coins or other!
        if(m_QuesVector[indexTiles]->isActive) {
            m_Coins->isActive = true;
            m_Coins->SetPosition(m_QuesVector[indexTiles]->GetPosition());
        }

    }
    if(m_Mario->MarioHead){
        unsigned long now2 = Util::Time::GetElapsedTimeMs();
        if(isBrick){
            glm::vec2 tilePos = m_Brick[indexTiles]->GetPosition();
            m_Brick[30]->SetVisible(true);
            m_Brick[indexTiles]->SetVisible(false);
            if(now2-m_MarioHeadTime<=100){
                m_Brick[30]->SetPosition({m_Brick[30]->GetPosition().x,m_Brick[30]->GetPosition().y+5.0f});
            }
            else if(now2-m_MarioHeadTime<=200 && now2-m_MarioHeadTime>100){
                m_Brick[30]->SetPosition({m_Brick[30]->GetPosition().x,m_Brick[30]->GetPosition().y-5.0f});
            }
            else{
                m_Brick[indexTiles]->SetVisible(true);
                m_Brick[30]->SetVisible(false);
                m_Mario->MarioHead = false;
                m_Brick[30]->SetPosition(tilePos);
            }
        }
        else if(!isBrick && m_QuesVector[indexTiles]->isActive){
            glm::vec2 tilePos = m_QuesVector[indexTiles]->GetPosition();
            m_DeadQues[indexTiles]->SetVisible(true);
            m_QuesVector[indexTiles]->SetVisible(false);
            if(now2-m_MarioHeadTime<=100){
                m_DeadQues[indexTiles]->SetPosition({m_DeadQues[indexTiles]->GetPosition().x,m_DeadQues[indexTiles]->GetPosition().y+5.0f});
            }
            else if(now2-m_MarioHeadTime<=200 && now2-m_MarioHeadTime>100){
                m_DeadQues[indexTiles]->SetPosition({m_DeadQues[indexTiles]->GetPosition().x,m_DeadQues[indexTiles]->GetPosition().y-5.0f});
            }
            else{
                m_Mario->MarioHead = false;
                m_DeadQues[indexTiles]->SetPosition(tilePos);
                m_QuesVector[indexTiles]->isActive = false;
            }


        }

    }
    //coins
    if(m_Coins->isActive){
        auto now3 = Util::Time::GetElapsedTimeMs();
        m_Coins->SetVisible(true);
        if(now3-m_MarioHeadTime<=450){
            m_Coins->SetPosition({m_Coins->GetPosition().x,m_Coins->GetPosition().y+8.0f});
        }
        else if (now3-m_MarioHeadTime<=900 && now3-m_MarioHeadTime>450){
            m_Coins->SetPosition({m_Coins->GetPosition().x,m_Coins->GetPosition().y-8.0f});
        }
        else{
            m_Coins->SetVisible(false);
            m_Coins->isActive = false;
        }
    }


    //if touch pillar
    if(m_Mario->IsCollideRight(m_Pillar)){
        m_Mario->MarioFinish = true;
        //change mario animated image
        m_Mario->SetVisible(false);
        m_Mario1->SetVisible(false);
        m_MarioBack->SetVisible(false);
        m_MarioPillar->SetPosition(m_Mario->GetPosition());

    }
    unsigned long timeEnd;
    if(m_Mario->MarioFinish){
        m_Mario->SetVisible(false);
        m_Mario1->SetVisible(false);
        m_MarioBack->SetVisible(false);
        if(!std::get<0>(result)){
            m_MarioPillar->SetPosition({m_Pillar->GetPosition().x-5.0f,m_MarioPillar->GetPosition().y-5.0f});
        }

        m_MarioPillar->SetVisible(true);

        m_Mario->SetPosition(m_MarioPillar->GetPosition());
        m_Mario1->SetPosition(m_MarioPillar->GetPosition());
        m_MarioBack->SetPosition(m_MarioPillar->GetPosition());

        if(m_Flag->GetPosition().y>=-135.0f){
            m_Flag->SetPosition({m_Flag->GetPosition().x,m_Flag->GetPosition().y-5.0f});
        }
        else{
            timeEnd = Util::Time::GetElapsedTimeMs();
            m_Mario1->SetVisible(true);
            m_MarioPillar->SetVisible(false);
            m_Mario1->SetPosition({m_Mario1->GetPosition().x+12.0f,m_Mario1->GetPosition().y});
            m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_endBack.png");

            m_Mario->SetPosition(m_Mario1->GetPosition());
            m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario->MarioEnd = true;
            m_Mario->MarioFinish = false;
        }

    }
    if(m_Mario->MarioEnd){
        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        if(Util::Time::GetElapsedTimeMs()-timeEnd >= 14500 && !isWinLevel){
            m_Mario->SetVisible(true);
            m_Mario1->SetVisible(false);
            m_Mario->SetLooping(true);
            m_Mario->SetPlaying();
            moveBackground(6.0f);
        }
        if(m_Castle[0]->GetPosition().x<=m_Mario->GetPosition().x){
            m_Mario->SetVisible(false);
            m_Mario1->SetVisible(false);
            isWinLevel = true;
        }

    }

    //*/
    LOG_INFO("Mario POs");
    LOG_INFO(m_Mario->GetPosition().x);
    LOG_INFO(m_Mario->GetPosition().y);

    //pos mushroom
    LOG_DEBUG("mush");
    LOG_DEBUG(m_MushVector[0]->GetPosition().x);

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();


}