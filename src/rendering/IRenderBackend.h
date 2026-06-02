#pragma once

#include "RenderTypes.h"

namespace Anjean::Rendering
{
    class IRenderBackend
    {
    public:
        virtual ~IRenderBackend() = default;

        virtual void beginFrame(const Color& clearColor) = 0;

        virtual BufferHandle createBuffer(const BufferDesc& desc) = 0;
        virtual TextureHandle createTexture(TextureDesc& desc) = 0;
        virtual PipelineHandle createPipeline(const PipelineDesc& desc) = 0;
        virtual void draw(const DrawCommand& command) = 0;
        virtual void drawSprite(const PipelineHandle& pPipeline, const Core::MeshData& pMesh, const std::optional<TextureHandle>& pTexture, const ObjectUniformHandle& pObjectUniform) = 0;
        virtual std::pair<decltype(BufferHandle::id), std::optional<decltype(TextureHandle::id)>> loadMeshToGPU(Mesh pMesh) = 0;

        virtual void endFrame() = 0;
    };
}