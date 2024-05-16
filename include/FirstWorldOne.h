//
// Created by Felicia Rulita on 2024/5/8.
//

#ifndef SUPERMARIO1_FIRSTWORLDONE_H
#define SUPERMARIO1_FIRSTWORLDONE_H

#include "App.h"
#include "Phase.h"
#include "AnimatedCharacter.h"
#include "Character.h"
#include "Util/SFX.hpp"
#include "Util/Logger.hpp"
#include "Util/BGM.hpp"
#include "PhaseResourcesManager.h"

class FirstWorldOne final : public Phase{
public:
    explicit FirstWorldOne();

    ~FirstWorldOne() = default;

    void Start(App *app) override;

};

#endif //SUPERMARIO1_FIRSTWORLDONE_H
