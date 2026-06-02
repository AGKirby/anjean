#include "Renderer.h"
#include "IRenderBackend.h"
#include "RendererBackendFactory.h"

namespace Anjean::Rendering
{
    Renderer::Renderer(Anjean::Window& window, const RendererConfig& config)
        : m_backend(CreateRendererBackend(window, config))
    {
    }

    Renderer::~Renderer() = default;

    void Renderer::beginFrame(const Color& clearColor)
    {
        m_backend->beginFrame(clearColor);
    }

    void Renderer::endFrame()
    {
        m_backend->endFrame();
    }
    
    BufferHandle Renderer::createBuffer(const BufferDesc& desc)
    {
        return m_backend->createBuffer(desc);
    }
    
    TextureHandle Renderer::createTexture(TextureDesc& desc)
    {
        return m_backend->createTexture(desc);
    }

    PipelineHandle Renderer::createPipeline(const PipelineDesc& desc)
    {
        return m_backend->createPipeline(desc);
    }
    
    PipelineHandle Renderer::createSpritePipeline()
    {
        PipelineDesc pipelineDesc;
        pipelineDesc.vertexFunction = "sprite_vertex_shader";
        pipelineDesc.fragmentFunction = "sprite_fragment_shader";
        
        return createPipeline(pipelineDesc);
    }

    void Renderer::draw(const DrawCommand& command)
    {
        m_backend->draw(command);
    }
    
    void Renderer::drawSprite(const PipelineHandle& pPipeline, const Core::MeshData& pMesh, const std::optional<TextureHandle>& pTexture, const ObjectUniformHandle& pObjectUniform)
    {
        m_backend->drawSprite(pPipeline, pMesh, pTexture, pObjectUniform);
    }
    
    std::pair<decltype(BufferHandle::id), std::optional<decltype(TextureHandle::id)>> Renderer::loadMeshToGPU(Mesh pMesh)
    {
        return m_backend->loadMeshToGPU(pMesh);
    }
}