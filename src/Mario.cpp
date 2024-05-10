//
// Created by Felicia Rulita on 2024/4/26.
//

#include "Mario.h"

Mario::Mario(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}

void Mario::MarioShrink(std::vector<std::string> imagePath) {
    SetImage(imagePath);
    SetPlaying();
    SetInterval(100);
}

int Mario::MarioBlinking(int time) {
    if(time<3){
        SetVisible(true);
    }
    else if(time>=3 && time<6){
        SetVisible(false);
    }
    else if(time==6){
        LOG_DEBUG("time=10");
        return 0;
    }
    return (time+1);
}

void Mario::Update(unsigned long BaseTime) {
    if(m_Jump){
        unsigned long jumpTime = 600;
        std::size_t timeNow = Util::Time::GetElapsedTimeMs();
        if(timeNow < BaseTime + jumpTime){
            m_HasEnded=false;
        }
        else{
            m_HasEnded=true;
        }
    }
}


