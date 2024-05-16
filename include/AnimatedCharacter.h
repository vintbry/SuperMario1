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

    std::vector<std::string> GetAnimationPath();

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void SetImage(const std::string& ImagePath);

    void SetImage(const std::vector<std::string>& AnimationPaths);

    [[nodiscard]] bool IfAnimationEnds() const;

    template<typename T>
    bool IsCollideRight(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    virtual bool IsCollideRight(std::vector<std::shared_ptr<Character>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;
            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

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

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;


            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    virtual bool IsCollideLeft(std::vector<std::shared_ptr<Character>> Object){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;


            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    template<typename T>
    bool IsStepOn(std::shared_ptr<T> Objects){

            auto tiles = Objects;
            bool collideX1 = (GetPosition().x-GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2-2.0f))&&(GetPosition().x-GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+2.0f);
            bool collideX2 = (GetPosition().x+GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2)-2.0f)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+2.0f);
            //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
            bool collideY = ((GetPosition().y - GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 15.0f) && ((GetPosition().y - GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+5.0f);

            glm::vec2 landPos = {GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+GetScaledSize().y/2};

            bool collideX = collideX1 || collideX2;

            if((collideX) && (collideY)){
                return true;
            }

        return false;
    }

    //mushroom, coins
    bool isActive = false;
    bool alreadyOut = false;



private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
    std::vector<std::string> m_AnimationPath;
};

#endif //SUPERMARIO1_ANIMATEDCHARACTER_H
