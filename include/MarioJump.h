//
// Created by Felicia Rulita on 2024/4/11.
//

#ifndef SUPERMARIO1_MARIOJUMP_H
#define SUPERMARIO1_MARIOJUMP_H

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Time.hpp"
#include "Character.h"

class MarioJump : public Character{
public:
    explicit MarioJump(const std::string& ImagePath);

    MarioJump(const MarioJump&) = delete;

    MarioJump(MarioJump&&) = delete;

    MarioJump& operator=(const MarioJump&) = delete;

    MarioJump& operator=(MarioJump&&) = delete;

    void Update(unsigned long BaseTime);

    bool IsJumping() const{
        return m_Jump;
    }

    void Jump(unsigned long BaseTime){
        m_Jump=true;
        Update(BaseTime);
    }

    bool m_Jump=false;
    bool m_HasEnded=true;
    bool m_maxJump=false;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_MARIOJUMP_H
