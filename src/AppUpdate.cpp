//
// Created by Felicia Rulita on 2024/3/12.

#include "FirstWorldOne.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include <cmath>
#include <algorithm>

void Phase::Rendering(){
    for(const auto & i:m_MushVector){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i:m_KoopaVec){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(int i=0;i<m_QuesVector.size();i++){
        if(m_QuesVector[i]->GetPosition().x<400.0f && !m_DeadQues[i]->GetVisibility()){
            m_QuesVector[i]->SetVisible(true);
        }
    }
    for(const auto & i:m_Brick){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i:m_Castle){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i:m_YellowMushVec){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    if(m_Pillar->GetPosition().x<400.0f)m_Pillar->SetVisible(true);
    if(m_Flag->GetPosition().x<400.0f)m_Flag->SetVisible(true);
    if(m_Coins->GetPosition().x<400.0f)m_Coins->SetVisible(true);
}

float Phase::gravity(float y_start, float time_gravity, const std::shared_ptr<AnimatedCharacter> Object){
    float height = y_start - searchLand(Object);
    float y_exact =y_start-((10.0f/2)*((sqrt((2*height)/10.0))*(sqrt((2*height)/10.0))));

    if (Object->GetPosition().y<y_exact+25.0f){
        return y_exact;
    }

    else {
        return y_start - ((10.0f / 2) * (time_gravity * time_gravity));
    }

}

glm::vec2 Phase::ParabolicMovement (int v0, float angel_cos, float angel_sin,float time,std::shared_ptr<Character> Object){
    // gravity =10
    float x ,y, X_Point_start, Y_Point_start;
    Y_Point_start = Object->GetPosition().y;
    X_Point_start = Object ->GetPosition().x;

    //Horizontal Distance =>x(t)=v0 * cos(angle)*t
    x= X_Point_start + (v0* angel_cos*time);


    //Vertical Distance => y(t)=(v0 *sin(angel)*time)−(0.5 * Gravity * time^2)
    y= Y_Point_start + ((v0 * angel_sin*time)-(0.5 * 10 * (time*time)));

    LOG_INFO("SIN COS");


    glm::vec2 Position= {x,y};
    return Position;

}

void Phase::moveBackground(float position,App *app) {
    m_Bg2->SetPosition({m_Bg2->GetPosition().x-position,m_Bg2->GetPosition().y});

    m_BrickMove->SetPosition({m_BrickMove->GetPosition().x-position,m_BrickMove->GetPosition().y});

    for(const auto & i : m_Land){
        i->SetPosition({i->GetPosition().x-position,i->GetPosition().y});
    }
    for(const auto & j : m_Tube){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_Wood){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_MushVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_KoopaVec){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_QuesVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_Brick){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_Brick_break){
        for ( const auto & x : j) {
            x->SetPosition({x->GetPosition().x - position, x->GetPosition().y});
            if(x->GetPosition().x<-400.0f){
                app->m_Root.RemoveChild(x);
            }
        }
    }
    for(const auto & j : m_Castle){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_DeadQues){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_YellowMushVec){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    if(m_Coins2!=nullptr){
        for(const auto &j : m_Coins2Vec){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
    }
    m_Pillar->SetPosition({m_Pillar->GetPosition().x-position,m_Pillar->GetPosition().y});
    m_Flag->SetPosition({m_Flag->GetPosition().x-position,m_Flag->GetPosition().y});
    m_Coins->SetPosition({m_Coins->GetPosition().x-position,m_Coins->GetPosition().y});

}

void Phase::callMario(){
    m_Mario->SetVisible(true);
    m_Mario->SetLooping(false);
    m_Mario->SetInterval(100);
    m_Mario->SetPlaying();
}

void Phase::callMarioJump() {
    if(m_EnterRight){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioJump);
            LOG_DEBUG(m_Mario->GetAnimationPath()[0]);
        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioJumpLvl2);
        }

    }
    else if(m_EnterLeft){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioJumpBack);
        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioJumpBackLvl2);
        }
    }

}

//make function for searching is on land from mario's x
float Phase::searchLand(const std::shared_ptr<AnimatedCharacter> Object){
    float x = Object->GetPosition().x;
    float y = -1000.0f;

    for(int i=0;i<m_KoopaVec.size();i++){
        auto tiles = m_KoopaVec[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

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
    y = y + Object->GetScaledSize().y/2;

    return y;
}

std::tuple<bool,glm::vec2 > Phase::IsOnLand(const std::shared_ptr<AnimatedCharacter>& Object){
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

bool Phase::IsCollideRight(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
};

bool Phase::IsCollideLeft(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }
    }
    return false;
};

bool Phase::IsCollideUp(){
    for(const auto& tiles : m_Brick){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
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
            return true;
        }

    }
    return false;
}

void Phase::Update(App *app){
    Rendering();

    timenow +=1;

    if(!marioStart){
        m_Mario->SetImage(MarioJump);
        m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-15.0f});
    }

    if(m_Mario->GetPosition().y<-200.0f){
        m_Mario->MarioDie = true;
    }

    if (time >0) {
        time = 400 - (static_cast<int>(timenow) / static_cast<int>(10));
    }
    else {
        time =0;
    }
    m_time->SetText(std::to_string(time));
    m_score->SetText(std::to_string(score));
    m_coin->SetText(std::to_string(coin));

    auto result = IsOnLand(m_Mario);

    if( std::get<0>(result) && !m_Mario->m_Jump && !m_Mario->MarioDie){
        //if on land then run
        position = std::get<1>(result);
        m_popup->SetVisible(false);
        m_Mario->SetVisible(true);

        marioStart = true;

        pressed1 = false;
        y0 = m_Mario->GetPosition().y;
        t=0;
        cnt=0;
        speed =2;

        m_Mario->SetPosition(position);

    }
    else if(std::get<0>(result) && m_Mario->m_Jump && m_Mario->m_HasEnded && !m_Mario->MarioDie){
        marioStart = true;
        position = std::get<1>(result);

        m_Mario->SetPosition(position);
        m_Mario->m_Jump=false;

    }

    else if(!m_Mario->MarioDie && !m_Mario->MarioStep && !m_Mario->MarioFinish && marioStart){
        callMarioJump();
        //make mario always fall is not on land
        ///*

        float y_under= searchLand(m_Mario);
        //float y_under= -172;

        h=y0 - ( y_under);
        if(!m_Mario->m_Jump && !std::get<0>(result) ){

            t += 0.4;
            //jatuh tinggi
            if (m_Mario->GetPosition().y<y0-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))+15.0f){
                m_Mario->SetPosition({m_Mario->GetPosition().x, y0-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))});
            }

            else {

                m_Mario->SetPosition({m_Mario->GetPosition().x, y0 - ((10.0f / 2) * (t * t))});
            }
            m_MarioPillar->SetPosition(m_Mario->GetPosition());
        }

    }
    //press F to go to next 部分 of map
    if(Util::Input::IsKeyDown(Util::Keycode::F)){
        moveBackground(2400.0f,app);

        m_Mario->SetPosition({m_Mario->GetPosition().x,100.0f});
    }
    if(Util::Input::IsKeyDown(Util::Keycode::RIGHT)&& !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioRun);

        }
        else if(m_Mario->level==1) {
            m_Mario->SetImage(MarioRunLvl2);

        }

    }
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp){
        m_EnterRight = true;
        m_EnterLeft = false;
        //when mario jump he can also go to the right



        if(m_Mario->m_Jump or !std::get<0>(result)){
            //mario only can run until the middle
            //else is the elements that move
            LOG_DEBUG("right and jump");
            if(m_Mario->GetPosition().x < 13.0f and !IsCollideRight(m_Mario)){
                m_Mario->SetPosition({m_Mario->GetPosition().x+6.0f,m_Mario->GetPosition().y});
            }
        }
            //if not jumping than run
        else{
            m_Mario->SetPlaying();
            callMario();
            //mario only can run until the middle
            //else is the elements that move

            if(m_Mario->GetPosition().x < 13.0f and !IsCollideRight(m_Mario)){
                m_Mario->SetPosition({m_Mario->GetPosition().x+6.0f,m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }
        }
        //if mario more than middle than the background move
        if(m_Mario->GetPosition().x >= 13.0f and !IsCollideRight(m_Mario)){
            moveBackground(6.0f,app);
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
            m_Mario1->SetPosition(m_Mario->GetPosition());

        }
        if(m_Mario1->IsJumping() && !m_Mario1->m_HasEnded && !(Util::Input::IsKeyPressed(Util::Keycode::RIGHT))){
            m_Mario->SetPosition({m_Mario->GetPosition().x + 1.0f, m_Mario->GetPosition().y});
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
                m_Mario1->SetPosition(m_Mario->GetPosition());
            }
            else{
                moveBackground((8.0f - slideTime));
            }
            slideTime += 1;
        }

        //}
         */
    }

    if(Util::Input::IsKeyDown(Util::Keycode::LEFT)&& !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioRunBack);

        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioRunBackLvl2);

        }
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp){
        m_EnterRight = false;
        m_EnterLeft = true;

        //when mario jump he can also go to the left
        if(m_Mario->m_Jump or !std::get<0>(result)){
            if(m_Mario->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){ // and IsCollide()
                m_Mario->SetPosition({m_Mario->GetPosition().x-6.0f, m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }

        }
        else{ //if not jump
            callMario();
            m_Mario->SetPlaying();
            m_Mario->SetVisible(true);
            if(m_Mario->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)){
                m_Mario->SetPosition({m_Mario->GetPosition().x-6.0f, m_Mario->GetPosition().y});
            }
            else{
                m_Mario->SetPosition(m_Mario->GetPosition());
            }
        }

    }

    if(Util::Input::IsKeyUp(Util::Keycode::LEFT)){
        leftSlide = true;
        slideTime = 0.0f;
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
    //set image jump
    if(Util::Input::IsKeyDown(Util::Keycode::UP)){
        if(m_EnterRight){
            LOG_DEBUG("msk up");
            //need to check
            if(m_Mario->level == 0){
                LOG_DEBUG("msk level");
                m_Mario->SetImage(MarioJump);
            }
            else if (m_Mario->level == 1){
                m_Mario->SetImage(MarioJumpLvl2);
            }

        }
        else if(m_EnterLeft){
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioJumpBack);
            }
            else if (m_Mario->level == 1){
                m_Mario->SetImage(MarioJumpBackLvl2);
            }
        }
    }

    if(Util::Input::IsKeyUp(Util::Keycode::UP)){
        pressed2 = false;

    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        if (m_Mario->m_Jump && pressed2 && pressed1) {
            cnt++;

        }
        else {
            cnt =0;
        }
    }

    cnts= cnt/2.0;
    //
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario->m_Jump && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd&& !pressed1 && !pressed2 && std::get<0>(result) && !m_Mario->MarioStep && cnt==0){
        LOG_DEBUG("msk pressed up");
        glm::vec2 newPos = m_Mario->GetPosition();
        pressed1 = true;
        pressed2= true ;
        //m_Mario_jump_audio->SetVolume(75);
        m_Mario_jump_audio->SetVolume(0);
        m_Mario_jump_audio->Play();
        cnt =0;
        t=0;
        //m_Mario->SetVisible(false);
        m_Mario->m_Jump= true;


    }


    if( m_Mario->m_Jump ){
        if (cnts>2) cnts=2;
        if (pressed2 && pressed1 && !m_Mario->MarioStep) m_Mario->PowerJump = 45.0f+(5.0f*cnts);

        t+=0.4f;

        if(!IsCollideUp()){
            max_jump= fmaxf(y0,m_Mario->GetPosition().y);


            LOG_INFO("t VALUE");
            LOG_INFO(t);
            if (t< (m_Mario->PowerJump/10.0)  ){
                m_Mario->SetPosition({m_Mario->GetPosition().x, y0+(m_Mario->PowerJump*t) -((10.0/2)*(t*t))});

            }
            else if (t> (m_Mario->PowerJump/10.0) ) {
                y0 = max_jump;
                t = 0;
                m_Mario->m_Jump = false;
            }

        }

            //Mario collide with above brick
        else{
            m_Mario->m_Jump = false;
            t=1;
            y0 = m_Mario->GetPosition().y-5.0f;
        }

    }
    //enemy moving
    for(int i=0; i<m_MushVector.size();i++){
        //gravity if fall
        if(m_MushVector[i]->GetPosition().x<=370.0f){
            m_MushVector[i]->isActive = true;
        }

        if(!std::get<0> (IsOnLand(m_MushVector[i])) && m_MushVector[i]->isActive && !m_MushVector[i]->EnemyDie){
            m_MushVector[i]->SetPosition({m_MushVector[i]->GetPosition().x, gravity(m_MushVector[i]->y_start_goombas, m_MushVector[i]->time_goombas, m_MushVector[i])});
            m_MushVector[i]->time_goombas+=0.3;

        }
        else if(m_MushVector[i]->isActive && !m_MushVector[i]->EnemyDie){
            //reset time goombas to 0
            m_MushVector[i]->time_goombas=0.0f;
            //reset the y start of the goombas to the y now on land
            m_MushVector[i]->y_start_goombas = m_MushVector[i]->GetPosition().y;
            //need to adjust with another things
            //t_goombas=0.0f;

            //need to adjust with another things
            if(m_MushVector[i]->IsCollideLeft(m_Tube) || m_MushVector[i]->IsCollideLeft(m_MushVector, i) || m_MushVector[i]->IsCollideLeft(m_KoopaVec) || m_MushVector[i]->IsCollideLeft(m_Wood) ){
                m_MushVector[i]->direction = 1.0f;
            }
            else if(m_MushVector[i]->IsCollideRight(m_Tube) || m_MushVector[i]->IsCollideRight(m_MushVector,i)|| m_MushVector[i]->IsCollideRight(m_KoopaVec) || m_MushVector[i]->IsCollideRight(m_Wood)){
                m_MushVector[i]->direction = -1.0f;
            }
            m_MushVector[i]->SetPosition({m_MushVector[i]->GetPosition().x+(2.0f* m_MushVector[i]->direction ),m_MushVector[i]->GetPosition().y});
        }
    }
    for(const auto & i : m_KoopaVec){
        //gravity if fall
        if(i->GetPosition().x<=370.0f){
            i->isActive = true;
        }

        if(!std::get<0> (IsOnLand(i)) && i->isActive && !i->EnemyDie){
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
                i->SetPosition({i->GetPosition().x + (2.0f * i->direction), i->GetPosition().y});
            }
        }
    }
    //yellow mush
    for (const auto & i :m_YellowMushVec){
        if(!std::get<0> (IsOnLand(i)) && i->isActive && i->isActive2 && i->GetVisibility()){
            i->SetPosition({i->GetPosition().x+1.0f,gravity(i->y_start_Yellow_Mushroom,i->time_Yellow_Mushroom,i)});
            i->time_Yellow_Mushroom+=0.3f;
        }
        else if (i->isActive2){
            i->y_start_Yellow_Mushroom = i->GetPosition().y;
            i->time_Yellow_Mushroom =0.0f;

            if(i->IsCollideLeft(m_Tube) ){
                i->SetImage(GA_RESOURCE_DIR"/images/Mushroom.png");
                i->direction = 1.0f;
            }
            else if(i->IsCollideRight(m_Tube)){
                i->SetImage(GA_RESOURCE_DIR"/images/Mushroom_Back.png");
                i->direction = -1.0f;
            }
            i->SetPosition({i->GetPosition().x+(3.0f* i->direction ),i->GetPosition().y});
        }
    }



    auto stepOnMush = m_Mario->IsStepOn(m_MushVector);
    auto stepOnKoo = m_Mario->IsStepOn(m_KoopaVec);

    //if mario kills enemy
    if((std::get<0>(stepOnMush)) && !m_Mario->MarioStep && !m_Mario->MarioDie && !m_MushVector[std::get<1>(stepOnMush)]->EnemyDie){
        //popup score need to fix!
        score = score +100;
        m_popup->SetVisible(true);
        t=0;
        m_Mario->PowerJump =30;
        y0 = searchLand(m_Mario)-10.0f;
        m_Mario->m_Jump = true;

        m_popup->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+50.0f});

        //m_Mario_stomp_audio->SetVolume(75);
        m_Mario_stomp_audio->SetVolume(0);
        m_Mario_stomp_audio->Play();

        m_Mario->MarioStep = true;
        m_MarioStepTime = Util::Time::GetElapsedTimeMs();
        index = std::get<1>(stepOnMush);
        m_MushVector[index]->SetImage(GA_RESOURCE_DIR"/images/goombas_dead.png");

        m_MushVector[index]->EnemyDie = true;

    }
    if((std::get<0>(stepOnKoo))  && !m_Mario->MarioDie){
        //popup score need to fix!
        score = score +100;
        m_popup->SetVisible(true);
        t=0;
        m_Mario->PowerJump =30;
        y0 = searchLand(m_Mario)-10.0f;
        m_Mario->m_Jump = true;

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
        else if (std::get<0>(result)){
            cnts= 0.0f;
        }
        else{
            m_MushVector[index]->SetPosition({m_MushVector[index]->GetPosition().x,-2000});
            cnts= 0.0f;
            m_Mario->MarioStep = false;
        }

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
        if((i->IsCollideRightDead(m_KoopaVec) || i->IsCollideLeftDead(m_KoopaVec))){
            i->SetImage(GA_RESOURCE_DIR"/images/goombas_dead2.png");
            i->isBounced = true;
            i->EnemyDie = true;
        }
        if(i->isBounced){
            i->SetPosition({i->GetPosition().x, i->GetPosition().y- i->time_goombas});
            i -> time_goombas+=1.0;
        }
    }



    //if mario killed by enemy
    if((m_Mario->IsCollideRight(m_MushVector) || m_Mario->IsCollideLeft(m_MushVector) || m_Mario->IsCollideRight(m_KoopaVec) || m_Mario->IsCollideLeft(m_KoopaVec)) && !m_Mario->MarioDie && !m_Mario->MarioStep && !m_Mario->MarioLevelingDown && !std::get<0>(stepOnMush) && !std::get<0>(stepOnKoo)){
        LOG_DEBUG("collide enemy");
        //m_Mario_dead_audio->SetVolume(50);
        m_Mario_dead_audio->SetVolume(0);
        m_Mario_dead_audio->Play();
        m_MarioDiesTime = Util::Time::GetElapsedTimeMs();
        m_Mario->level-=1;
        if(m_Mario->level==-1){
            m_Mario->MarioDie = true;
            m_BGMusic->Pause();
        }
        else{
            LOG_DEBUG("msk brp kali leveldown");
            m_MarioShrinkTime = Util::Time::GetElapsedTimeMs();
            m_Mario->MarioLevelingDown = true;
            m_Mario->MarioShrink(MarioShrink);
            countBlinkTime = 0;

        }

    }

    //if mario levelingdown
    if(m_Mario->MarioLevelingDown){
        BlinkTime+=1;
        countBlinkTime = m_Mario->MarioBlinking(countBlinkTime);
        if(BlinkTime>=100){
            m_Mario->MarioLevelingDown = false;
            BlinkTime = 0;
        }
    }

    //if mario heading tiles
    auto headOnBrick = m_Mario->IsHeading(m_Brick);
    auto headOnQues = m_Mario->IsHeading(m_QuesVector);
    if(std::get<0>(headOnBrick)){
        m_Mario->MarioHeadBrick = true;
        m_MarioHeadTime = Util::Time::GetElapsedTimeMs();
        indexTiles = std::get<1>(headOnBrick);
        //when mario small or mario level=0 the brick won't break
        if(m_Mario->level == 0 ){
            m_BrickMove->SetPosition(m_Brick[indexTiles]->GetPosition());
            isBrick = 1;
            //m_Mario_bump_audio->SetVolume(75);
            m_Mario_bump_audio->SetVolume(0);
            m_Mario_bump_audio->Play();
        }
            // when mario big or mario level = 1, so brick will crack
        else if (m_Mario->level >= 1){
            // is brick =2 => brick will crack
            isBrick =2;
            m_Brick[indexTiles]-> SetVisible(false);
            for (int i =0 ; i<4; i++) m_Brick_break[indexTiles][i]->SetVisible(true);
            // m_Brick[indexTiles]->SetPosition({m_Brick[indexTiles]->GetPosition().x, -20000});

        }
        //if mush on the top of it
        for(const auto & i: m_MushVector){
            LOG_DEBUG("mushvector");
            LOG_DEBUG(m_MushVector[14]->GetPosition().y-m_MushVector[14]->GetScaledSize().y/2);
            LOG_DEBUG(m_Brick[indexTiles]->GetPosition().y+m_Brick[indexTiles]->GetScaledSize().y/2);
            //define x too else it will only take y as the condition
            if( i->IsStepOn(m_Brick[indexTiles]) && !i->EnemyDie){
                LOG_DEBUG("step on brick");
                i->EnemyDie = true;
                i->isBounced = true;
            }
        }
    }
    else if(std::get<0>(headOnQues) && (!m_Coins->isActive)){
        m_Mario->MarioHeadQues = true;
        m_MarioHeadTime2 = Util::Time::GetElapsedTimeMs();
        indexTiles2 = std::get<1>(headOnQues);
        m_DeadQues[indexTiles2]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
        isBrick = 3;
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
                if(indexTiles2==1){
                    indexMush = 0;
                }
                else if(indexTiles2 == 4 ){
                    LOG_DEBUG("masuk indexTiles2");
                    indexMush = 1;
                }
                else if(indexTiles2 == 5 ){
                    indexMush = 2;
                }
                else if(indexTiles2 == 9 ){
                    indexMush = 3;
                }

                if(!m_DeadQues[indexTiles2]->GetVisibility() && !m_YellowMushVec[indexMush]->isActive){
                    m_MarioHeadTime_yelmush = Util::Time::GetElapsedTimeMs();
                    m_YellowMushVec[indexMush]->isActive = true;
                    LOG_DEBUG("Msk brp kl bos");
                    LOG_DEBUG(m_QuesVector[indexTiles2]->GetPosition().y);
                    m_YellowMushVec[indexMush]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
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
    for(const auto & i:m_YellowMushVec){
        if(i->isActive){
            auto now5 = Util::Time::GetElapsedTimeMs();
            i->SetVisible(true);
            if(now5-m_MarioHeadTime_yelmush<=60){
                LOG_DEBUG("masuk yellow mush sini");
                LOG_DEBUG(i->GetPosition().y);
                i->SetVisible(false);
                i->SetPosition({i->GetPosition().x,i->GetPosition().y+8.0f});
            }
            else if(now5-m_MarioHeadTime_yelmush>60 && now5-m_MarioHeadTime_yelmush<=500){
                i->SetVisible(true);
                i->SetPosition({i->GetPosition().x,i->GetPosition().y+2.0f});
            }
            else if(now5-m_MarioHeadTime_yelmush>500){
                i->isActive2 = true;

            }
        }
        //leveling up!
        if(i->isActive2){

            if(i->IsCollideRight(m_Mario) || i->IsCollideLeft(m_Mario)){
                LOG_DEBUG("yellow mush collide mario");
                m_Mario->MarioLevelingUp = true;
                i->SetPosition({-1000.0f,-1000.0f});
                m_Mario->level+=1;

                if(m_EnterRight){
                    m_Mario->SetImage(levelUp);
                }
                else if(m_EnterLeft){
                    m_Mario->SetImage(levelUpBack);
                }
                m_Mario->SetPlaying();
                m_Mario->SetInterval(75);


            }

        }
    }

    //if mario leveling up
    if(m_Mario->MarioLevelingUp && !m_Mario->IsPlaying()){
        m_Mario->MarioLevelingUp = false;
    }
    //heading brick and question
    if( m_Mario->MarioHeadBrick){
        if(isBrick==1){
            unsigned long now2 = Util::Time::GetElapsedTimeMs();
            glm::vec2 tilePos = m_Brick[indexTiles]->GetPosition();
            m_BrickMove->SetVisible(true);
            m_Brick[indexTiles]->SetVisible(false);
            if(now2-m_MarioHeadTime<=100){
                m_BrickMove->SetPosition({m_BrickMove->GetPosition().x,m_BrickMove->GetPosition().y+5.0f});
            }
            else if(now2-m_MarioHeadTime<=200 && now2-m_MarioHeadTime>100){
                m_BrickMove->SetPosition({m_BrickMove->GetPosition().x,m_BrickMove->GetPosition().y-5.0f});
            }
            else{
                m_Brick[indexTiles]->SetVisible(true);
                m_BrickMove->SetVisible(false);
                m_Mario->MarioHeadBrick = false;
                m_BrickMove->SetPosition(tilePos);
            }
        }
        else if (isBrick==2){
            if (!m_Mario->m_Jump) m_Brick[indexTiles]->SetPosition({m_Brick[indexTiles]->GetPosition().x, -20000});

        }
    }
    else if(isBrick==3 && m_QuesVector[indexTiles2]->isActive && m_Mario->MarioHeadQues){
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

    // Makes the Brick Breaking independently => when m_Mario => (level==1) => collide up

    for (int i=0 ; i<m_Brick_break.size();i++){
        for (int Brickbat_index =0 ; Brickbat_index< m_Brick_break[i].size()-1;Brickbat_index++) {
            auto Brickbat_each = m_Brick_break[i][Brickbat_index];
            auto StartPoint= m_Brick_break[i][4];
            float Angle_cos, Angle_sin;
            if (Brickbat_each->GetVisibility()){
                Brickbat_each->CharacterTimePhysics +=0.4;

                //Control the movement of Left top Brickbat
                if (Brickbat_index==0) {Angle_cos = -0.087; Angle_sin = 0.99 ;}
                //Control the movement of Left bottom Brickbat
                else if (Brickbat_index==1) {Angle_cos = -0.17; Angle_sin = 0.98 ;}
                //Control the movement of Right top Brickbat
                else if (Brickbat_index==2){ Angle_cos = 0.087; Angle_sin = 0.99 ;}
                //Control the movement of Right bottom Brickbat
                else if (Brickbat_index==3) {Angle_cos = 0.17; Angle_sin = 0.98 ;}

                Brickbat_each->SetPosition(ParabolicMovement(30,Angle_cos,Angle_sin,Brickbat_each->CharacterTimePhysics,StartPoint));
                //Brickbat_each->SetPosition({Brickbat_each->GetPosition().x+AngelDegree,Brickbat_each->GetPosition().y- Brickbat_each->CharacterTimePhysics});

                // to remove the brickbat when y on coordinate less than -300
                if (Brickbat_each->GetPosition().y <= -300) Brickbat_each->SetVisible(false);
            }
        }

    }


    //if touch pillar
    if(m_Mario->IsCollideRight(m_Pillar) && !m_Mario->MarioFinish){
        m_Mario->MarioFinish = true;
        //change mario animated image
        m_Mario->SetVisible(false);
        m_MarioPillar->SetPosition({m_Pillar->GetPosition().x,m_Mario->GetPosition().y});

    }
    unsigned long timeEnd;
    if(m_Mario->MarioFinish){
        m_Mario->SetVisible(false);
        if(m_MarioPillar->GetPosition().y>=-135.0f){
            m_MarioPillar->SetPosition({m_Pillar->GetPosition().x-5.0f,m_MarioPillar->GetPosition().y-5.0f});
        }

        m_MarioPillar->SetVisible(true);

        m_Mario->SetPosition(m_MarioPillar->GetPosition());


        if(m_Flag->GetPosition().y>=-135.0f){
            m_Flag->SetPosition({m_Flag->GetPosition().x,m_Flag->GetPosition().y-5.0f});
        }
        else{
            timeEnd = Util::Time::GetElapsedTimeMs();
            //m_Mario1->SetVisible(true);
            m_MarioPillar->SetVisible(false);
            m_Mario->SetPosition({m_Mario->GetPosition().x+12.0f,m_Mario->GetPosition().y});
            m_Mario->SetImage(MarioPillarEnd);

            //m_Mario->SetPosition(m_Mario1->GetPosition());
            m_Mario->MarioEnd = true;
            m_Mario->MarioFinish = false;
        }

    }
    if(m_Mario->MarioEnd){
        m_BGMusic->Pause();
        if(!winSong) {
            //m_Mario_levelFinish_audio->SetVolume(50);
            m_Mario_levelFinish_audio->SetVolume(0);
            m_Mario_levelFinish_audio->Play();
            winSong = true;
        }
        if(Util::Time::GetElapsedTimeMs()-timeEnd >= 15500 && !isWinLevel){
            m_Mario->SetVisible(true);
            m_Mario->SetLooping(true);
            m_Mario->SetPlaying();
            m_Mario->SetInterval(70);
            moveBackground(6.0f,app);
        }
        if(m_Castle[0]->GetPosition().x<=m_Mario->GetPosition().x){
            m_Mario->SetVisible(false);
            isWinLevel = true;

        }

    }

    //mario levelup
    LOG_INFO("Mario POs");
    LOG_INFO(m_Mario->GetPosition().x);
    LOG_INFO(m_Mario->GetPosition().y);

    //if mario stepping the land
    if(std::get<0>(result) &&(m_Mario->GetAnimationPath() == MarioJump || m_Mario->GetAnimationPath() == MarioJumpBack ||m_Mario->GetAnimationPath() == MarioJumpLvl2 || m_Mario->GetAnimationPath() == MarioJumpBackLvl2)){
        if(m_EnterRight){
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioRun);
            }
            else if(m_Mario->level == 1){
                m_Mario->SetImage(MarioRunLvl2);
            }
        }
        else if(m_EnterLeft){
            LOG_DEBUG("step land left");
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioRunBack);
            }
            else if(m_Mario->level == 1){
                LOG_DEBUG("msk left level 1");
                m_Mario->SetImage(MarioRunBackLvl2);
            }
        }
    }
    //DO NOT MOVE OR ADD SOMETHING UNDER THESE TWO!!
    //exit
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        SetState(State::END);

    }
        //if die
    else if(m_Mario->MarioDie){
        m_popup->SetVisible(false);
        unsigned long now = Util::Time::GetElapsedTimeMs();
        m_Mario->SetImage(GA_RESOURCE_DIR"/Mario/mario_death.png");

        if(now-m_MarioDiesTime<=300){
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+5.0f});
        }
        else{
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-5.0f});

            if(m_Mario->GetPosition().y<-400.0f){
                Restart(app);
                SetState(State::START);
            }
        }

    }

    //restart
    if(Util::Input::IsKeyPressed(Util::Keycode::R)){
        Restart(app);
        SetState(State::START);
    }

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    app->m_Root.Update();

    //NEXT LEVEL
    if(isWinLevel){
        LOG_DEBUG("next level");
        //blm di restart
        Restart(app);
        app->SetPhase(App::Phases::FIRST_WORLD_TWO);
        app->ChangePhase(App::Phases::FIRST_WORLD_TWO);
    }


}
