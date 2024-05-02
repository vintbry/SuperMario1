//
// Created by Felicia Rulita on 2024/4/26.
//

#ifndef SUPERMARIO1_MARIO_H
#define SUPERMARIO1_MARIO_H
#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Character.h"
#include "QuestionTiles.h"
#include "AnimatedCharacter.h"
#include "Mushroom.h"
#include "Koopa.h"

class Mario : public AnimatedCharacter{
public:
    explicit Mario(const std::vector<std::string>& AnimationPaths);

    template<typename T>
    std::tuple<bool,int> IsStepOn(std::vector<std::shared_ptr<T>> Objects){
        for(int i=0;i<Objects.size();i++){
            auto tiles = Objects[i];
            bool collideX1 = (GetPosition().x-GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(GetPosition().x-GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideX2 = (GetPosition().x+GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
            bool collideY = ((GetPosition().y - GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((GetPosition().y - GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

            glm::vec2 landPos = {GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+GetScaledSize().y/2};

            bool collideX = collideX1 || collideX2;

            if((collideX) && (collideY)){
                return {true,i};
            }
        }
        return {false, -1};
    }

    std::tuple<bool,int> IsHeading(std::vector<std::shared_ptr<Character>>Objects){
        for(int i=0;i<Objects.size();i++){
            //debugging
            auto tiles = Objects[i];
            bool collideX1 = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
            bool collideX2 = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(GetPosition().x + GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

            bool collideX = collideX1 || collideX2;

            if(collideX && collideY){
                return {true,i};
            }

        }
        return {false,-1};
    }

    std::tuple<bool,int> IsHeading(std::vector<std::shared_ptr<QuestionTiles>>Objects){
        for(int i=0;i<Objects.size();i++){
            //debugging
            auto tiles = Objects[i];
            bool collideX1 = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
            bool collideX2 = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(GetPosition().x + GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

            bool collideX = collideX1 || collideX2;

            if(collideX && collideY){
                return {true,i};
            }

        }
        return {false,-1};
    }
    template<typename T>
    bool IsCollideRight(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    bool IsCollideRight(std::vector<std::shared_ptr<Character>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }
    bool IsCollideRight(std::shared_ptr<Character> Object ){
        bool collideX = (GetPosition().x + GetScaledSize().x/2>=Object->GetPosition().x-Object->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=Object->GetPosition().x+Object->GetScaledSize().x/2);
        bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2);
        bool collideY2 = (GetPosition().y - GetScaledSize().y/2<Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2;

        LOG_DEBUG("collideright");
        LOG_DEBUG(GetPosition().x + GetScaledSize().x/2);
        LOG_DEBUG(Object->GetPosition().x-Object->GetScaledSize().x/2);


        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }


        return false;
    }

    template<typename T>
    bool IsCollideLeft(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    bool IsCollideLeft(std::shared_ptr<Character> Object ){
        bool collideX = (GetPosition().x + GetScaledSize().x/2>=Object->GetPosition().x-Object->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=Object->GetPosition().x+Object->GetScaledSize().x/2);
        bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2);
        bool collideY2 = (GetPosition().y - GetScaledSize().y/2<Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2;

        LOG_DEBUG("collideright");
        LOG_DEBUG(GetPosition().x + GetScaledSize().x/2);
        LOG_DEBUG(Object->GetPosition().x-Object->GetScaledSize().x/2);


        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }


        return false;
    }

    bool MarioDie = false;
    bool MarioStep = false;
    bool MarioHeadBrick = false;
    bool MarioHeadQues = false;
    bool MarioFinish = false;
    bool MarioEnd = false;
    bool MarioStepKoopa = false;

    int level = 0;

    //mushroom, coins
    bool isActive = false;



private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};
#endif //SUPERMARIO1_MARIO_H
