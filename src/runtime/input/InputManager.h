#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <queue> 

namespace Anjean::Runtime {
  struct MouseState
  {
    float x = 0.0f;
    float y = 0.0f;

    float deltaX = 0.0f;
    float deltaY = 0.0f;

    float velocityX = 0.0f;
    float velocityY = 0.0f;

    bool leftDown = false;
    bool rightDown = false;
    bool middleDown = false;

    bool movedThisFrame = false;
  };

  struct InputState {
    MouseState mouseState;
  };
  
  struct AnjeanInputEventMouseEvent {
    // TODO: Implement our own event emitters
    /**
     * SDL Mouse Motion Event give us this:
     *  float x;            < X coordinate, relative to window 
     *  float y;            < Y coordinate, relative to window 
     *  float xrel;         < The relative motion in the X direction 
     *  float yrel;         < The relative motion in the Y direction 
     */

     float windowXPosition;
     float windowYPosition;
     float xMotion;
     float yMotion;
  };

  enum class AnjeanInputEventType
  {
      MouseMotion,
      MouseButton,
      Keyboard
  };

  struct AnjeanInputEvent{
    AnjeanInputEventType type;
    AnjeanInputEventMouseEvent mouseMotion;
    uint8_t padding[128];
  };

  class InputManager {
    public:
      std::vector<AnjeanInputEvent> frameEvents;
      InputState inputState;
      void pollEvents();
      void updateInputState();
  };
}