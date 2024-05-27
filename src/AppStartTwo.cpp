//
// Created by Felicia Rulita on 2024/5/14.
//

#include "AnimatedCharacter.h"
#include "FirstWorldTwo.h"
#include "Character.h"
#include "Util/SFX.hpp"
#include "Util/Logger.hpp"
#include "Util/BGM.hpp"
#include "PhaseResourcesManager.h"

void FirstWorldTwo::Start(App *app) {
    LOG_TRACE("Start Second World!");

    m_Bg = std::make_shared<BackgroundImage>(GA_RESOURCE_DIR"/Background/WorldTwoBegin.png");

    app->m_Root.AddChild(m_Bg);

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
    app->m_Root.AddChild(m_Mario);

    m_TubeBig = std::make_shared<Character>(GA_RESOURCE_DIR"/images/bigTube1.png");
    m_TubeBig->SetPosition({103.0f,-110.0f});
    m_TubeBig->SetZIndex(100);
    m_TubeBig->SetVisible(true);
    app->m_Root.AddChild(m_TubeBig);

    marioStart = false;

    app->m_Root.Update();
    SetState(State::STARTLEVEL);

}

void FirstWorldTwo::StartLevel(App *app) {
    LOG_DEBUG("msk start level");

    m_Mario->SetPosition({m_Mario->GetPosition().x + 3.0f, m_Mario->GetPosition().y});
    m_Mario->SetPlaying();

    LOG_DEBUG(m_Mario->GetPosition().x);

    //next state
    if(m_Mario->GetPosition().x > 150){
        Restart(app);
        SetState(State::STARTLEVEL2);
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        SetState(State::END);

    }

    app->m_Root.Update();
}
void FirstWorldTwo::StartLevel2(App *app) {
    m_Bg1 = std::make_shared<BackgroundImage>(GA_RESOURCE_DIR"/Background/bg1.png");
    app->m_Root.AddChild(m_Bg1);

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
    app->m_Root.AddChild(m_title);

    m_score =std::make_shared<TEXTS>( "0") ;
    m_score->SetZIndex(100);
    m_score ->SetVisible(true);
    m_score->SetPosition({-250.0f,200.0f});
    app->m_Root.AddChild(m_score);

    m_coin =std::make_shared<TEXTS>( "0") ;
    m_coin->SetZIndex(100);
    m_coin ->SetVisible(true);
    m_coin->SetPosition({-80.0f,200.0f});
    app->m_Root.AddChild(m_coin);

    m_world =std::make_shared<TEXTS>( "1-2") ;
    m_world->SetZIndex(100);
    m_world ->SetVisible(true);
    m_world->SetPosition({110.0f,200.0f});
    app->m_Root.AddChild(m_world);

    m_time =std::make_shared<TEXTS>( "0") ;
    m_time->SetZIndex(100);
    m_time ->SetVisible(true);
    m_time->SetPosition({270.0f,200.0f});
    app->m_Root.AddChild(m_time);

    m_popup =std::make_shared<TEXTS>( "100") ;
    m_popup->SetZIndex(100);
    m_popup ->SetVisible(false);
    m_popup->SetPosition({0.0f,0.0f});
    app->m_Root.AddChild(m_popup);

    //BGM
    m_BGMusic = std::make_unique<Util::BGM>(GA_RESOURCE_DIR"/Audio/BGMusic.mp3");
    //m_BGMusic->SetVolume(35);
    m_BGMusic->SetVolume(0);
    m_BGMusic->Play();

    //Bg
    m_Bg2 = std::make_shared<Character>(GA_RESOURCE_DIR"/Background/bg_World2.png");
    m_Bg2->SetZIndex(2);
    m_Bg2->SetVisible(true);
    m_Bg2->SetPosition({3235.0f,-20.0f});

    app->m_Root.AddChild(m_Bg2);


    //Mario Jump
    MarioJump.reserve(2);
    MarioJump.emplace_back(GA_RESOURCE_DIR"/Mario/mario_jump.png");
    MarioJump.emplace_back(GA_RESOURCE_DIR"/Mario/mario_jump.png");

    //Mario jump back
    MarioJumpBack.reserve(2);
    MarioJumpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");
    MarioJumpBack.emplace_back(GA_RESOURCE_DIR"/Mario/mario_jumpBack.png");

    MarioJumpLvl2.reserve(2);
    MarioJumpLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_jump.png");
    MarioJumpLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_jump.png");

    MarioJumpBackLvl2.reserve(2);
    MarioJumpBackLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_jumpBack.png");
    MarioJumpBackLvl2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_jumpBack.png");

    MarioPillarEnd.reserve(1);
    MarioPillarEnd.emplace_back(GA_RESOURCE_DIR"/Mario/mario_endBack.png");

    MarioPillarEnd2.reserve(1);
    MarioPillarEnd2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_endBack.png");

    //Mario run forward
    MarioRun.reserve(5);
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    for(int i = 0; i < 3; i++){
        MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario_move"+ std::to_string(i)+ ".png");
    }
    MarioRun.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    m_Mario = std::make_shared<Mario>(MarioRun);
    m_Mario->SetPosition({-265.0f, 200.0f});
    m_Mario->SetInterval(100);
    m_Mario->SetZIndex(50);
    m_Mario->SetVisible(true);
    app->m_Root.AddChild(m_Mario);

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
    app->m_Root.AddChild(m_MarioBack);

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
    app->m_Root.AddChild(m_MarioPillar);

    MarioPillar2.reserve(2);
    MarioPillar2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_end1.png");
    MarioPillar2.emplace_back(GA_RESOURCE_DIR"/Mario/mario1_end.png");

    //mario shrink
    MarioShrink.reserve(52);
    for(int i=0;i<8;i++){
        MarioShrink.emplace_back(GA_RESOURCE_DIR"/Mario/MarioShrink1.png");
    }
    for(int i=0;i<8;i++){
        MarioShrink.emplace_back(GA_RESOURCE_DIR"/Mario/MarioShrink2.png");
    }
    for(int i=0;i<36;i++){
        MarioShrink.emplace_back(GA_RESOURCE_DIR"/Mario/mario.png");
    }

    //mushroom
    Mushroom1.reserve(2);
    for(int i=0;i<2;i++){
        Mushroom1.emplace_back(GA_RESOURCE_DIR"/images/goombas_"+std::to_string(i)+".png");
    }

    for(int i=0;i<14;i++){
        m_Mushroom = std::make_shared<Mushroom>(Mushroom1);
        m_Mushroom->SetLooping(true);
        m_Mushroom->SetPlaying();
        m_Mushroom->SetZIndex(5);
        m_Mushroom->SetVisible(false);
        m_MushVector.push_back(m_Mushroom);

        app->m_Root.AddChild(m_MushVector[i]);

    }
    m_MushVector[0]->SetPosition({131.0f,-172.0f});
    m_MushVector[1]->SetPosition({163.0f,-140.0f});
    m_MushVector[2]->SetPosition({543.0f,-172.0f});

    m_MushVector[3]->SetPosition({1663.0f,-172.0f});

    m_MushVector[4]->SetPosition({2015.0f,86.0f});

    m_MushVector[5]->SetPosition({2111.0f,-42.0f});
    m_MushVector[6]->SetPosition({2143.0f,-42.0f});

    m_MushVector[7]->SetPosition({2915.0f,-172.0f});
    m_MushVector[8]->SetPosition({2883.0f,-172.0f});
    m_MushVector[9]->SetPosition({2851.0f,-172.0f});

    m_MushVector[10]->SetPosition({3997.0f,-76.0f});
    m_MushVector[11]->SetPosition({4045.0f,-44.0f});

    m_MushVector[12]->SetPosition({5267.0f,-172.0f});
    m_MushVector[13]->SetPosition({5315.0f,-172.0f});


    //koopa
    KoopaPic.reserve(2);
    for(int i = 0;i<2;i++){
        KoopaPic.emplace_back(GA_RESOURCE_DIR"/images/koopa_"+std::to_string(i)+".png");
    }
    for(int i=0;i<3;i++){
        m_Koopa = std::make_shared<Koopa>(KoopaPic);
        m_Koopa->SetInterval(100);
        m_Koopa->SetZIndex(5);
        m_Koopa->SetLooping(true);
        m_Koopa->SetPlaying();
        m_Koopa->SetVisible(false);
        m_KoopaVec.push_back(m_Koopa);
        app->m_Root.AddChild(m_KoopaVec[i]);

    }

    m_KoopaVec[0]->SetPosition({1055.0f,-169.0f});
    m_KoopaVec[1]->SetPosition({1087.0f,-169.0f});

    m_KoopaVec[2]->SetPosition({1567.0f,-169.0f});


    KoopaBack.reserve(2);
    KoopaBack.emplace_back(GA_RESOURCE_DIR"/images/koopa_0Back.png");
    KoopaBack.emplace_back(GA_RESOURCE_DIR"/images/koopa_1Back.png");

    //Background tiles
    for(int i = 1; i <= 6; i++){
        m_Land.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/landLongWorld2_"+std::to_string(i)+".png"));
        m_Land[i-1]->SetZIndex(5);
        m_Land[i-1]->SetVisible(true);
        app->m_Root.AddChild(m_Land[i-1]);
    }
    m_Land[0]->SetPosition({918.0f,-220.0f});
    m_Land[1]->SetPosition({2900.0f,-220.0f});
    m_Land[2]->SetPosition({3597.0f,-220.0f});
    m_Land[3]->SetPosition({3885.0f,-220.0f});
    m_Land[4]->SetPosition({4468.0f,-220.0f});
    m_Land[5]->SetPosition({5044.0f,-220.0f});

    //In Air Tile
    //Question Mark

    QuestionMark.reserve(3);
    for(int i = 0;i < 3; i++){
        QuestionMark.emplace_back(GA_RESOURCE_DIR"/images/question"+std::to_string(i)+".png");
    }

    for(int i=0;i<5;i++){
        m_Question = std::make_shared<QuestionTiles>(QuestionMark);
        m_Question->SetLooping(true);
        m_Question->SetPlaying();
        m_Question->SetZIndex(5);
        m_Question->SetVisible(false);
        m_QuesVector.push_back(m_Question);

        m_QuesVector[i]->SetZIndex(5);
        m_QuesVector[i]->SetVisible(false);

        app->m_Root.AddChild(m_QuesVector[i]);
    }
    //set position
    m_QuesVector[0]->SetPosition({-61.0f,-82.0f});
    m_QuesVector[0]->isMushInside = true;
    m_QuesVector[0]->indexMush = 0;
    m_QuesVector[1]->SetPosition({-29.0f,-82.0f});
    m_QuesVector[2]->SetPosition({3.0f,-82.0f});
    m_QuesVector[3]->SetPosition({35.0f,-82.0f});
    m_QuesVector[4]->SetPosition({67.0f,-82.0f});



    //dead brick
    for(int i=0;i<14;i++) {
        m_DeadQues.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/deadQues.png"));
        m_DeadQues[i]->SetZIndex(5);
        m_DeadQues[i]->SetVisible(false);
        app->m_Root.AddChild(m_DeadQues[i]);
    }

    //brick
    for(int i = 0;i<255;i++){
        m_Brick.push_back(std::make_shared<Brick>(GA_RESOURCE_DIR"/images/tilesWorld2_1.png"));
        m_Brick[i]->SetZIndex(5);
        m_Brick[i]->SetVisible(false);
        app->m_Root.AddChild(m_Brick[i]);
    }
    m_Brick[0]->SetPosition({575.0f,-42.0f});

    m_Brick[1]->SetPosition({895.0f,-74.0f});
    m_Brick[2]->SetPosition({895.0f,-42.0f});
    m_Brick[3]->SetPosition({895.0f,-10.0f});

    m_Brick[4]->SetPosition({927.0f,-74.0f}); //927

    m_Brick[5]->SetPosition({959.0f,-74.0f}); //959
    m_Brick[6]->SetPosition({959.0f,-42.0f});
    m_Brick[7]->SetPosition({959.0f,-10.0f});

    m_Brick[8]->SetPosition({991.0f,-10.0f});
    m_Brick[9]->SetPosition({1023.0f,-10.0f});

    m_Brick[10]->SetPosition({1055.0f,-10.0f});
    m_Brick[11]->SetPosition({1055.0f,-42.0f});
    m_Brick[12]->SetPosition({1055.0f,-74.0f});

    m_Brick[13]->SetPosition({1087.0f,-74.0f});

    m_Brick[14]->SetPosition({1119.0f,-74.0f});
    m_Brick[15]->SetPosition({1119.0f,-42.0f});
    m_Brick[16]->SetPosition({1119.0f,-10.0f});

    m_Brick[17]->SetPosition({1311.0f,-74.0f});
    m_Brick[18]->SetPosition({1311.0f,-42.0f});
    m_Brick[19]->SetPosition({1311.0f,-10.0f});
    m_Brick[20]->SetPosition({1311.0f,22.0f});
    m_Brick[21]->SetPosition({1311.0f,54.0f});

    m_Brick[22]->SetPosition({1343.0f,-74.0f});
    m_Brick[23]->SetPosition({1343.0f,-42.0f});
    m_Brick[24]->SetPosition({1343.0f,-10.0f});
    m_Brick[25]->SetPosition({1343.0f,22.0f});
    m_Brick[26]->SetPosition({1343.0f,54.0f});

    m_Brick[27]->SetPosition({1375.0f,-74.0f});
    m_Brick[28]->SetPosition({1375.0f,-106.0f});
    m_Brick[29]->SetPosition({1375.0f,-138.0f});

    m_Brick[30]->SetPosition({1407.0f,-74.0f});
    m_Brick[31]->SetPosition({1407.0f,-106.0f});
    m_Brick[32]->SetPosition({1407.0f,-138.0f});

    m_Brick[33]->SetPosition({1535.0f,-74.0f});
    m_Brick[34]->SetPosition({1567.0f,-74.0f});
    m_Brick[35]->SetPosition({1599.0f,-74.0f});
    m_Brick[36]->SetPosition({1631.0f,-74.0f});

    m_Brick[37]->SetPosition({1663.0f,-74.0f});
    m_Brick[38]->SetPosition({1663.0f,-42.0f});
    m_Brick[39]->SetPosition({1663.0f,-10.0f});
    m_Brick[40]->SetPosition({1663.0f,22.0f});
    m_Brick[41]->SetPosition({1663.0f,54.0f});

    m_Brick[42]->SetPosition({1695.0f,-74.0f});
    m_Brick[43]->SetPosition({1695.0f,-42.0f});
    m_Brick[44]->SetPosition({1695.0f,-10.0f});
    m_Brick[45]->SetPosition({1695.0f,22.0f});
    m_Brick[46]->SetPosition({1695.0f,54.0f});

    m_Brick[47]->SetPosition({1823.0f,-74.0f});
    m_Brick[48]->SetPosition({1823.0f,-42.0f});
    m_Brick[49]->SetPosition({1823.0f,-10.0f});
    m_Brick[50]->SetPosition({1823.0f,22.0f});
    m_Brick[51]->SetPosition({1823.0f,54.0f});

    m_Brick[52]->SetPosition({1855.0f,-74.0f});
    m_Brick[53]->SetPosition({1887.0f,-74.0f});
    m_Brick[54]->SetPosition({1887.0f,-42.0f});

    m_Brick[55]->SetPosition({1983.0f,-74.0f});
    m_Brick[56]->SetPosition({1983.0f,-42.0f});
    m_Brick[57]->SetPosition({1983.0f,-10.0f});
    m_Brick[58]->SetPosition({1983.0f,22.0f});
    m_Brick[59]->SetPosition({1983.0f,54.0f});

    m_Brick[60]->SetPosition({2015.0f,-74.0f});
    m_Brick[61]->SetPosition({2015.0f,-42.0f});
    m_Brick[62]->SetPosition({2015.0f,-10.0f});
    m_Brick[63]->SetPosition({2015.0f,22.0f});
    m_Brick[64]->SetPosition({2015.0f,54.0f});

    m_Brick[65]->SetPosition({2111.0f,-74.0f});
    m_Brick[66]->SetPosition({2143.0f,-74.0f});
    m_Brick[67]->SetPosition({2175.0f,-74.0f});

    m_Brick[68]->SetPosition({2355.0f,-74.0f});
    m_Brick[69]->SetPosition({2355.0f,-42.0f});

    m_Brick[70]->SetPosition({2387.0f,-74.0f});
    m_Brick[71]->SetPosition({2387.0f,-42.0f});

    m_Brick[72]->SetPosition({2419.0f,-74.0f});
    m_Brick[73]->SetPosition({2419.0f,-42.0f});

    m_Brick[74]->SetPosition({2451.0f,-74.0f});
    m_Brick[75]->SetPosition({2451.0f,-42.0f});

    m_Brick[76]->SetPosition({2483.0f,-74.0f});
    m_Brick[77]->SetPosition({2483.0f,-42.0f});

    m_Brick[78]->SetPosition({2515.0f,-74.0f});
    m_Brick[79]->SetPosition({2515.0f,-42.0f});
    //on the ground no need to give brick_break
    m_Brick[80]->SetPosition({3581.0f,-172.0f});
    m_Brick[81]->SetPosition({3581.0f,-140.0f});
    m_Brick[82]->SetPosition({3581.0f,-108.0f});

    m_Brick[83]->SetPosition({3613.0f,-172.0f});
    m_Brick[84]->SetPosition({3613.0f,-140.0f});
    m_Brick[85]->SetPosition({3613.0f,-108.0f});
    //

    m_Brick[86]->SetPosition({4356.0f,-106.0f});
    m_Brick[87]->SetPosition({4388.0f,-106.0f});
    m_Brick[88]->SetPosition({4420.0f,-106.0f});
    m_Brick[89]->SetPosition({4452.0f,-106.0f});
    m_Brick[90]->SetPosition({4484.0f,-106.0f});
    m_Brick[91]->SetPosition({4516.0f,-106.0f});

    //connecting the upper brick
    for(int i=0;i<2;i++){
        m_Brick[92+i]->SetPosition({1375.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[94+i]->SetPosition({1407.0f,86.0f+(32.0f*i)});
    }

    for(int i=0;i<2;i++){
        m_Brick[96+i]->SetPosition({1535.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[98+i]->SetPosition({1567.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[100+i]->SetPosition({1599.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[102+i]->SetPosition({1631.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[104+i]->SetPosition({1663.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[106+i]->SetPosition({1695.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[108+i]->SetPosition({1791.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[110+i]->SetPosition({1823.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[112+i]->SetPosition({1855.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[114+i]->SetPosition({1887.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[116+i]->SetPosition({2111.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[118+i]->SetPosition({2143.0f,86.0f+(32.0f*i)});
    }
    for(int i=0;i<2;i++){
        m_Brick[120+i]->SetPosition({2175.0f,86.0f+(32.0f*i)});
    }

    //upper brick
    for(int i=0;i<133;i++){
        m_Brick[122+i]->SetPosition({-160.0f+(32.0f*i),150.0f});
    }

    //m_Brick[255]->SetPosition({5044.0f,})

    //brick_break
    //should be adjusted
    m_Brick_break.resize(261);
    for (int i = 0; i < 261; ++i) {
        m_Brick_break[i].resize(5);
    }
    for(int i = 0;i<261;i++){
        for (int x =0 ; x<5 ;x++) {
            const auto BrickBreak = std::make_shared<Brick>(GA_RESOURCE_DIR"/images/block_debris0.png");
            BrickBreak->SetZIndex(100);
            BrickBreak->SetVisible(false);
            app->m_Root.AddChild(BrickBreak);
            m_Brick_break[i][x] = BrickBreak;

        }
    }
    for (int i =0 ; i<5 ; i++) {
        LOG_DEBUG("for2");
        m_Brick_break[0][i]->SetPosition({575.0f, -42.0f});

        m_Brick_break[1][i]->SetPosition({895.0f, -74.0f});
        m_Brick_break[2][i]->SetPosition({895.0f, -42.0f});
        m_Brick_break[3][i]->SetPosition({895.0f, -10.0f});

        m_Brick_break[4][i]->SetPosition({927.0f, -74.0f});

        m_Brick_break[5][i]->SetPosition({959.0f, -74.0f});
        m_Brick_break[6][i]->SetPosition({959.0f, -42.0f});
        m_Brick_break[7][i]->SetPosition({959.0f, -10.0f});

        m_Brick_break[8][i]->SetPosition({991.0f, -10.0f});
        m_Brick_break[9][i]->SetPosition({1023.0f, -10.0f});

        m_Brick_break[10][i]->SetPosition({1055.0f, -10.0f});
        m_Brick_break[11][i]->SetPosition({1055.0f, -42.0f});
        m_Brick_break[12][i]->SetPosition({1055.0f, -74.0f});

        m_Brick_break[13][i]->SetPosition({1087.0f, -74.0f});

        m_Brick_break[14][i]->SetPosition({1119.0f, -74.0f});
        m_Brick_break[15][i]->SetPosition({1119.0f, -42.0f});
        m_Brick_break[16][i]->SetPosition({1119.0f, -10.0f});

        m_Brick_break[17][i]->SetPosition({1311.0f, -74.0f});
        m_Brick_break[18][i]->SetPosition({1311.0f, -42.0f});
        m_Brick_break[19][i]->SetPosition({1311.0f, -10.0f});
        m_Brick_break[20][i]->SetPosition({1311.0f, 22.0f});
        m_Brick_break[21][i]->SetPosition({1311.0f, 54.0f});

        m_Brick_break[22][i]->SetPosition({1343.0f, -74.0f});
        m_Brick_break[23][i]->SetPosition({1343.0f, -42.0f});
        m_Brick_break[24][i]->SetPosition({1343.0f, -10.0f});
        m_Brick_break[25][i]->SetPosition({1343.0f, 22.0f});
        m_Brick_break[26][i]->SetPosition({1343.0f, 54.0f});

        m_Brick_break[27][i]->SetPosition({1375.0f, -74.0f});
        m_Brick_break[28][i]->SetPosition({1375.0f, -106.0f});
        m_Brick_break[29][i]->SetPosition({1375.0f, -138.0f});

        m_Brick_break[30][i]->SetPosition({1407.0f, -74.0f});
        m_Brick_break[31][i]->SetPosition({1407.0f, -106.0f});
        m_Brick_break[32][i]->SetPosition({1407.0f, -138.0f});

        m_Brick_break[33][i]->SetPosition({1535.0f, -74.0f});
        m_Brick_break[34][i]->SetPosition({1567.0f, -74.0f});
        m_Brick_break[35][i]->SetPosition({1599.0f, -74.0f});
        m_Brick_break[36][i]->SetPosition({1631.0f, -74.0f});

        m_Brick_break[37][i]->SetPosition({1663.0f, -74.0f});
        m_Brick_break[38][i]->SetPosition({1663.0f, -42.0f});
        m_Brick_break[39][i]->SetPosition({1663.0f, -10.0f});
        m_Brick_break[40][i]->SetPosition({1663.0f, 22.0f});
        m_Brick_break[41][i]->SetPosition({1663.0f, 54.0f});

        m_Brick_break[42][i]->SetPosition({1695.0f, -74.0f});
        m_Brick_break[43][i]->SetPosition({1695.0f, -42.0f});
        m_Brick_break[44][i]->SetPosition({1695.0f, -10.0f});
        m_Brick_break[45][i]->SetPosition({1695.0f, 22.0f});
        m_Brick_break[46][i]->SetPosition({1695.0f, 54.0f});

        m_Brick_break[47][i]->SetPosition({1823.0f, -74.0f});
        m_Brick_break[48][i]->SetPosition({1823.0f, -42.0f});
        m_Brick_break[49][i]->SetPosition({1823.0f, -10.0f});
        m_Brick_break[50][i]->SetPosition({1823.0f, 22.0f});
        m_Brick_break[51][i]->SetPosition({1823.0f, 54.0f});

        m_Brick_break[52][i]->SetPosition({1855.0f, -74.0f});
        m_Brick_break[53][i]->SetPosition({1887.0f, -74.0f});
        m_Brick_break[54][i]->SetPosition({1887.0f, -42.0f});

        m_Brick_break[55][i]->SetPosition({1983.0f, -74.0f});
        m_Brick_break[56][i]->SetPosition({1983.0f, -42.0f});
        m_Brick_break[57][i]->SetPosition({1983.0f, -10.0f});
        m_Brick_break[58][i]->SetPosition({1983.0f, 22.0f});
        m_Brick_break[59][i]->SetPosition({1983.0f, 54.0f});

        m_Brick_break[60][i]->SetPosition({2015.0f, -74.0f});
        m_Brick_break[61][i]->SetPosition({2015.0f, -42.0f});
        m_Brick_break[62][i]->SetPosition({2015.0f, -10.0f});
        m_Brick_break[63][i]->SetPosition({2015.0f, 22.0f});
        m_Brick_break[64][i]->SetPosition({2015.0f, 54.0f});

        m_Brick_break[65][i]->SetPosition({2111.0f, -74.0f});
        m_Brick_break[66][i]->SetPosition({2143.0f, -74.0f});
        m_Brick_break[67][i]->SetPosition({2175.0f, -74.0f});

        m_Brick_break[68][i]->SetPosition({2355.0f, -74.0f});
        m_Brick_break[69][i]->SetPosition({2355.0f, -42.0f});

        m_Brick_break[70][i]->SetPosition({2387.0f, -74.0f});
        m_Brick_break[71][i]->SetPosition({2387.0f, -42.0f});

        m_Brick_break[72][i]->SetPosition({2419.0f, -74.0f});
        m_Brick_break[73][i]->SetPosition({2419.0f, -42.0f});

        m_Brick_break[74][i]->SetPosition({2451.0f, -74.0f});
        m_Brick_break[75][i]->SetPosition({2451.0f, -42.0f});

        m_Brick_break[76][i]->SetPosition({2483.0f, -74.0f});
        m_Brick_break[77][i]->SetPosition({2483.0f, -42.0f});

        m_Brick_break[78][i]->SetPosition({2515.0f, -74.0f});
        m_Brick_break[79][i]->SetPosition({2515.0f, -42.0f});

        m_Brick_break[80][i]->SetPosition({4356.0f, -106.0f});
        m_Brick_break[81][i]->SetPosition({4388.0f, -106.0f});
        m_Brick_break[82][i]->SetPosition({4420.0f, -106.0f});
        m_Brick_break[83][i]->SetPosition({4452.0f, -106.0f});
        m_Brick_break[84][i]->SetPosition({4484.0f, -106.0f});
        m_Brick_break[85][i]->SetPosition({4516.0f, -106.0f});

        for(int j=0;j<5;j++){
            m_Brick_break[86+j][i]->SetPosition({1375.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[91+j][i]->SetPosition({1407.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[96+j][i]->SetPosition({1535.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[101+j][i]->SetPosition({1567.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[106+j][i]->SetPosition({1599.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[111+j][i]->SetPosition({1631.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[116+j][i]->SetPosition({1663.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[121+j][i]->SetPosition({1695.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[126+j][i]->SetPosition({1791.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[131+j][i]->SetPosition({1823.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[136+j][i]->SetPosition({1855.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[141+j][i]->SetPosition({1887.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[146+j][i]->SetPosition({2111.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[151+j][i]->SetPosition({2143.0f, 86.0f+(32.0f*j)});
        }
        for(int j=0;j<5;j++){
            m_Brick_break[156+j][i]->SetPosition({2175.0f, 86.0f+(32.0f*j)});
        }

        for(int j=0;j<100;j++){
            m_Brick_break[161+j][i]->SetPosition({-160.0f+(32.0f*j),246.0f});
        }
    }


    //brick move
    m_BrickMove = std::make_shared<Character>(GA_RESOURCE_DIR"/images/tilesWorld2_1.png");
    m_BrickMove->SetZIndex(5);
    m_BrickMove->SetPosition({-1000.0f,-1000.0f});
    m_BrickMove->SetVisible(false);
    app->m_Root.AddChild(m_BrickMove);

    //Tube
    for(int i=0;i<3;i++){
        m_Tube.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/tube.png"));
        m_Tube[i]->SetZIndex(4);
        m_Tube[i]->SetVisible(false);

    }
    m_Tube[0]->SetPosition({2979.0f,-350.0f});
    m_Tube[1]->SetPosition({3171.0f,-310.0f});
    m_Tube[2]->SetPosition({3363.0f,-380.0f});


    for(int i=0;i<3;i++){
        app->m_Root.AddChild(m_Tube[i]);
    }

    //wood
    for(int i=0;i<13;i++){
        m_Wood.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/woodBlue.png"));
        m_Wood[i]->SetZIndex(4);
        m_Wood[i]->SetVisible(true);
    }

    m_Wood[0]->SetPosition({163.0f,-172.0f});

    m_Wood[1]->SetPosition({227.0f,-156.0f});
    m_Wood[1]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong.png");

    m_Wood[2]->SetPosition({291.0f,-140.0f});
    m_Wood[2]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong2.png");

    m_Wood[3]->SetPosition({355.0f,-124.0f});
    m_Wood[3]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong3.png");

    m_Wood[4]->SetPosition({419.0f,-124.0f});
    m_Wood[4]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong3.png");

    m_Wood[5]->SetPosition({483.0f,-140.0f});
    m_Wood[5]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong2.png");

    m_Wood[6]->SetPosition({611.0f,-140.0f});
    m_Wood[6]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong2.png");

    m_Wood[7]->SetPosition({675.0f,-156.0f});
    m_Wood[7]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong.png");


    m_Wood[8]->SetPosition({3933.0f,-172.0f});
    m_Wood[9]->SetPosition({3965.0f,-156.0f});
    m_Wood[9]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong.png");
    m_Wood[10]->SetPosition({3997.0f,-140.0f});
    m_Wood[10]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong2.png");
    m_Wood[11]->SetPosition({4029.0f,-124.0f});
    m_Wood[11]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong3.png");
    m_Wood[12]->SetPosition({4061.0f,-124.0f});
    m_Wood[12]->SetImage(GA_RESOURCE_DIR"/images/woodBlueLong3.png");


    for(int i=0;i<13;i++){
        app->m_Root.AddChild(m_Wood[i]);
    }

    //pillar and flag
    m_Pillar = std::make_shared<Character>(GA_RESOURCE_DIR"/images/flag_pillar.png");
    m_Pillar->SetZIndex(4);
    m_Pillar->SetVisible(false);
    m_Pillar->SetPosition({6035.0f,-6.0f});
    app->m_Root.AddChild(m_Pillar);

    m_Flag = std::make_shared<Character>(GA_RESOURCE_DIR"/images/flag.png");
    m_Flag->SetZIndex(4);
    m_Flag->SetVisible(false);
    m_Flag->SetPosition({6019.0f,110.0f});
    app->m_Root.AddChild(m_Flag);

    //castle
    for(int i = 0; i < 2; i++){
        m_Castle.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/blackCastle.png"));
        m_Castle[i]->SetZIndex(100);
        m_Castle[i]->SetVisible(false);
        m_Castle[i]->SetPosition({6547.0f,-172.0f + (i*32.0f)});
        app->m_Root.AddChild(m_Castle[i]);
    }

    //moving Platform
    for(int i=0;i<4;i++){
        m_MovingPlatform.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/movingPlatform.png"));
        m_MovingPlatform[i]->SetZIndex(100);
        m_MovingPlatform[i]->SetVisible(false);
        app->m_Root.AddChild(m_MovingPlatform[i]);
    }
    m_MovingPlatform[0]->SetPosition({4205.0f,-300.0f});
    m_MovingPlatform[1]->SetPosition({4205.0f,0.0f});
    m_MovingPlatform[2]->SetPosition({4205.0f,300.0f});
    m_MovingPlatform[3]->SetPosition({4205.0f,600.0f});

    for(int i=0;i<4;i++){
        m_MovingPlatform2.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/images/movingPlatform.png"));
        m_MovingPlatform2[i]->SetZIndex(100);
        m_MovingPlatform2[i]->SetVisible(false);
        app->m_Root.AddChild(m_MovingPlatform2[i]);
    }
    m_MovingPlatform2[0]->SetPosition({4660.0f,-300.0f});
    m_MovingPlatform2[1]->SetPosition({4660.0f,0.0f});
    m_MovingPlatform2[2]->SetPosition({4660.0f,-900.0f});
    m_MovingPlatform2[3]->SetPosition({4660.0f,-600.0f});

    /*
    m_PRM = std::make_shared<PhaseResourcesManager>();
    app->m_Root.AddChildren(m_PRM->GetChildren());
     */

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
    app->m_Root.AddChild(m_Coins);


    //coins2
    CoinsLvl2.reserve(5);
    for(int i = 1;i<6;i++){
        LOG_DEBUG("coinslvl2");
        CoinsLvl2.emplace_back(GA_RESOURCE_DIR"/images/Coins2_1/"+std::to_string(i)+".png");
    }
    for(int i=0;i<17;i++){
        LOG_DEBUG("coins2");
        m_Coins2 = std::make_shared<AnimatedCharacter>(CoinsLvl2);
        m_Coins2->SetLooping(true);
        m_Coins2->SetPlaying();
        m_Coins2->SetZIndex(5);
        m_Coins2->SetVisible(true);
        m_Coins2Vec.push_back(m_Coins2);
        app->m_Root.AddChild(m_Coins2Vec[i]);

    }
    m_Coins2Vec[0]->SetPosition({959.0f,50.0f});
    m_Coins2Vec[1]->SetPosition({991.0f,50.0f});
    m_Coins2Vec[2]->SetPosition({1023.0f,50.0f});
    m_Coins2Vec[3]->SetPosition({1055.0f,50.0f});
    m_Coins2Vec[4]->SetPosition({927.0f,-42.0f});
    m_Coins2Vec[5]->SetPosition({1087.0f,-42.0f});

    m_Coins2Vec[6]->SetPosition({1535.0f,-42.0f});
    m_Coins2Vec[7]->SetPosition({1567.0f,-42.0f});
    m_Coins2Vec[8]->SetPosition({1599.0f,-42.0f});
    m_Coins2Vec[9]->SetPosition({1631.0f,-42.0f});

    m_Coins2Vec[10]->SetPosition({1855.0f,-42.0f});

    m_Coins2Vec[11]->SetPosition({2355.0f,-10.0f});
    m_Coins2Vec[12]->SetPosition({2387.0f,-10.0f});
    m_Coins2Vec[13]->SetPosition({2419.0f,-10.0f});
    m_Coins2Vec[14]->SetPosition({2451.0f,-10.0f});
    m_Coins2Vec[15]->SetPosition({2483.0f,-10.0f});
    m_Coins2Vec[16]->SetPosition({2515.0f,-10.0f});



    //level up mush
    YellowMushroom.reserve(2);
    for(int i=0;i<2;i++){
        YellowMushroom.emplace_back(GA_RESOURCE_DIR"/images/mushroom.png");
    }

    for(int i=0;i<4;i++){
        m_YellowMush = std::make_shared<YellowMush>(YellowMushroom);
        m_YellowMush->SetLooping(true);
        m_YellowMush->SetPlaying();
        m_YellowMush->SetZIndex(3);
        m_YellowMush->SetVisible(false);
        m_YellowMush->SetPosition({-1000.0f,-1000.0f});
        m_YellowMushVec.push_back(m_YellowMush);



    }

    for(int i=0;i<4;i++){
        app->m_Root.AddChild(m_YellowMushVec[i]);
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

    SetState(State::UPDATE);

}