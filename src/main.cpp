#include "App.h"
#include "MenuPhase.h"
#include "Core/Context.hpp"
#include <iostream>

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    App app(App::Phases::MENU);

    if(context){
        while (!context->GetExit()) {

            if(app.m_CurrentPhase->GetCurrentState() ==  Phase::State::EXIT){
                context->SetExit(true);
                break;
            }
            if(app.m_CurrentPhase->GetCurrentState() ==  Phase::State::START){
                std::cout<<"masuk start";
            }

            app.Update();
            context->Update();
        }


    }


    return 0;
}
