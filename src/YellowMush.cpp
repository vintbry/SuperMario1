//
// Created by Felicia Rulita on 2024/5/1.
//
#include "YellowMush.h"

YellowMush::YellowMush(const std::string &ImagePath) : Character(ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}