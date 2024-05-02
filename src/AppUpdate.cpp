//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include <cmath>
#include <algorithm>

glm::vec2 App::jumpFormula(float xvalue, float x0, float y0, float v0, float t) {
    float y = y0 + (v0 * t) + (0.5 * 10.0f * t * t);
    float x = x0 + xvalue;
}

void App::moveBackground(float position) {
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
    for(const auto & j : m_MushVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_KoopaVec){
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
    m_YellowMush->SetPosition({m_YellowMush->GetPosition().x-position,m_YellowMush->GetPosition().y});
}

void App::callMario(){
    m_Mario->SetVisible(true);
    m_Mario->SetLooping(false);
    m_Mario->SetInterval(100);
    m_Mario->SetPlaying();
}

void App::callMarioBackward(){

    m_Mario->SetLooping(false);
    m_Mario->SetPlaying();
}

//make function for searching is on land from mario's x
float App::searchLand(const std::shared_ptr<AnimatedCharacter> Object){
    float x = Object->GetPosition().x;
    float y = -1000.0f;
    for(int i=0;i<m_MushVector.size();i++){
        auto tiles = m_MushVector[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Land.size();i++){
        auto tiles = m_Land[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Tube.size();i++){
        auto tiles = m_Tube[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_QuesVector.size();i++){
        auto tiles = m_QuesVector[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Brick.size();i++){
        auto tiles = m_Brick[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Wood.size();i++){
        auto tiles = m_Wood[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }
    LOG_DEBUG(y);
    y = y + m_Mario->GetScaledSize().y/2;
    LOG_DEBUG("return search land");
    LOG_DEBUG(y);

    return y;
}

std::tuple<bool,glm::vec2 > App::IsOnLand(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Land){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 100.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_QuesVector){
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
    for(const auto& tiles : m_Brick){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_Tube){
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
    for(const auto& tiles : m_Wood){
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

std::tuple<bool,glm::vec2 > App::IsOnLand(const std::shared_ptr<Character>& Object){
    for(const auto& tiles : m_Land){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 100.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_QuesVector){
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
    for(const auto& tiles : m_Brick){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_Tube){
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
    for(const auto& tiles : m_Wood){
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

bool App::IsCollideRight(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        //debugging
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        //debugging
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        //debugging
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        //debugging
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        //debugging
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

bool App::IsCollideLeft(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        //debugging
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        //debugging
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        //debugging
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        //debugging
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x - Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        //debugging
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
    for(const auto& tiles : m_Brick){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            LOG_DEBUG("msk sini");
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            LOG_DEBUG("msk sini");
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        //debugging
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

    if(m_Mario->GetPosition().y<-200.0f){
        m_Mario->MarioDie = true;
    }

    if (time >0) {
        time = 1000 - (static_cast<int>(timenow) / static_cast<int>(100));
    }
    else {
        time =0;
    }
    m_time->SetText(std::to_string(time));
    m_score->SetText(std::to_string(score));
    m_coin->SetText(std::to_string(coin));

    auto result = IsOnLand(m_Mario);

    if( std::get<0>(result) && !m_Mario1->m_Jump && !m_Mario->MarioDie){
        //if on land then run
        position = std::get<1>(result);
        m_popup->SetVisible(false);
        m_Mario->SetVisible(true);

        pressed1 = false;
        y0 = m_Mario->GetPosition().y;
        t=0;
        cnt=0;
        speed =2;

        m_Mario1->SetVisible(false);

        m_Mario->SetPosition(position);
        m_Mario1->SetPosition(position);

    }
    else if(std::get<0>(IsOnLand(m_Mario)) && m_Mario1->m_Jump && m_Mario1->m_HasEnded && !m_Mario->MarioDie){
        position = std::get<1>(IsOnLand(m_Mario));
        m_Mario1->SetVisible(false);

        m_Mario->SetPosition(position);
        m_Mario1->SetPosition(position);
        m_Mario1->m_Jump=false;
    }

    else if(!m_Mario->MarioDie && !m_Mario->MarioStep){
        //make mario always fall is not on land
        ///*

        float y_under= searchLand(m_Mario);
        //float y_under= -172;

        h=y0 - ( y_under);
        if(!m_Mario1->m_Jump && !std::get<0>(result) ){
            LOG_INFO("MASUK FALL");

            t += 0.5;
            //jatuh tinggi
            if (m_Mario->GetPosition().y<y0-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))+15.0f){
                m_Mario->SetPosition({m_Mario->GetPosition().x, y0-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))});
                LOG_INFO("MASUKK FALL2");
                LOG_INFO(t);
            }

            else {

                m_Mario->SetPosition({m_Mario->GetPosition().x, y0 - ((10.0f / 2) * (t * t))});
            }
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_MarioPillar->SetPosition(m_Mario->GetPosition());
        }
        m_Mario->SetVisible(false);
        m_Mario1->SetVisible(true);

    }
    LOG_DEBUG(searchLand(m_Mario));
    //press F to go to next 部分 of map
    if(Util::Input::IsKeyDown(Util::Keycode::F)){
        moveBackground(2400.0f);

        m_Mario->SetPosition({m_Mario->GetPosition().x,100.0f});
    }
    if(Util::Input::IsKeyDown(Util::Keycode::RIGHT)&& !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_Mario->SetImage(MarioRun);
        m_Mario->SetInterval(100);
        m_Mario->SetPlaying();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_EnterRight = true;
        m_EnterLeft = false;
        //when mario jump he can also go to the right
        m_Mario->SetPlaying();


        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand(m_Mario))){
            //change picture from running to jumping
            m_Mario->SetVisible(false);
            m_Mario1->SetVisible(true);
            //mario only can run until the middle
            //else is the elements that move
            if(m_Mario1->GetPosition().x < 13.0f and !IsCollideRight(m_Mario)){
                m_Mario1->SetPosition({m_Mario1->GetPosition().x+8.0f,m_Mario1->GetPosition().y});
            }


            m_Mario->SetPosition(m_Mario1->GetPosition());
        }
            //if not jumping than run
        else{
            callMario();
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
        }
        //if mario more than middle than the background move
        if(m_Mario->GetPosition().x >= 13.0f and !IsCollideRight(m_Mario)){
            moveBackground(8.0f);
        }

    }

    if(Util::Input::IsKeyUp(Util::Keycode::RIGHT)&& !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        /*
        rightSlide = true;
        slideTime = 0.0f;
        LOG_DEBUG("slide");
         */
    }
    if(rightSlide && !IsCollideRight(m_Mario) && !m_Mario->MarioDie && !m_Mario->MarioStep){
        /* //might no need
        if(m_Mario1->IsJumping()){
            //need to change
            m_Mario->SetPosition({m_Mario->GetPosition().x + 1.0f, m_Mario->GetPosition().y});
            m_MarioBack->SetPosition(m_Mario->GetPosition());
            m_Mario1->SetPosition(m_Mario->GetPosition());

        }
        if(m_Mario1->IsJumping() && !m_Mario1->m_HasEnded && !(Util::Input::IsKeyPressed(Util::Keycode::RIGHT))){
            m_Mario->SetPosition({m_Mario->GetPosition().x + 1.0f, m_Mario->GetPosition().y});
            m_MarioBack->SetPosition(m_Mario->GetPosition());
            m_Mario1->SetPosition(m_Mario->GetPosition());
        }
         */
        //else {
        //nti di pake tp skrg ganggu babi
        /*
        if (slideTime > 8.0f) {
            slideTime = 0.0f;
            rightSlide = false;
            //m_Mario->SetImage(MarioRun);
        } else {
            //m_Mario->SetImage(GA_RESOURCE_DIR"/Mario/mario_st.png");
            if(m_Mario->GetPosition().x < 13.0f) {
                m_Mario->SetPosition({m_Mario->GetPosition().x + (8.0f - slideTime), m_Mario->GetPosition().y});
                //m_MarioBack->SetPosition(m_Mario->GetPosition());
                m_Mario1->SetPosition(m_Mario->GetPosition());
            }
            else{
                moveBackground((8.0f - slideTime));
            }
            slideTime += 1;
        }
         */
        //}
    }

    if(Util::Input::IsKeyDown(Util::Keycode::LEFT)&& !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_Mario->SetImage(MarioRunBack);
        callMario();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");

    }

    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd){
        m_EnterRight = false;
        m_EnterLeft = true;
        callMario();
        //make other invisible
        m_Mario1->SetVisible(false);

        //when mario jump he can also go to the left
        if(m_Mario1->m_Jump or !std::get<0>(IsOnLand(m_Mario))){
            m_Mario->SetVisible(false);
            if(m_Mario->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){ // and IsCollide()
                m_Mario->SetPosition({m_Mario1->GetPosition().x-4.0f, m_Mario1->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario1->GetPosition());
            }

            //renew position
            m_Mario1->SetPosition(m_Mario->GetPosition());
            m_Mario1->SetVisible(true);
        }
        else{ //if not jump
            m_Mario->SetPlaying();
            m_Mario->SetVisible(true);
            if(m_Mario->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){
                m_Mario->SetPosition({m_Mario->GetPosition().x-8.0f, m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }

            //renew position
            m_Mario1->SetPosition(m_Mario->GetPosition());
        }
        //renew position
        m_Mario->SetPosition(m_Mario1->GetPosition());

    }

    if(Util::Input::IsKeyUp(Util::Keycode::LEFT)){
        leftSlide = true;
        slideTime = 0.0f;
        LOG_DEBUG("slide");
    }
    /*
    if(leftSlide && !IsCollideLeft(m_Mario)){
        if(slideTime>8.0f){
            slideTime = 0.0f;
            leftSlide = false;
        }
        else{
            m_Mario->SetPosition({m_Mario->GetPosition().x-(8.0f-slideTime),m_Mario->GetPosition().y});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            slideTime += 1.0f;
        }
    }
     */

    if(Util::Input::IsKeyUp(Util::Keycode::UP)){
        pressed2 = false;

    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        if (m_Mario1->m_Jump && pressed2 )cnt++;
    }

    cnts= cnt/2.0;
    //*/
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario1->m_Jump && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd&& !pressed1 && !pressed2){
        glm::vec2 newPos = m_Mario->GetPosition();
        pressed1 = true;
        pressed2= true ;
        //m_Mario_jump_audio->SetVolume(75);
        m_Mario_jump_audio->SetVolume(0);
        m_Mario_jump_audio->Play();

        m_JumpBaseTime=Util::Time::GetElapsedTimeMs();
        m_Mario1->SetPosition(newPos);
        //m_MarioBack->SetPosition(newPos);
        m_Mario1->SetVisible(true);

        m_Mario1->Jump(m_JumpBaseTime);

        m_Mario->SetVisible(false);
        m_Mario1->m_Jump= true;
        //m_MarioBack->SetVisible(false);

    }

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;

    }

    //if(!m_Mario1->m_HasEnded && m_Mario1->m_Jump ){
    if( m_Mario1->m_Jump ){
        if (cnts>2) cnts=2;
        if (pressed2 && pressed1 && !m_Mario->MarioStep) powerjump = 45.0f+(5.0f*cnts);

        t+=0.5f;

        if(!IsCollideUp()){
            max_jump= fmaxf(y0,m_Mario1->GetPosition().y);


            LOG_INFO("t VALUE");
            LOG_INFO(t);
            if (t<= (powerjump/10.0)  ){
                m_Mario1->SetPosition({m_Mario1->GetPosition().x, y0+(powerjump*t) -((10.0/2)*(t*t))});
                //m_MarioBack->SetPosition(m_Mario1->GetPosition());
                m_Mario->SetPosition(m_Mario1->GetPosition());

            }

            if (t>= (powerjump/10.0) ) {
                y0=max_jump;
                t=0;
                m_Mario1->m_Jump = false;


            }

            //m_Mario1->Jump(m_JumpBaseTime);
        }
        else{
            m_Mario1->m_Jump = false;
            t=1;
            y0 = m_Mario->GetPosition().y-5.0f;
        }

    }
    //enemy moving
    for(const auto & i : m_MushVector){
        //gravity if fall
        if(i->GetPosition().x<=370.0f){
            i->isActive = true;
        }

        if(!std::get<0> (IsOnLand(i)) && i->isActive && !i->EnemyDie){
            i->SetPosition({i->GetPosition().x-1.0f,i->GetPosition().y-5.0f});
        }
        else if(i->isActive && !i->EnemyDie){
            //need to adjust with another things
            if(i->IsCollideLeft(m_Tube) ){
                i->direction = 1.0f;
            }
            else if(i->IsCollideRight(m_Tube)){
                i->direction = -1.0f;
            }
            i->SetPosition({i->GetPosition().x+(2.0f* i->direction ),i->GetPosition().y});
        }
    }
    for(const auto & i : m_KoopaVec){
        //gravity if fall
        if(i->GetPosition().x<=370.0f){
            i->isActive = true;
        }

        if(!std::get<0> (IsOnLand(i)) && i->isActive && !i->EnemyDie){
            LOG_DEBUG("msk koopa");
            i->SetPosition({i->GetPosition().x-1.0f,i->GetPosition().y-5.0f});
        }
        else if(i->isActive && !i->EnemyDie){
            if(i->IsCollideLeft(m_Tube)){
                i->direction = 1.0f;
            }
            else if(i->IsCollideRight(m_Tube)){
                i->direction = -1.0f;
            }
            if(i->stepTimes==0) {
                LOG_DEBUG("masuk Koo");
                i->SetPosition({i->GetPosition().x + (2.0f * i->direction), i->GetPosition().y});
            }
        }
    }
    //yellow mush
    if(!std::get<0> (IsOnLand(m_YellowMush)) && m_YellowMush->isActive && m_YellowMush->isActive2){
        m_YellowMush->SetPosition({m_YellowMush->GetPosition().x+1.0f,m_YellowMush->GetPosition().y-5.0f});
    }
    else if (m_YellowMush->isActive2){
        if(m_YellowMush->IsCollideLeft(m_Tube) ){
            m_YellowMush->SetImage(GA_RESOURCE_DIR"/images/Mushroom.png");
            m_YellowMush->direction = 1.0f;
        }
        else if(m_YellowMush->IsCollideRight(m_Tube)){
            LOG_DEBUG("Yellow right");
            m_YellowMush->SetImage(GA_RESOURCE_DIR"/images/Mushroom_Back.png");
            m_YellowMush->direction = -1.0f;
        }
        m_YellowMush->SetPosition({m_YellowMush->GetPosition().x+(3.0f* m_YellowMush->direction ),m_YellowMush->GetPosition().y});
    }


    auto stepOnMush = m_Mario->IsStepOn(m_MushVector);
    auto stepOnKoo = m_Mario->IsStepOn(m_KoopaVec);

    //if mario kills enemy
    if((std::get<0>(stepOnMush)) && !m_Mario->MarioStep && !m_Mario->MarioDie){
        //popup score need to fix!
        score = score +100;
        m_popup->SetVisible(true);
        t=0;
        powerjump =30;
        y0 = searchLand(m_Mario)-10.0f;
        m_Mario1->m_Jump = true;

        m_popup->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+50.0f});

        //m_Mario_stomp_audio->SetVolume(75);
        m_Mario_stomp_audio->SetVolume(0);
        m_Mario_stomp_audio->Play();

        m_Mario->MarioStep = true;
        m_MarioStepTime = Util::Time::GetElapsedTimeMs();
        index = std::get<1>(stepOnMush);
        m_MushVector[index]->SetImage(GA_RESOURCE_DIR"/images/goombas_dead.png");

        m_MushVector[index]->EnemyDie = true;
        m_Mario1->SetPosition(m_Mario->GetPosition());
        //m_MarioBack->SetPosition(m_Mario->GetPosition());

    }
    if((std::get<0>(stepOnKoo))  && !m_Mario->MarioDie){
        //popup score need to fix!
        score = score +100;
        m_popup->SetVisible(true);
        m_popup->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+50.0f});

        //m_Mario_stomp_audio->SetVolume(75);
        m_Mario_stomp_audio->SetVolume(0);
        m_Mario_stomp_audio->Play();


        m_Mario->MarioStep = true;
        m_Mario->MarioStepKoopa = true;

        m_MarioStepTime = Util::Time::GetElapsedTimeMs();
        index2 = std::get<1>(stepOnKoo);
        m_KoopaVec[index2]->SetImage(GA_RESOURCE_DIR"/images/koopa_dead.png");
        m_KoopaVec[index2]->stepTimes +=1;

        //m_KoopaVec[index2]->EnemyDie = true;
        m_Mario1->SetPosition(m_Mario->GetPosition());
        //m_MarioBack->SetPosition(m_Mario->GetPosition());

        if(m_Mario->GetPosition().x <= m_KoopaVec[index2]->GetPosition().x){
            m_KoopaVec[index2]->directionUp = 1.0f;
        }
        else if(m_Mario->GetPosition().x > m_KoopaVec[index2]->GetPosition().x){
            m_KoopaVec[index2]->directionUp = -1.0f;
        }
    }
    if(m_Mario->MarioStep){

        unsigned long now1 = Util::Time::GetElapsedTimeMs();
        if(now1-m_MarioStepTime<=300){
            cnts= 0.0f;
        }
        else{
            m_MushVector[index]->SetPosition({m_MushVector[index]->GetPosition().x,m_MushVector[index]->GetPosition().y-2000});
            m_Mario->MarioStep = false;
        }

        m_Mario1->SetPosition(m_Mario->GetPosition());
        //m_MarioBack->SetPosition(m_Mario->GetPosition());
    }
    //if mario step koopa twice
    if( m_Mario->MarioStepKoopa && m_KoopaVec[index2]->stepTimes==2){
        m_KoopaVec[index2]->levelUp = true;
    }
    if(m_KoopaVec[index2]->levelUp){
        if( m_KoopaVec[index2]->IsCollideRight(m_Wood)){
            m_KoopaVec[index2]->directionUp = -1.0f;
        }
        else if( m_KoopaVec[index2]->IsCollideLeft(m_Wood)){
            m_KoopaVec[index2]->directionUp = 1.0f;
        }
        m_KoopaVec[index2]->SetPosition({m_KoopaVec[index2]->GetPosition().x+(20.0f*m_KoopaVec[index2]->directionUp),m_KoopaVec[index2]->GetPosition().y});
    }

    //if mush killed by koopa
    for(const auto & i : m_MushVector){
        if(i->IsCollideRight(m_KoopaVec) || i->IsCollideLeft(m_KoopaVec)){
            i->SetImage(GA_RESOURCE_DIR"/images/goombas_dead2.png");
            i->isBounced = true;
            i->EnemyDie = true;
        }
        if(i->isBounced){
            i->SetPosition({i->GetPosition().x-2.0f,i->GetPosition().y+2.0f});
        }
    }

    //if mario collide enemy
    if((m_Mario->IsCollideRight(m_MushVector) || m_Mario->IsCollideLeft(m_MushVector) || m_Mario->IsCollideRight(m_KoopaVec) || m_Mario->IsCollideLeft(m_KoopaVec)) && !m_Mario->MarioDie && !m_Mario->MarioStep){
        //m_Mario_dead_audio->SetVolume(50);
        m_Mario_dead_audio->SetVolume(0);
        m_Mario_dead_audio->Play();
        m_MarioDiesTime = Util::Time::GetElapsedTimeMs();
        m_Mario->MarioDie = true;
        m_BGMusic->Pause();

    }
    if(m_Mario->MarioDie){
        m_popup->SetVisible(false);
        unsigned long now = Util::Time::GetElapsedTimeMs();
        m_Mario1->SetImage(GA_RESOURCE_DIR"/Mario/mario_death.png");

        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        if(now-m_MarioDiesTime<=300){
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());
            //m_MarioBack->SetPosition(m_Mario->GetPosition());
        }
        else{
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-5.0f});
            m_Mario1->SetPosition(m_Mario->GetPosition());

            if(m_Mario->GetPosition().y<-400.0f){
                //Restart();
            }

        }

    }

    //if mario heading tiles
    auto headOnBrick = m_Mario->IsHeading(m_Brick);
    auto headOnQues = m_Mario->IsHeading(m_QuesVector);
    if(std::get<0>(headOnBrick)){
        m_Mario->MarioHeadBrick = true;
        m_MarioHeadTime = Util::Time::GetElapsedTimeMs();
        indexTiles = std::get<1>(headOnBrick);
        m_Brick[30]->SetPosition(m_Brick[indexTiles]->GetPosition());
        isBrick = true;
        //m_Mario_bump_audio->SetVolume(75);
        m_Mario_bump_audio->SetVolume(0);
        m_Mario_bump_audio->Play();
    }
    else if(std::get<0>(headOnQues) && !m_Coins->isActive  ){
        m_Mario->MarioHeadQues = true;
        m_MarioHeadTime2 = Util::Time::GetElapsedTimeMs();
        indexTiles2 = std::get<1>(headOnQues);
        m_DeadQues[indexTiles2]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
        isBrick = false;
        //m_Mario_bump_audio->SetVolume(75);
        m_Mario_bump_audio->SetVolume(0);
        m_Mario_bump_audio->Play();

        //m_Mario_coin_audio->SetVolume(75);
        m_Mario_coin_audio->SetVolume(0);
        m_Mario_coin_audio->Play();

        //coins came out
        //need to initiate which ques come out coins or other!
        if(m_QuesVector[indexTiles2]->isActive) {
            //for other world should be 調整
            if(indexTiles2 == 1 || indexTiles2 == 4 || indexTiles2 == 5 || indexTiles == 9){
                m_YellowMush->isActive = true;
                if(!m_DeadQues[indexTiles2]->GetVisibility()){
                    LOG_DEBUG("Msk brp kl bos");
                    m_YellowMush->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
                }

            }
            else{
                if(m_Coins->GetPosition().y == -1000.0f){
                    m_Coins->isActive = true;
                    coin+=1;
                    m_Coins->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
                }
            }

        }
    }

    //mushroom for leveling up
    if(m_YellowMush->isActive){
        auto now5 = Util::Time::GetElapsedTimeMs();
        m_YellowMush->SetVisible(true);
        if(now5-m_MarioHeadTime2<=30){
            m_YellowMush->SetPosition({m_YellowMush->GetPosition().x,m_YellowMush->GetPosition().y+8.0f});
        }
        else if(now5-m_MarioHeadTime2>30 && now5-m_MarioHeadTime2<=400){
            m_YellowMush->SetPosition({m_YellowMush->GetPosition().x,m_YellowMush->GetPosition().y+2.0f});
        }
        else if(now5-m_MarioHeadTime2>400){
            m_YellowMush->isActive2 = true;

        }
    }

    //leveling up
    if(m_Mario->IsCollideRight(m_YellowMush) || m_Mario->IsCollideLeft(m_YellowMush)){
        m_YellowMush->SetPosition({-1000.0,-1000.0f});
        m_Mario->level+=1;

        m_Mario->SetImage(levelUp);
        m_Mario->SetPlaying();
        m_Mario->SetInterval(75);

        LOG_DEBUG("masuk levelup");
        LOG_DEBUG(m_Mario->level);
    }

    LOG_DEBUG("yellow mush Pos");
    LOG_DEBUG(m_YellowMush->GetPosition().x);
    LOG_DEBUG(m_YellowMush->GetPosition().y);
    if(isBrick && m_Mario->MarioHeadBrick){
        unsigned long now2 = Util::Time::GetElapsedTimeMs();
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
            m_Mario->MarioHeadBrick = false;
            m_Brick[30]->SetPosition(tilePos);
        }
    }
    else if(!isBrick && m_QuesVector[indexTiles2]->isActive && m_Mario->MarioHeadQues){
        unsigned long now4 = Util::Time::GetElapsedTimeMs();
        glm::vec2 tilePos2 = m_QuesVector[indexTiles2]->GetPosition();
        m_DeadQues[indexTiles2]->SetVisible(true);
        m_QuesVector[indexTiles2]->SetVisible(false);
        if(now4-m_MarioHeadTime2<=100){
            m_DeadQues[indexTiles2]->SetPosition({m_DeadQues[indexTiles2]->GetPosition().x,m_DeadQues[indexTiles2]->GetPosition().y+5.0f});
        }
        else if(now4-m_MarioHeadTime2<=200 && now4-m_MarioHeadTime2>100){
            m_DeadQues[indexTiles2]->SetPosition({m_DeadQues[indexTiles2]->GetPosition().x,m_DeadQues[indexTiles2]->GetPosition().y-5.0f});
        }
        else{
            m_Mario->MarioHeadQues = false;
            m_DeadQues[indexTiles2]->SetPosition(tilePos2);
            m_QuesVector[indexTiles2]->isActive = false;
        }
    }


    //coins
    if(m_Coins->isActive){
        auto now3 = Util::Time::GetElapsedTimeMs();
        LOG_DEBUG("msk isactive");
        m_Coins->SetVisible(true);
        if(now3-m_MarioHeadTime2<=450){
            LOG_DEBUG("msk atas");
            m_Coins->SetPosition({m_Coins->GetPosition().x,m_Coins->GetPosition().y+8.0f});
        }
        else if (now3-m_MarioHeadTime2<=900 && now3-m_MarioHeadTime2>450){
            LOG_DEBUG("msk");
            m_Coins->SetPosition({m_Coins->GetPosition().x,m_Coins->GetPosition().y-8.0f});
        }
        else{
            m_Coins->SetVisible(false);
            m_Coins->isActive = false;
            m_Coins->SetPosition({-1000.0f,-1000.0f});
        }
    }


    //if touch pillar
    if(m_Mario->IsCollideRight(m_Pillar)){
        LOG_DEBUG("pillar");
        LOG_DEBUG(m_Pillar->GetPosition().x - m_Pillar->GetScaledSize().x/2);
        m_Mario->MarioFinish = true;
        //change mario animated image
        m_Mario->SetVisible(false);
        m_Mario1->SetVisible(false);
        //m_MarioBack->SetVisible(false);
        m_MarioPillar->SetPosition(m_Mario->GetPosition());

    }
    unsigned long timeEnd;
    if(m_Mario->MarioFinish){
        m_Mario->SetVisible(false);
        m_Mario1->SetVisible(false);
        //m_MarioBack->SetVisible(false);
        if(m_MarioPillar->GetPosition().y>=-135.0f){
            m_MarioPillar->SetPosition({m_Pillar->GetPosition().x-5.0f,m_MarioPillar->GetPosition().y-5.0f});
        }

        m_MarioPillar->SetVisible(true);

        m_Mario->SetPosition(m_MarioPillar->GetPosition());
        m_Mario1->SetPosition(m_MarioPillar->GetPosition());
        //m_MarioBack->SetPosition(m_MarioPillar->GetPosition());

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
            //m_MarioBack->SetPosition(m_Mario1->GetPosition());
            m_Mario->MarioEnd = true;
            m_Mario->MarioFinish = false;
        }

    }
    if(m_Mario->MarioEnd){
        m_Mario1->SetVisible(true);
        m_Mario->SetVisible(false);
        m_BGMusic->Pause();
        if(!winSong) {
            //m_Mario_levelFinish_audio->SetVolume(50);
            m_Mario_levelFinish_audio->SetVolume(0);
            m_Mario_levelFinish_audio->Play();
            winSong = true;
        }
        if(Util::Time::GetElapsedTimeMs()-timeEnd >= 15500 && !isWinLevel){
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

    //mario levelup

    //*/
    LOG_INFO("Mario POs");
    LOG_INFO(m_Mario->GetPosition().x);
    LOG_INFO(m_Mario->GetPosition().y);


    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();


}