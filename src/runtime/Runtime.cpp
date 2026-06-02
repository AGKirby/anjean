#include "Runtime.h"
#include "objects/GameObject.h"
#include "objects/Camera.h"

namespace Anjean::Runtime
{

    Runtime::Runtime()
    {
        inputManager = InputManager();
        currentCamera = Camera();
        currentCamera.transform.position = {0,0,0};
        currentCamera.transform.rotation = {0,0,0};
        currentCamera.transform.scale = {1,1,1};
        sceneObjects = std::vector<GameObject>{};
    }

    void Runtime::beginTick()
    {
        inputManager.pollEvents();
    }

    void Runtime::executeTick()
    {
        // update systems/game objects
    }

    void Runtime::endTick()
    {
        inputManager.frameEvents.clear();
    }

    std::vector<GameObject> Runtime::getRenderableSceneObjects() {
      return sceneObjects;
    }
    
    Camera Runtime::getCurrentCamera() {
      return currentCamera;
    }

    std::vector<Mesh> Runtime::getAllMeshes() {
      float hw = 1.0f / 2.0f;
      float hh = 1.0f / 2.0f;
      float hd = 1.0f / 2.0f;
      decltype(Mesh::vertices) cubeVertices;
      
      float u0 = 0.0f;
      float u1 = 1.0f;
      float v0 = 0.0f;
      float v1 = 1.0f;

      cubeVertices = {
          // Front, +Z
          { { -hw, -hh,  hd }, { u0, v1 } },
          { {  hw, -hh,  hd }, { u1, v1 } },
          { { -hw,  hh,  hd }, { u0, v0 } },

          { {  hw, -hh,  hd }, { u1, v1 } },
          { {  hw,  hh,  hd }, { u1, v0 } },
          { { -hw,  hh,  hd }, { u0, v0 } },

          // Back, -Z
          { {  hw, -hh, -hd }, { u0, v1 } },
          { { -hw, -hh, -hd }, { u1, v1 } },
          { {  hw,  hh, -hd }, { u0, v0 } },

          { { -hw, -hh, -hd }, { u1, v1 } },
          { { -hw,  hh, -hd }, { u1, v0 } },
          { {  hw,  hh, -hd }, { u0, v0 } },

          // Top, +Y
          { { -hw,  hh,  hd }, { u0, v1 } },
          { {  hw,  hh,  hd }, { u1, v1 } },
          { { -hw,  hh, -hd }, { u0, v0 } },

          { {  hw,  hh,  hd }, { u1, v1 } },
          { {  hw,  hh, -hd }, { u1, v0 } },
          { { -hw,  hh, -hd }, { u0, v0 } },

          // Bottom, -Y
          { { -hw, -hh, -hd }, { u0, v1 } },
          { {  hw, -hh, -hd }, { u1, v1 } },
          { { -hw, -hh,  hd }, { u0, v0 } },

          { {  hw, -hh, -hd }, { u1, v1 } },
          { {  hw, -hh,  hd }, { u1, v0 } },
          { { -hw, -hh,  hd }, { u0, v0 } },

          // Left, -X
          { { -hw, -hh,  hd }, { u0, v1 } },
          { { -hw,  hh,  hd }, { u0, v0 } },
          { { -hw, -hh, -hd }, { u1, v1 } },

          { { -hw,  hh,  hd }, { u0, v0 } },
          { { -hw,  hh, -hd }, { u1, v0 } },
          { { -hw, -hh, -hd }, { u1, v1 } },

          // Right, +X
          { {  hw, -hh, -hd }, { u0, v1 } },
          { {  hw,  hh, -hd }, { u0, v0 } },
          { {  hw, -hh,  hd }, { u1, v1 } },

          { {  hw,  hh, -hd }, { u0, v0 } },
          { {  hw,  hh,  hd }, { u1, v0 } },
          { {  hw, -hh,  hd }, { u1, v1 } },
      };
      std::vector<Mesh> meshes;
      Mesh cube;
      cube.id = 1;
      cube.vertexCount = 36;
      cube.vertices = cubeVertices;

      meshes.push_back(cube);

      return meshes;
    }
    
    std::vector<Texture> Runtime::getAllTextures() {
      std::vector<Texture> textures;
      
      Texture tempTexture{};
      tempTexture.filename="text.png";
      tempTexture.width=36;
      tempTexture.height=36;
      tempTexture.channels=0;
      
      textures.push_back(tempTexture);

      return textures;
    }
}