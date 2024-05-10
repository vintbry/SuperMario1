//
// Created by Felicia Rulita on 2024/5/8.
//

#ifndef SUPERMARIO1_BEGINNINGPHASE_H
#define SUPERMARIO1_BEGINNINGPHASE_H

#include "Phase.h"

class BeginningPhase final : public Phase{
public:
    explicit BeginningPhase();

    ~BeginningPhase() = default;

    void Start(App *app) override;

    void Update(App *app) override;

    void End(App *app) override;
};

#endif //SUPERMARIO1_BEGINNINGPHASE_H
