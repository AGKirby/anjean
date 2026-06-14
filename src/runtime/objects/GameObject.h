#pragma once

#include <cstdint>
#include <optional>

#include "../Runtime.h"
#include "./NativeMeshes/Mesh.h"
#include "Collider.h"
#include "Texture.h"

namespace Anjean::Runtime {
  class GameObject {
  public:
    virtual ~GameObject() = default;

    std::uint32_t id = 0;

    Transform transform;

    std::optional<Mesh*> mesh = std::nullopt;
    std::optional<Texture> texture = std::nullopt;
    std::optional<std::uint32_t> physicsBodyId;
    std::optional<Collider> collider = std::nullopt;

    virtual GameObjectType getGameObjectType() const {
      return ANJEAN_GAMEOBJECT;
    }
  };
} // namespace Anjean::Runtime