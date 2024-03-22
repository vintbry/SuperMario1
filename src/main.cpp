#include "App.h"
#include "Core/Context.hpp"
#include "Map.h"

int main(int, char**) {
    Core::Context context1;

    unsigned int newWidth = 256;
    unsigned int newHeight = 240;

    context1.SetWindowWidth(newWidth);
    context1.SetWindowHeight(newHeight);

    auto context = context1.GetInstance();
    //auto context = Core::Context::GetInstance();
    //Map map;
    //map.RenderMap();
    App app;

    if(context){
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
