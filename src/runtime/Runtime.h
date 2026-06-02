#pragma once
#include "input/InputManager.h"
#include "RuntimeTypes.h"
#include "objects/Camera.h"
#include "objects/Texture.h"
#include "../Core/Core.h"

namespace Anjean::Runtime
{
    class Runtime
    {
      public:
          Runtime();
          InputManager inputManager;
          std::vector<GameObject> sceneObjects;
          Camera currentCamera;
          void beginTick();
          void executeTick();
          void endTick();
          std::vector<GameObject> getRenderableSceneObjects();
          Camera getCurrentCamera();
          std::vector<Mesh> getAllMeshes();
          std::vector<Texture> getAllTextures();
          
    };
}