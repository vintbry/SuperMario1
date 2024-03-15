//
// Created by Felicia Rulita on 2024/3/12.
//

#include "App.h"

#include "Character.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Update(){
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        glm::vec2 position = m_Mario->GetPosition();
        m_Mario->SetPosition({position.x+3.0f,position.y});
    }
    else if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        glm::vec2 position = m_Mario->GetPosition();

    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}