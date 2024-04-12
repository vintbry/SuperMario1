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
#include "MarioJump.h"
#include "Util/SFX.hpp"
#include "Util/BGM.hpp"
#include "QuestionTiles.h"

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

    std::shared_ptr<Util::BGM> m_BGMusic;
    std::shared_ptr<Util::SFX> m_Mario_jump_audio;
    std::shared_ptr<Util::SFX> m_Mario_dead_audio;
    Util::Root m_Root;
    //Util::SFX m_audio_mario_small_jump = static_cast<Util::SFX>("/Audio/small_mario_jump.wav");  // Explicit casting
    std::shared_ptr<MarioJump> m_Mario1;
    std::shared_ptr<Character> m_Bg;



    std::vector<std::shared_ptr<Character>> m_Land;
    std::vector<std::shared_ptr<Character>> m_Brick;
    std::vector<std::shared_ptr<Character>> m_Tube;
    std::vector<std::shared_ptr<Character>> m_Wood;

    std::vector<std::shared_ptr<QuestionTiles>> m_QuesVector;

    std::shared_ptr<QuestionTiles> m_Question;

    std::vector<std::shared_ptr<AnimatedCharacter>> m_MushVector;

    std::shared_ptr<AnimatedCharacter> m_Mario;
    std::shared_ptr<AnimatedCharacter> m_MarioBack;
    std::shared_ptr<AnimatedCharacter> m_Mushroom;

    glm::vec2 position;
    glm::vec2 positionLand;

    std::shared_ptr<PhaseResourcesManager> m_PRM;

    int index=0;
    int indexTiles = 0;

    unsigned int cnt=0;

    unsigned long timenow = 0;
    unsigned long m_JumpBaseTime = 0;
    unsigned long m_Time=0.f;
    unsigned long m_MarioDiesTime = 0;
    unsigned long m_MarioStepTime = 0;
    unsigned long m_MarioHeadTime = 0;

    bool m_EnterDown = false;
    bool m_EnterRight = true;
    bool m_EnterLeft = false;
    bool m_Collide = false;
    bool isBrick = true;

    void callMarioForward();

    void callMarioBackward();

    void moveQuestionBox();

    void moveBrick();

    std::tuple<bool,glm::vec2> IsOnLand(std::shared_ptr<AnimatedCharacter>);

    bool IsCollideRight(std::shared_ptr<AnimatedCharacter> Object);

    bool IsCollideLeft(std::shared_ptr<AnimatedCharacter> Object);

    bool IsCollideUp();
};

#endif //SUPERMARIO1_APP_H
