//
// Created by Felicia Rulita on 2024/5/22.
//

#ifndef SUPERMARIO1_BRICKS_H
#define SUPERMARIO1_BRICKS_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Character.h"

class Brick : public Character{
public:
    explicit Brick(const std::string& ImagePath);

    // CharacterTimePhysics => hold the value of the time we used in physics => esplecially fall, jump, etc.
    float CharacterTimePhysics = 0.0f;

    bool isMushInside = false;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_BRICKS_H
