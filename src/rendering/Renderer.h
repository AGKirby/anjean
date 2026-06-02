#pragma once

#include <memory>

#include "RenderTypes.h"
#include "../runtime/RuntimeTypes.h"
#include "../window/Window.h"

namespace Anjean::Rendering
{
    class IRenderBackend;

    class Renderer
    {
    public:
        explicit Renderer(Anjean::Window& window, const RendererConfig& config = {});
        ~Renderer();

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;

        Renderer(Renderer&&) noexcept = default;
        Renderer& operator=(Renderer&&) noexcept = default;

        void beginFrame(const Color& clearColor);
        TextureHandle createTexture(TextureDesc& desc);
        BufferHandle createBuffer(const BufferDesc& desc);
        PipelineHandle createPipeline(const PipelineDesc& desc);
        PipelineHandle createSpritePipeline();
        std::pair<decltype(BufferHandle::id), std::optional<decltype(TextureHandle::id)>> loadMeshToGPU(Mesh pMesh);
        void draw(const DrawCommand& command);
        void drawSprite(const PipelineHandle& pPipeline, const Core::MeshData& pMesh, const std::optional<TextureHandle>& pTexture, const ObjectUniformHandle& pObjectUniform);
        void endFrame();

    private:
        std::unique_ptr<IRenderBackend> m_backend;
    };
}