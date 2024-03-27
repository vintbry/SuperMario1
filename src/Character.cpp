//
// Created by Felicia Rulita on 2024/3/12.
//
#include "Character.h"
#include "Util/Image.hpp"
#include "Util/Time.hpp"

Character::Character(const std::string& ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}

void Character::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Character::Update(unsigned long BaseTime) {
    if(m_Jump){
        unsigned long jumpTime = 500;
        std::size_t timeNow = Util::Time::GetElapsedTimeMs();
        if(timeNow < BaseTime + jumpTime){
            m_HasEnded=false;
        }
        else{
            m_HasEnded=true;
        }
    }
}


