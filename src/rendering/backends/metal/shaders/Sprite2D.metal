#include <metal_stdlib>
using namespace metal;

struct SpriteVertex
{
    packed_float3 position;
    float u;
    float v;
};

struct VertexOut
{
    float4 position [[position]];
    float2 textureCoordinate;
};

struct ObjectUniforms
{
    float4x4 model;
    float4x4 modelTranslation;
    float4x4 modelScale;
    float4x4 modelRot;
    float4x4 viewProjection;
};

vertex VertexOut sprite_vertex_shader(
    uint vertexId [[vertex_id]],
    const device SpriteVertex* vertices [[buffer(0)]],
    constant ObjectUniforms& uniforms [[buffer(1)]]
)
{
    SpriteVertex v = vertices[vertexId];

    VertexOut out;

    float3 pos = float3(v.position);
    
    float2 uv = float2(v.u, v.v);

    out.position = uniforms.viewProjection * uniforms.model * float4(pos, 1.0);
    out.textureCoordinate = uv;

    return out; 
}

fragment float4 sprite_fragment_shader(
    VertexOut in [[stage_in]],
    texture2d<float, access::sample> baseColor [[texture(0)]],
    constant float &elapsedTime [[buffer(0)]]
) {
    float2 uv = in.textureCoordinate;
    constexpr sampler s(mag_filter::nearest, min_filter::nearest);
    return baseColor.sample(s, uv);
}