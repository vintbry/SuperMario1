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

class AnimatedCharacter : public Util::GameObject {
public:
    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths);

    void Update(unsigned long BaseTime);
    /*
    bool IsJumping() const{
        return m_Jump;
    }
    */
    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }
    void SetInterval(int milliseconds){
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->SetInterval(milliseconds);
    }
    //only for first trial, later should can jump to another level
    //of land
    //glm::vec2 GetLandPosition(){return {-400.0f, -200.5f};}
    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }
    /*
    void Jump(unsigned long BaseTime){
        m_Jump=true;
        Update(BaseTime);
    };
    */
    [[nodiscard]] bool GetVisibility() const { return m_Visible; }
    void SetPlaying(){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();

    }
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void SetImage(const std::string& ImagePath);

    [[nodiscard]] bool IfAnimationEnds() const;

    //bool m_Jump=false;
    //bool m_HasEnded=true;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_ANIMATEDCHARACTER_H
