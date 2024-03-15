//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_APP_H
#define SUPERMARIO1_APP_H

#include "Util/Root.hpp"
#include "Character.h"
#include "Util/Text.hpp"
#include "AnimatedCharacter.h"
#include "PhaseResourcesManager.h"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    enum class Phase {
        FIRST_WORLD,
    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::FIRST_WORLD;

    Util::Root m_Root;

    std::shared_ptr<Character> m_Mario1;
    //std::shared_ptr<Character> m_Mushroom;
    //std::vector<std::shared_ptr<Character>> m_Doors;

    std::shared_ptr<AnimatedCharacter> m_Mario;

    std::shared_ptr<PhaseResourcesManager> m_PRM;

    unsigned long m_JumpBaseTime = 0;

    bool m_EnterDown = false;
};

#endif //SUPERMARIO1_APP_H
