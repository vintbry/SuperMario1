//
// Created by Felicia Rulita on 2024/5/1.
//

#ifndef SUPERMARIO1_YELLOWMUSH_H
#define SUPERMARIO1_YELLOWMUSH_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "AnimatedCharacter.h"
#include "Character.h"

class YellowMush : public AnimatedCharacter{
public:
    explicit YellowMush(const std::vector<std::string>& AnimationPaths);

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
    template<typename T>
    bool IsCollideRight(std::shared_ptr<T> Object ){
            auto tiles = Object;
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }


        return false;
    }
    template<typename T>
    bool IsCollideLeft(std::vector<std::shared_ptr<T>> Object){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }
    template<typename T>
    bool IsCollideLeft(std::shared_ptr<T> Object){

            auto tiles = Object;
            bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY = collideY1 || collideY2;

            if(collideX && collideY){
                return true;
            }


        return false;
    }

    float direction = 1.0f;
    float y_start_Yellow_Mushroom = 0.0f;
    float time_Yellow_Mushroom =0.0f;

    bool isActive = false;
    bool isActive2 = false;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_YELLOWMUSH_H
