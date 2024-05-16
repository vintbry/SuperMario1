//
// Created by Felicia Rulita on 2024/5/14.
//

#ifndef SUPERMARIO1_FIRSTWORLDTWO_H
#define SUPERMARIO1_FIRSTWORLDTWO_H

#include "App.h"
#include "Phase.h"
#include "AnimatedCharacter.h"
#include "Character.h"
#include "Util/SFX.hpp"
#include "Util/Logger.hpp"
#include "Util/BGM.hpp"
#include "PhaseResourcesManager.h"

class FirstWorldTwo final : public Phase{
public:
    explicit FirstWorldTwo();

    ~FirstWorldTwo() = default;

    void Start(App *app) override;

    void StartLevel(App *app) override;

    void StartLevel2(App *app) override;
};

#endif //SUPERMARIO1_FIRSTWORLDTWO_H
