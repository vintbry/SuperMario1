//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_BACKGROUNDIMAGE_H
#define SUPERMARIO1_BACKGROUNDIMAGE_H

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class BackgroundImage : public Util::GameObject {

public:
    BackgroundImage() : GameObject(
            std::make_unique<Util::Image>(GA_RESOURCE_DIR"/Background/bg1.png"), -10) {
    }
    /*
    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }

private:
    inline std::string ImagePath(const int phase) {
        return GA_RESOURCE_DIR"/Image/Background/phase" + std::to_string(phase) + ".png";
    }
    */
};

#endif //SUPERMARIO1_BACKGROUNDIMAGE_H
