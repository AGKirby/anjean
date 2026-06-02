#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#include "Orchestrator/Orchestrator.hpp"

using namespace Anjean;

#define STEP_RATE_IN_MILLISECONDS 16

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    // orchestrator = Orchestrator::Orchestrator();
    if (!SDL_SetAppMetadata("Anjean Editor", "1.0", "com.Anjean.Editor"))
    {
        return SDL_APP_FAILURE;
    }

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (argc > 1)
    {
        std::cout << "Command: " << argv[1] << std::endl;
    }

    // int screenWidth = std::stoi(argv[2]);
    // int screenHeight = std::stoi(argv[3]);
    // float textWidth = std::stof(argv[4]);
    // float textHeight = std::stof(argv[5]);
    // const char* filename = argv[6];

    auto* orchestrator = new Orchestrator::Orchestrator();
    *appstate = orchestrator;
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    auto* orchestrator = static_cast<Orchestrator::Orchestrator*>(appstate);

    if (orchestrator)
    {
        orchestrator->Tick();
    }
    
    const Uint64 now = SDL_GetTicks();
    
    // while ((now - as->last_step) >= STEP_RATE_IN_MILLISECONDS)
    // {
    //     as->last_step += STEP_RATE_IN_MILLISECONDS;
    //     rotationY += as->rotationSpeed;
    //     const bool* state = SDL_GetKeyboardState(NULL);
    //     if (state[SDL_SCANCODE_W]) {
    //         // Space bar is currently held down
    //         as->cameraPos[2] -= .005;
    //     }
    //     if (state[SDL_SCANCODE_A]) {
    //         // Space bar is currently held down
    //         as->cameraPos[0] -= .005;
    //     }
    //     if (state[SDL_SCANCODE_S]) {
    //         // Space bar is currently held down
    //         as->cameraPos[2] += .005;
    //     }
    //     if (state[SDL_SCANCODE_D]) {
    //         // Space bar is currently held down
    //         as->cameraPos[0] += .005;
    //     }        
    // }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    // (void)appstate;

    switch (event->type)
    {
        case SDL_EVENT_MOUSE_MOTION:
            break;
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;

        default:
            std::cout << event->type;
            break;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    (void)result;

    SDL_Quit();
}