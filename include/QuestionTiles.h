//
// Created by Felicia Rulita on 2024/4/11.
//

#ifndef SUPERMARIO1_QUESTIONTILES_H
#define SUPERMARIO1_QUESTIONTILES_H
#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"


class QuestionTiles : public Util::GameObject {
public:
    explicit QuestionTiles(const std::vector<std::string>& QuestionPaths);

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

    bool isActive = true;
private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_QUESTIONTILES_H
