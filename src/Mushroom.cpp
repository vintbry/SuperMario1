//
// Created by Felicia Rulita on 2024/4/29.
//
#include "Mushroom.h"

Mushroom::Mushroom(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths){
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}