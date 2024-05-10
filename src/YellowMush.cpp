//
// Created by Felicia Rulita on 2024/5/1.
//
#include "YellowMush.h"

YellowMush::YellowMush(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);

}