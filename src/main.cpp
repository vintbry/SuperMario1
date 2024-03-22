#include "App.h"
#include "Core/Context.hpp"
#include "Map.h"

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    Map map;
    map.RenderMap();
    App app;

    if(context){
        /*
        unsigned int newWidth = 256;
        unsigned int newHeight = 240;

        context->SetWindowWidth(newWidth);
        context->SetWindowHeight(newHeight);
        */

        while (!context->GetExit()) {
            switch (app.GetCurrentState()) {
                case App::State::START:
                    app.Start();
                    break;

                case App::State::UPDATE:
                    app.Update();
                    break;

                case App::State::END:
                    app.End();
                    context->SetExit(true);
                    break;
            }
            context->Update();
        }


    }


    return 0;
}
