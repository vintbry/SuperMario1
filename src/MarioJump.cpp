//
// Created by Felicia Rulita on 2024/4/11.
//
#include "MarioJump.h"

MarioJump::MarioJump(const std::string &ImagePath) : Character(ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}

void MarioJump::Update(unsigned long BaseTime) {
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