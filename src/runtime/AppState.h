#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "../rendering/RenderTypes.h"
#include "../rendering/Renderer.h"
#include "../runtime/objects/GameObject.h"
#include "Runtime.h"

namespace Anjean {
  class Window;
}

namespace Anjean::Runtime
{
    struct AppState
    {
        Uint64 last_step = 0;

        std::unique_ptr<Anjean::Window> window;
        std::unique_ptr<Anjean::Rendering::Renderer> renderer;
        std::unique_ptr<Runtime> manager;

        Rendering::PipelineHandle basicColorPipeline;
        Rendering::TextureHandle demoTexture;
        Rendering::Mesh demoMesh;
        Rendering::Mesh demoMesh2;
        float rotationSpeed;
        simd_float3 cameraPos;
        simd_float4x4 cameraMatrix;
        simd_float4x4 projectionMatrix;
        std::unique_ptr<GameObject> camera;
        std::unique_ptr<GameObject> cube1;
        std::unique_ptr<GameObject> cube2;
        std::vector<GameObject*> gameObjectsToRender;
    };
}