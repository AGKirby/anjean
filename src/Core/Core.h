#pragma once
#include <iostream>
#include <cstdint>

namespace Anjean::Core
{
    struct Position3D
    {
        float x;
        float y;
        float z;
    };

    struct Position2D
    {
        float x;
        float y;
    };

    struct MeshVertex
    {
        Position3D position;
        Position2D uv;
    };

    struct MeshData
    {
        std::uint32_t id = 0;
        std::vector<MeshVertex> vertices;
    };
}