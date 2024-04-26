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
    std::shared_ptr<Util::SFX> m_Mario_coin_audio;
    std::shared_ptr<Util::SFX> m_Mario_stomp_audio;
    std::shared_ptr<Util::SFX> m_Mario_bump_audio;
    std::shared_ptr<Util::SFX> m_Mario_levelFinish_audio;
    std::shared_ptr<Util::SFX> m_Mario_flagpole_audio;
    Util::Root m_Root;

    std::shared_ptr<MarioJump> m_Mario1;
    std::shared_ptr<Character> m_Bg;
    std::shared_ptr<Character> m_Pillar;
    std::shared_ptr<Character> m_Flag;

    std::vector<std::shared_ptr<Character>> m_DeadQues;
    std::vector<std::shared_ptr<Character>> m_Land;
    std::vector<std::shared_ptr<Character>> m_Brick;
    std::vector<std::shared_ptr<Character>> m_Tube;
    std::vector<std::shared_ptr<Character>> m_Wood;
    std::vector<std::shared_ptr<Character>> m_Castle;

    std::vector<std::shared_ptr<QuestionTiles>> m_QuesVector;

    std::shared_ptr<QuestionTiles> m_Question;

    std::vector<std::shared_ptr<AnimatedCharacter>> m_MushVector;

    std::shared_ptr<AnimatedCharacter> m_Mario;
    std::shared_ptr<AnimatedCharacter> m_MarioPillar;
    std::shared_ptr<AnimatedCharacter> m_MarioBack;
    std::shared_ptr<AnimatedCharacter> m_Mushroom;
    std::shared_ptr<AnimatedCharacter> m_Coins;

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
    bool isWinLevel = false;

    void moveBackground(float position);

    void callMarioForward();

    void callMarioBackward();

    std::tuple<bool,glm::vec2> IsOnLand(std::shared_ptr<AnimatedCharacter>);

    bool IsCollideRight(std::shared_ptr<AnimatedCharacter> Object);

    bool IsCollideLeft(std::shared_ptr<AnimatedCharacter> Object);

    bool IsCollideUp();


private:
    void RemoveRoot(std::vector<std::shared_ptr<Character>> Objects){
        for(const auto & i : Objects){
            m_Root.RemoveChild(i);
        }
    }
    void RemoveRoot(std::vector<std::shared_ptr<QuestionTiles>> Objects){
        for(const auto & i : Objects){
            m_Root.RemoveChild(i);
        }
    }

    void Restart() {
        // Resetting states
        m_CurrentState = State::START;
        m_Phase = Phase::FIRST_WORLD;

        m_Root.RemoveChild(m_Mario1);
        m_Root.RemoveChild(m_Bg);
        m_Root.RemoveChild(m_Pillar);
        m_Root.RemoveChild(m_Flag);
        m_Root.RemoveChild(m_Question);

        RemoveRoot(m_Land);
        RemoveRoot(m_Brick);
        RemoveRoot(m_Tube);
        RemoveRoot(m_Wood);
        RemoveRoot(m_Castle);

        RemoveRoot(m_QuesVector);

        m_Root.RemoveChild(m_Mario);
        m_Root.RemoveChild(m_MarioPillar);
        m_Root.RemoveChild(m_MarioBack);
        m_Root.RemoveChild(m_Mushroom);

        m_Root.RemoveChild(m_Question);


        // Resetting positions and game-specific flags
        position = glm::vec2(0, 0);
        positionLand = glm::vec2(0, 0);
        m_EnterDown = false;
        m_EnterRight = true;
        m_EnterLeft = false;
        m_Collide = false;
        isBrick = true;
        isWinLevel = false;

        // Resetting timers
        timenow = 0;
        m_JumpBaseTime = 0;
        m_Time = 0.f;
        m_MarioDiesTime = 0;
        m_MarioStepTime = 0;
        m_MarioHeadTime = 0;

        // Clearing all the vectors
        m_Land.clear();
        m_Brick.clear();
        m_Tube.clear();
        m_Wood.clear();
        m_Castle.clear();
        m_QuesVector.clear();
        m_MushVector.clear();

        // Reset audio components, if they have a reset method or similar
        m_BGMusic.reset();
        m_Mario_jump_audio.reset();
        m_Mario_dead_audio.reset();
        m_Mario_coin_audio.reset();
        m_Mario_stomp_audio.reset();
        m_Mario_bump_audio.reset();

        // Optionally, reinitialize or reload resources

        m_PRM.reset();



    }

};

#endif //SUPERMARIO1_APP_H
