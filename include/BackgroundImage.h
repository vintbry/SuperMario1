//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_BACKGROUNDIMAGE_H
#define SUPERMARIO1_BACKGROUNDIMAGE_H

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include <iostream>

class BackgroundImage : public Util::GameObject {

public:
    BackgroundImage(std::string image) : GameObject(
            std::make_unique<Util::Image>(image), -10) {
    }

    void NextPhase(std::string phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        if(temp){
            std::cout<<"temp not null";
        }
        else{
            std::cout<<"null";
        }
        temp->SetImage(ImagePath(phase));
    }

private:
    inline std::string ImagePath(std::string phase) {
        return GA_RESOURCE_DIR"/Background/Phase" + phase + ".png";
    }
};

#endif //SUPERMARIO1_BACKGROUNDIMAGE_H
