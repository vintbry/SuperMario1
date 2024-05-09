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

    void Update(App *app) override;

    void End(App *app) override;

    void Restart(App *app);

private:

    bool pressed1= false ;
    bool pressed2=false;

    float speed=2;
    float powerjump =0.0f;
    float t =0;


    std::shared_ptr<Util::BGM> m_BGMusic;

    std::shared_ptr<Util::SFX> m_Mario_jump_audio;
    std::shared_ptr<Util::SFX> m_Mario_dead_audio;
    std::shared_ptr<Util::SFX> m_Mario_coin_audio;
    std::shared_ptr<Util::SFX> m_Mario_stomp_audio;
    std::shared_ptr<Util::SFX> m_Mario_bump_audio;
    std::shared_ptr<Util::SFX> m_Mario_levelFinish_audio;
    std::shared_ptr<Util::SFX> m_Mario_flagpole_audio;

    std::shared_ptr<TEXTS> m_title;

    std::shared_ptr<TEXTS> m_score;
    std::shared_ptr<TEXTS> m_coin;
    std::shared_ptr<TEXTS> m_world;
    std::shared_ptr<TEXTS> m_time;
    std::shared_ptr<TEXTS> m_popup;

    std::shared_ptr<MarioJump> m_Mario1;

    std::shared_ptr<BackgroundImage> m_Bg;

    std::shared_ptr<Character> m_Bg2;
    std::shared_ptr<Character> m_Pillar;
    std::shared_ptr<Character> m_Flag;

    std::shared_ptr<YellowMush> m_YellowMush;

    std::vector<std::shared_ptr<YellowMush>> m_YellowMushVec;

    std::vector<std::shared_ptr<Character>> m_DeadQues;
    std::vector<std::shared_ptr<Character>> m_Land;
    std::vector<std::shared_ptr<Character>> m_Brick;
    std::vector<std::shared_ptr<Character>> m_Tube;
    std::vector<std::shared_ptr<Character>> m_Wood;
    std::vector<std::shared_ptr<Character>> m_Castle;

    std::vector<std::shared_ptr<Koopa>> m_KoopaVec;

    std::vector<std::shared_ptr<QuestionTiles>> m_QuesVector;

    std::shared_ptr<QuestionTiles> m_Question;

    std::vector<std::shared_ptr<Mushroom>> m_MushVector;

    std::shared_ptr<Mario> m_Mario;
    std::shared_ptr<Mario> m_MarioPillar;
    std::shared_ptr<Mario> m_MarioBack;

    std::shared_ptr<Mushroom> m_Mushroom;

    std::shared_ptr<AnimatedCharacter> m_Coins;

    std::shared_ptr<Koopa> m_Koopa;

    glm::vec2 position;
    glm::vec2 positionLand;

    std::shared_ptr<PhaseResourcesManager> m_PRM;

    std::vector<std::string> MarioRun;
    std::vector<std::string> MarioRunLvl2;
    std::vector<std::string> MarioRunBack;
    std::vector<std::string> MarioRunBackLvl2;
    std::vector<std::string> MarioPillar;
    std::vector<std::string> MarioShrink;
    std::vector<std::string> Mushroom1;
    std::vector<std::string> QuestionMark;
    std::vector<std::string> Coins;
    std::vector<std::string> KoopaPic;
    std::vector<std::string> levelUp;
    std::vector<std::string> levelUpBack;
    std::vector<std::string> MarioBigFront;
    std::vector<std::string> MarioBigBack;

    int index=0;
    int index2=0;
    int indexTiles = 0;
    int indexTiles2 = 0;
    int indexMush = 0;

    float slideTime=0;
    float SpeedInAir=0;
    float y0= -172.0f;
    float h ;
    float max_jump=0;

    unsigned int cnt=0;
    unsigned int cnts=0;
    unsigned int time=1000 ;
    unsigned int score=0 ;
    unsigned int coin=0;

    unsigned long timenow = 0;
    unsigned long m_JumpBaseTime = 0;
    unsigned long m_MarioDiesTime = 0;
    unsigned long m_MarioStepTime = 0;
    unsigned long m_MarioHeadTime = 0;
    unsigned long m_MarioHeadTime2 = 0;
    unsigned long m_MarioHeadTime_yelmush = 0;

    bool m_EnterDown = false;
    bool m_EnterRight = true;
    bool m_EnterLeft = false;
    bool m_Collide = false;
    bool isBrick = true;
    bool isWinLevel = false;
    bool winSong = false;
    bool leftSlide = false;
    bool rightSlide = false;
    bool pressUp = false;

    void moveBackground(float position);

    void callMario();

    float searchLand(std::shared_ptr<AnimatedCharacter>);

    std::tuple<bool,glm::vec2> IsOnLand(const std::shared_ptr<AnimatedCharacter>&);

    std::tuple<bool,glm::vec2> IsOnLand(const std::shared_ptr<Character>&);

    glm::vec2 jumpFormula(float xvalue, float x0, float y0, float v0, float t);

    bool IsCollideRight(const std::shared_ptr<AnimatedCharacter>& Object);

    bool IsCollideLeft(const std::shared_ptr<AnimatedCharacter>& Object);

    bool IsCollideUp();
};

#endif //SUPERMARIO1_FIRSTWORLDONE_H
