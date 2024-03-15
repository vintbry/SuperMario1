//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_CHARACTER_H
#define SUPERMARIO1_CHARACTER_H

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Time.hpp"

class Character : public Util::GameObject, public Util::Time {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    //from Animated Character
    void Update(unsigned long BaseTime);

    bool IsJumping() const{
        return m_Jump;
    }

    glm::vec2 GetLandPosition(){return {-400.0f, -200.5f};}

    void Jump(unsigned long BaseTime){
        m_Jump=true;
        Update(BaseTime);
    }

    bool m_Jump=false;
    bool m_HasEnded=true;


    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        //(void) other;
        float x1=GetPosition().x;
        float x2=other->GetPosition().x;
        float y1=GetPosition().y;
        float y2=other->GetPosition().y;

        bool x_overlap=(x1>=x2 && x1<=x2+other->GetScaledSize().x);
        bool y_overlap=(y1>=y2 && y1<=y2+other->GetScaledSize().y);

        return x_overlap && y_overlap;
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_CHARACTER_H