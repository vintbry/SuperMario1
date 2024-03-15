//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_ANIMATEDCHARACTER_H
#define SUPERMARIO1_ANIMATEDCHARACTER_H

#include <vector>
#include <string>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"

class AnimatedCharacter : public Util::GameObject {
public:
    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }

    void SetPlaying(){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();

    }

    [[nodiscard]] bool IfAnimationEnds() const;
};

#endif //SUPERMARIO1_ANIMATEDCHARACTER_H
