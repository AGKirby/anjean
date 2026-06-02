#pragma once

#include <memory>

#include "RenderTypes.h"
#include "../window/Window.h"

namespace Anjean::Rendering
{
    class IRenderBackend;

    std::unique_ptr<IRenderBackend> CreateRendererBackend(
        Anjean::Window& window,
        const RendererConfig& config
    );
}