//
// Created by Felicia Rulita on 2024/3/12.
//

#include "AnimatedCharacter.h"
#include "App.h"
#include "Character.h"
#include "Util/SFX.hpp"
#include "Util/Logger.hpp"
#include "Util/BGM.hpp"
#include "PhaseResourcesManager.h"


void App::Start(){
    LOG_TRACE("Start!");
    m_Mario_dead_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/mario-death.wav");
    m_Mario_jump_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/jump-small.wav");
    m_Mario_coin_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/coin.wav");
    m_Mario_stomp_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/enemy-stomp.wav");
    m_Mario_bump_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/bump.wav");
    m_Mario_levelFinish_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/level-clear.wav");
    //not implemented yet
    m_Mario_flagpole_audio = std::make_unique<Util::SFX>(GA_RESOURCE_DIR"/Audio/sound_effects/flagpole.wav");

    //text
    m_title =std::make_shared<TEXTS>( "SCORE                 COINS                 WORLD               TIME") ;
    m_title->SetZIndex(100);
    m_title ->SetVisible(true);
    m_title->SetPosition({0.0f,230.0f});
    m_Root.AddChild(m_title);

    m_score =std::make_shared<TEXTS>( "0") ;
    m_score->SetZIndex(100);
    m_score ->SetVisible(true);
    m_score->SetPosition({-250.0f,200.0f});
    m_Root.AddChild(m_score);

    m_coin =std::make_shared<TEXTS>( "0") ;
    m_coin->SetZIndex(100);
    m_coin ->SetVisible(true);
    m_coin->SetPosition({-80.0f,200.0f});
    m_Root.AddChild(m_coin);

    m_world =std::make_shared<TEXTS>( "1-1") ;
    m_world->SetZIndex(100);
    m_world ->SetVisible(true);
    m_world->SetPosition({110.0f,200.0f});
    m_Root.AddChild(m_world);

    m_time =std::make_shared<TEXTS>( "0") ;
    m_time->SetZIndex(100)
            ;   m_time ->SetVisible(true);
    m_time->SetPosition({270.0f,200.0f});
    m_Root.AddChild(m_time);

    m_popup =std::make_shared<TEXTS>( "100") ;
    m_popup->SetZIndex(100);
    m_popup ->SetVisible(false);
    m_popup->SetPosition({0.0f,0.0f});
    m_Root.AddChild(m_popup);

    //BGM
    m_BGMusic = std::make_unique<Util::BGM>(GA_RESOURCE_DIR"/Audio/BGMusic.mp3");
    //m_BGMusic->SetVolume(35);
    m_BGMusic->SetVolume(0);
    m_BGMusic->Play();

    //Bg
    m_Bg = std::make_shared<Character>(GA_RESOURCE_DIR"/Background/bg2.png");
    m_Bg->SetZIndex(2);
    m_Bg->SetVisible(true);
    m_Bg->SetPosition({3235.0f,-20.0f});

    m_Root.AddChild(m_Bg);


    //Mario Jump
    m_Mario1 = std::make_shared<MarioJump>(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    m_Mario1->SetZIndex(50);
    m_Mario1->SetVisible(false);

   // m_audio_mario_small_jump.LoadMedia(GA_RESOURCE_DIR"/Audio/small_mario_jump.wav");

    m_Root.AddChild(m_Mario1);

    //Mario run forward
    MarioRun.reserve(5);
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    for(int i = 0; i < 3; i++){
        MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    m_Mario = std::make_shared<Mario>(MarioRun);
    m_Mario->SetPosition({-265.0f, -172.0f});
    m_Mario->SetInterval(100);
    m_Mario->SetZIndex(50);
    m_Mario->SetVisible(true);
    m_Root.AddChild(m_Mario);

    //Mario run backward
    MarioRunBack.reserve(5);
    MarioRunBack.emplace_back(GA_RESOURCE_DIR"/Mario/marioBack.png");
    for(int i=0; i < 3; i++){
        MarioRunBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+std::to_string(i)+"_back.png");
    }
    MarioRunBack.emplace_back(GA_RESOURCE_DIR"/Mario/marioBack.png");

    m_MarioBack = std::make_shared<Mario>(MarioRunBack);
    m_MarioBack->SetInterval(100);
    m_MarioBack->SetZIndex(50);
    m_MarioBack->SetVisible(false);
    m_Root.AddChild(m_MarioBack);

    //mario pillar
    MarioPillar.reserve(2);
    MarioPillar.emplace_back(GA_RESOURCE_DIR"/Mario/mario_end.png");
    MarioPillar.emplace_back(GA_RESOURCE_DIR"/Mario/mario_end1.png");

    m_MarioPillar = std::make_shared<Mario>(MarioPillar);
    m_MarioPillar->SetInterval(100);
    m_MarioPillar->SetZIndex(50);
    m_MarioPillar->SetVisible(false);
    m_MarioPillar->SetLooping(true);
    m_MarioPillar->SetPlaying();
    m_Root.AddChild(m_MarioPillar);

    //mushroom
    Mushroom1.reserve(2);
    for(int i=0;i<2;i++){
        Mushroom1.emplace_back(GA_RESOURCE_DIR"/images/goombas_"+std::to_string(i)+".png");
    }

    for(int i=0;i<17;i++){
        m_Mushroom = std::make_shared<Mushroom>(Mushroom1);
        m_Mushroom->SetLooping(true);
        m_Mushroom->SetPlaying();
        m_Mushroom->SetZIndex(5);
        m_Mushroom->SetVisible(true);
        m_MushVector.push_back(m_Mushroom);

    }
    m_MushVector[16]->SetPosition({-400.0f,-172.0f});

    m_MushVector[0]->SetPosition({355.0f,-172.0f});
    m_MushVector[1]->SetPosition({933.0f,-172.0f});
    m_MushVector[2]->SetPosition({1285.0f,-172.0f});
    m_MushVector[3]->SetPosition({1317.0f,-172.0f});

    m_MushVector[4]->SetPosition({2771.0f,-172.0f});
    m_MushVector[5]->SetPosition({2819.0f,-172.0f});
    m_MushVector[6]->SetPosition({3315.0f,-172.0f});
    m_MushVector[7]->SetPosition({3363.0f,-172.0f});
    m_MushVector[8]->SetPosition({3635.0f,-172.0f});
    m_MushVector[9]->SetPosition({3683.0f,-172.0f});
    m_MushVector[10]->SetPosition({3763.0f,-172.0f});
    m_MushVector[11]->SetPosition({3811.0f,-172.0f});

    m_MushVector[12]->SetPosition({5267.0f,-172.0f});
    m_MushVector[13]->SetPosition({5315.0f,-172.0f});

    m_MushVector[14]->SetPosition({2208.0f,72.0f});
    m_MushVector[15]->SetPosition({2256.0f,72.0f});


    for(int i=0;i<17;i++){
        m_Root.AddChild(m_MushVector[i]);
    }

    //koopa
    KoopaPic.reserve(2);
    for(int i = 0;i<2;i++){
        KoopaPic.emplace_back(GA_RESOURCE_DIR"/images/koopa_"+std::to_string(i)+".png");
    }
    for(int i=0;i<1;i++){
        m_Koopa = std::make_shared<Koopa>(KoopaPic);
        m_Koopa->SetInterval(100);
        m_Koopa->SetZIndex(5);
        m_Koopa->SetLooping(true);
        m_Koopa->SetPlaying();
        m_Koopa->SetVisible(true);
        m_KoopaVec.push_back(m_Koopa);

    }

    m_KoopaVec[0]->SetPosition({3507.0f,-169.0f});
    for(int i=0;i<1;i++){
        m_Root.AddChild(m_KoopaVec[i]);
    }


    //Background tiles
    for(int i = 0; i < 4; i++){
        m_Land.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tilesLong"+std::to_string(i)+".png"));
        m_Land[i]->SetZIndex(5);
        m_Land[i]->SetVisible(true);
        m_Root.AddChild(m_Land[i]);
    }
    m_Land[0]->SetPosition({740.0f,-220.0f});
    m_Land[1]->SetPosition({2150.0f,-220.0f});
    m_Land[2]->SetPosition({3538.0f,-220.0f});
    m_Land[3]->SetPosition({5746.0f,-220.0f});

    //In Air Tile
    //Question Mark

    QuestionMark.reserve(3);
    for(int i = 0;i < 3; i++){
        QuestionMark.emplace_back(GA_RESOURCE_DIR"/images/question"+std::to_string(i)+".png");
    }

    for(int i=0;i<14;i++){
        m_Question = std::make_shared<QuestionTiles>(QuestionMark);
        m_Question->SetLooping(true);
        m_Question->SetPlaying();
        m_Question->SetZIndex(5);
        m_Question->SetVisible(true);
        m_QuesVector.push_back(m_Question);

        m_QuesVector[i]->SetZIndex(5);
        m_QuesVector[i]->SetVisible(true);


    }
    //set position
    m_QuesVector[0]->SetPosition({163.0f,-82.0f});
    m_QuesVector[1]->SetPosition({323.0f,-82.0f});
    m_QuesVector[2]->SetPosition({355.0f,40.0f});
    m_QuesVector[3]->SetPosition({387.0f,-82.0f});
    m_QuesVector[4]->SetPosition({1696.0f,-52.0f});

    m_QuesVector[5]->SetPosition({2144.0f,-82.0f});

    m_QuesVector[6]->SetPosition({2675.0f,40.0f});
    m_QuesVector[7]->SetPosition({3059.0f,-82.0f});
    m_QuesVector[8]->SetPosition({3155.0f,-82.0f});
    m_QuesVector[9]->SetPosition({3155.0f,40.0f});
    m_QuesVector[10]->SetPosition({3251.0f,-82.0f});
    m_QuesVector[11]->SetPosition({3795.0f,40.0f});
    m_QuesVector[12]->SetPosition({3827.0f,40.0f});
    m_QuesVector[13]->SetPosition({5139.0f,-82.0f});

    for(int i=0;i<14;i++){
        m_Root.AddChild(m_QuesVector[i]);
    }

    //dead brick
    for(int i=0;i<14;i++) {
        m_DeadQues.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/deadQues.png"));
        m_DeadQues[i]->SetZIndex(5);
        m_DeadQues[i]->SetVisible(false);
        m_Root.AddChild(m_DeadQues[i]);
    }

    //brick
    for(int i = 0;i<31;i++){
        m_Brick.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/inAir1.png"));
        m_Brick[i]->SetZIndex(5);
        m_Brick[i]->SetVisible(true);
        m_Root.AddChild(m_Brick[i]);
    }
    m_Brick[0]->SetPosition({291.0f,-82.0f});
    m_Brick[1]->SetPosition({355.0f,-82.0f});
    m_Brick[2]->SetPosition({419.0f,-82.0f});
    m_Brick[3]->SetPosition({2112.0f,-82.0f});
    m_Brick[4]->SetPosition({2176.0f,-82.0f});
    m_Brick[5]->SetPosition({2208.0f,40.0f});
    m_Brick[6]->SetPosition({2240.0f,40.0f});
    m_Brick[7]->SetPosition({2272.0f,40.0f});
    m_Brick[8]->SetPosition({2304.0f,40.0f});
    m_Brick[9]->SetPosition({2336.0f,40.0f});
    m_Brick[10]->SetPosition({2368.0f,40.0f});
    m_Brick[11]->SetPosition({2400.0f,40.0f});
    m_Brick[12]->SetPosition({2432.0f,40.0f});
    m_Brick[13]->SetPosition({2464.0f,40.0f});

    m_Brick[14]->SetPosition({2579.0f,40.0f});
    m_Brick[15]->SetPosition({2611.0f,40.0f});
    m_Brick[16]->SetPosition({2643.0f,40.0f});
    m_Brick[17]->SetPosition({2675.0f,-82.0f});
    m_Brick[18]->SetPosition({2867.0f,-82.0f});
    m_Brick[19]->SetPosition({2899.0f,-82.0f});

    m_Brick[20]->SetPosition({3443.0f,-82.0f});
    m_Brick[21]->SetPosition({3539.0f,40.0f});
    m_Brick[22]->SetPosition({3571.0f,40.0f});
    m_Brick[23]->SetPosition({3763.0f,40.0f});
    m_Brick[24]->SetPosition({3859.0f,40.0f});
    m_Brick[25]->SetPosition({3795.0f,-82.0f});
    m_Brick[26]->SetPosition({3827.0f,-82.0f});
    m_Brick[27]->SetPosition({5075.0f,-82.0f});
    m_Brick[28]->SetPosition({5107.0f,-82.0f});
    m_Brick[29]->SetPosition({5171.0f,-82.0f});

    m_Brick[30]->SetVisible(false);

    for(int i = 0;i<31;i++){
        m_Root.AddChild(m_Brick[i]);
    }

    //Tube
    for(int i=0;i<6;i++){
        m_Tube.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tube.png"));
        m_Tube[i]->SetZIndex(4);
        m_Tube[i]->SetVisible(true);

    }
    m_Tube[0]->SetPosition({565.0f,-380.0f});
    m_Tube[1]->SetPosition({885.0f,-350.0f});
    m_Tube[2]->SetPosition({1141.0f,-310.0f});
    m_Tube[3]->SetPosition({1493.0f,-310.0f});

    m_Tube[4]->SetPosition({4931.0f,-380.0f});
    m_Tube[5]->SetPosition({5443.0f,-380.0f});


    for(int i=0;i<6;i++){
        m_Root.AddChild(m_Tube[i]);
    }

    //wood
    for(int i=0;i<26;i++){
        m_Wood.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/wood.png"));
        m_Wood[i]->SetZIndex(4);
        m_Wood[i]->SetVisible(false);
    }

    m_Wood[0]->SetPosition({3955.0f,-172.0f});
    m_Wood[1]->SetPosition({3987.0f,-140.0f});
    m_Wood[2]->SetPosition({4019.0f,-108.0f});
    m_Wood[3]->SetPosition({4052.0f,-124.0f});
    m_Wood[3]->SetImage(GA_RESOURCE_DIR"/images/woodbig3.png");

    m_Wood[4]->SetPosition({4147.0f, -124.0f});
    m_Wood[4]->SetImage(GA_RESOURCE_DIR"/images/woodbig3.png");
    m_Wood[5]->SetPosition({4179.0f,-108.0f});
    m_Wood[6]->SetPosition({4211.0f,-140.0f});
    m_Wood[7]->SetPosition({4243.0f,-172.0f});

    m_Wood[8]->SetPosition({4435.0f,-172.0f});
    m_Wood[9]->SetPosition({4467.0f,-140.0f});
    m_Wood[10]->SetPosition({4499.0f,-108.0f});
    m_Wood[11]->SetPosition({4531.0f,-76.0f});
    m_Wood[12]->SetPosition({4563.0f,-124.0f});
    m_Wood[12]->SetImage(GA_RESOURCE_DIR"/images/woodbig3.png");

    m_Wood[13]->SetPosition({4659.0f,-124.0f});
    m_Wood[13]->SetImage(GA_RESOURCE_DIR"/images/woodbig3.png");
    m_Wood[14]->SetPosition({4691.0f,-108.0f});
    m_Wood[15]->SetPosition({4723.0f,-140.0f});
    m_Wood[16]->SetPosition({4755.0f,-172.0f});

    m_Wood[17]->SetPosition({5491.0f,-172.0f});
    m_Wood[18]->SetPosition({5532.0f,-140.0f});
    m_Wood[19]->SetPosition({5555.0f,-108.0f});
    m_Wood[20]->SetPosition({5587.0f,-76.0f});
    m_Wood[21]->SetPosition({5619.0f,-44.0f});
    m_Wood[22]->SetPosition({5651.0f,-12.0f});
    m_Wood[23]->SetPosition({5683.0f, 20.0f});

    m_Wood[24]->SetPosition({5731.0f,-60.0f});
    m_Wood[24]->SetImage(GA_RESOURCE_DIR"/images/woodBig4.png");

    m_Wood[25]->SetPosition({6035.0f,-172.0f});
    m_Wood[25]->SetVisible(true);

    for(int i=0;i<26;i++){
        m_Root.AddChild(m_Wood[i]);
    }

    //pillar and flag
    m_Pillar = std::make_shared<Character>(GA_RESOURCE_DIR"/images/flag_pillar.png");
    m_Pillar->SetZIndex(4);
    m_Pillar->SetVisible(true);
    m_Pillar->SetPosition({6035.0f,-6.0f});
    m_Root.AddChild(m_Pillar);

    m_Flag = std::make_shared<Character>(GA_RESOURCE_DIR"/images/flag.png");
    m_Flag->SetZIndex(4);
    m_Flag->SetVisible(true);
    m_Flag->SetPosition({6019.0f,110.0f});
    m_Root.AddChild(m_Flag);

    //castle
    for(int i = 0; i < 2; i++){
        m_Castle.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/blackCastle.png"));
        m_Castle[i]->SetZIndex(100);
        m_Castle[i]->SetVisible(true);
        m_Castle[i]->SetPosition({6547.0f,-172.0f + (i*32.0f)});
        m_Root.AddChild(m_Castle[i]);
    }


    m_PRM = std::make_shared<PhaseResourcesManager>();
    m_Root.AddChildren(m_PRM->GetChildren());

    //Coins
    Coins.reserve(3);
    for(int i = 0 ; i < 3 ; i++){
        Coins.emplace_back(GA_RESOURCE_DIR"/images/coin_an"+std::to_string(i)+".png");
    }

    m_Coins = std::make_shared<AnimatedCharacter>(Coins);
    m_Coins->SetInterval(100);
    m_Coins->SetZIndex(3);
    m_Coins->SetVisible(false);
    m_Coins->SetLooping(true);
    m_Coins->SetPlaying();
    m_Coins->SetPosition({-1000.0f,-1000.0f});
    m_Root.AddChild(m_Coins);

    //level up mush
    for(int i=0;i<4;i++){
        m_YellowMush = std::make_shared<YellowMush>(GA_RESOURCE_DIR"/images/mushroom.png");
        m_YellowMush->SetZIndex(3);
        m_YellowMush->SetVisible(false);
        m_YellowMush->SetPosition({-1000.0f,-1000.0f});

        m_YellowMushVec.push_back(m_YellowMush);

    }

    for(int i=0;i<4;i++){
        m_Root.AddChild(m_YellowMushVec[i]);
    }


    levelUp.reserve(6);
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlup.png");
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlup.png");
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario1.png");
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlup.png");
    levelUp.emplace_back(GA_RESOURCE_DIR"/Mario/mario1.png");

    levelUpBack.reserve(6);
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlupBack.png");
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/marioBack.png");
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlupBack.png");
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario1Back.png");
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_lvlupBack.png");
    levelUpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario1Back.png");

    MarioRunLvl2.reserve(5);
    MarioRunLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1.png");
    for(int i=0;i<3;i++){
        MarioRunLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_move"+std::to_string(i)+".png");
    }
    MarioRunLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1.png");

    MarioRunBackLvl2.reserve(5);
    MarioRunBackLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1Back.png");
    for(int i=0;i<3;i++){
        MarioRunBackLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_move"+std::to_string(i)+"Back.png");
    }
    MarioRunBackLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1Back.png");


    m_CurrentState=State::UPDATE;

}