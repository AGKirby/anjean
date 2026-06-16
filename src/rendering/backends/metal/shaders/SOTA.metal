#include <metal_stdlib>
using namespace metal;

// ------------------------------------------------------------
// Function constants
// ------------------------------------------------------------

constant bool kHasBaseColorTexture [[function_constant(0)]];


// ------------------------------------------------------------
// Vertex input
// ------------------------------------------------------------

struct MeshVertex
{
    packed_float3 position;
    packed_float2 uv;
};


// ------------------------------------------------------------
// Frame data
// Updated once per camera / pass.
// ------------------------------------------------------------

struct FrameUniforms
{
    float4x4 viewProjection;
};


// ------------------------------------------------------------
// Object data
// Updated per object / draw / instance.
// Keeps full 3D support.
// ------------------------------------------------------------

struct ObjectUniforms
{
    float4x4 model;
};


// ------------------------------------------------------------
// Material data
// Updated per material.
// ------------------------------------------------------------

struct MaterialUniforms
{
    half4 baseColorFactor;
};


// ------------------------------------------------------------
// Vertex output
// ------------------------------------------------------------

struct VertexOut
{
    float4 position [[position]];
    float2 uv;
};


// ------------------------------------------------------------
// Vertex shader
// ------------------------------------------------------------

vertex VertexOut mesh_vertex_shader(
    uint vertexId [[vertex_id]],
    const device MeshVertex* vertices [[buffer(0)]],
    constant ObjectUniforms& object [[buffer(1)]],
    constant FrameUniforms& frame [[buffer(2)]]
) {
    const MeshVertex v = vertices[vertexId];

    VertexOut out;

    const float4 worldPosition =
        object.model * float4(float3(v.position), 1.0);

    out.position =
        frame.viewProjection * worldPosition;

    out.uv = float2(v.uv);

    return out;
}


// ------------------------------------------------------------
// Fragment shader
// ------------------------------------------------------------

fragment half4 mesh_fragment_shader(
    VertexOut in [[stage_in]],
    constant MaterialUniforms& material [[buffer(0)]],
    texture2d<half, access::sample> baseColorTexture [[texture(0)]],
    sampler baseColorSampler [[sampler(0)]]
) {
    half4 baseColor = material.baseColorFactor;

    if (kHasBaseColorTexture) {
        const half4 texel =
            baseColorTexture.sample(baseColorSampler, in.uv);

        baseColor *= texel;
    }

    return baseColor;
}