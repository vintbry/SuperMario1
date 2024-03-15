//
// Created by Felicia Rulita on 2024/3/12.
//
#include "AnimatedCharacter.h"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}
/*
void AnimatedCharacter::Update(unsigned long BaseTime) {
    if(m_Jump){

        unsigned long jumpTime = 1000;
        std::size_t timeNow = Util::Time::GetElapsedTimeMs();
        if(timeNow < BaseTime + jumpTime){
            m_HasEnded=false;

            LOG_DEBUG("Base2");
            LOG_DEBUG(BaseTime);
        }
        else{
            m_HasEnded=true;
            LOG_DEBUG("ended");
        }
        LOG_DEBUG(timeNow);
        LOG_DEBUG("Base3");
        LOG_DEBUG(BaseTime);
        LOG_DEBUG(m_HasEnded);
        //LOG_DEBUG(BaseTime);
    }
}
*/
void AnimatedCharacter::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}


