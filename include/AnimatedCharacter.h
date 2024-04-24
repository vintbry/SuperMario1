//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_ANIMATEDCHARACTER_H
#define SUPERMARIO1_ANIMATEDCHARACTER_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Character.h"
#include "QuestionTiles.h"

class AnimatedCharacter : public Util::GameObject{
public:
    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths);

    void Update(unsigned long BaseTime);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }
    void SetInterval(int milliseconds){
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->SetInterval(milliseconds);
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }
    void SetPlaying(){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();

    }
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void SetImage(const std::string& ImagePath);

    [[nodiscard]] bool IfAnimationEnds() const;

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
    bool IsCollideRight(std::vector<std::shared_ptr<AnimatedCharacter>> Object ){
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

        bool collideY = collideY1 || collideY2;

        if(collideX && collideY){
            return true;
        }


        return false;
    }

    bool IsCollideLeft(std::vector<std::shared_ptr<Character>> Object){
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
    bool IsCollideLeft(std::vector<std::shared_ptr<AnimatedCharacter>> Object){
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
    std::tuple<bool,int> IsStepOn(std::vector<std::shared_ptr<AnimatedCharacter>> Objects){
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


    float direction = -1.0f;
    bool MarioDie = false;
    bool MarioStep = false;
    bool EnemyDie = false;
    bool MarioHead = false;
    bool MarioFinish = false;
    bool MarioEnd = false;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_ANIMATEDCHARACTER_H
