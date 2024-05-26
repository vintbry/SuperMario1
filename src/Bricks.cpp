//
// Created by Felicia Rulita on 2024/5/22.
//
#include "Bricks.h"

Brick::Brick(const std::string& ImagePath) : Character(ImagePath){
    SetImage(ImagePath);

    ResetPosition();
}