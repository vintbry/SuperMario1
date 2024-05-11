//
// Created by Felicia Rulita on 2024/3/12.
//
#include "AnimatedCharacter.h"

AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
    m_AnimationPath = AnimationPaths;
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}

void AnimatedCharacter::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void AnimatedCharacter::SetImage(const std::vector<std::string>& AnimationPaths) {
    m_AnimationPath = AnimationPaths;
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false,0);
}

std::vector<std::string> AnimatedCharacter::GetAnimationPath() {
    return m_AnimationPath;
}
