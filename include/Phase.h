//
// Created by Felicia Rulita on 2024/5/7.
//

#ifndef SUPERMARIO1_PHASE_H
#define SUPERMARIO1_PHASE_H

#include "Character.h"
#include "App.h"
#include "Util/Input.hpp"

class Phase{
public:
    enum class State {
        START,
        UPDATE,
        END,
        EXIT,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void SetState(State state);

    virtual void Start(App *app) = 0;

    virtual void Update(App *app) = 0;

    virtual void End(App *app) = 0;

    State m_CurrentState = State::START;

    std::shared_ptr<BackgroundImage> m_Bg;

};

#endif //SUPERMARIO1_PHASE_H
