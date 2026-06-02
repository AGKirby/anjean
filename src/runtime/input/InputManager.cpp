#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "InputManager.h"

namespace Anjean::Runtime {
  void InputManager::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_MOUSE_MOTION: {
          AnjeanInputEvent inputEvent;
          inputEvent.type = AnjeanInputEventType::MouseMotion;
          inputEvent.mouseMotion.windowXPosition = event.motion.x;
          inputEvent.mouseMotion.windowYPosition = event.motion.y;
          inputEvent.mouseMotion.xMotion = event.motion.xrel;
          inputEvent.mouseMotion.yMotion = event.motion.yrel;
          frameEvents.push_back(inputEvent);
          break;
        }
        default: {
          break;
        }
      }
    }
  };
  
  void InputManager::updateInputState() {
    for (AnjeanInputEvent event : frameEvents) {
      switch (event.type) {
        case AnjeanInputEventType::MouseMotion : {
          MouseState previousMouseState = inputState.mouseState;
          float newWindowXPosition = event.mouseMotion.windowXPosition;
          float newWindowYPosition = event.mouseMotion.windowYPosition;
          float newYMotion = event.mouseMotion.yMotion;
          float newXMotion = event.mouseMotion.xMotion;
          
          inputState.mouseState.deltaX = newWindowXPosition - inputState.mouseState.x;
          inputState.mouseState.deltaY = newWindowYPosition - inputState.mouseState.y;
          inputState.mouseState.x = newWindowXPosition;
          inputState.mouseState.y = newWindowYPosition;
          inputState.mouseState.movedThisFrame = true;
          break;
        }
      }
    }
  }
}