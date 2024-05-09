//
// Created by Felicia Rulita on 2024/5/7.
//

#ifndef SUPERMARIO1_MENUPHASE_H
#define SUPERMARIO1_MENUPHASE_H

#include "Phase.h"
#include "Character.h"

class MenuPhase final : public Phase{
public:
    explicit MenuPhase();

    ~MenuPhase() = default;

    void Start(App *app) override;

    void Update(App *app) override;

    void End(App *app) override;

};

#endif //SUPERMARIO1_MENUPHASE_H
