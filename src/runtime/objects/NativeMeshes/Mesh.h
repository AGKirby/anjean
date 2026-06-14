#pragma once

#include <memory>
#include <string>

#include "../../RuntimeTypes.h"
#include "../RuntimeObject.h"
#include <cstdint>
#include <optional>
#include <vector>

namespace Anjean::Runtime {
  class Mesh : public RuntimeObject {
  public:
    Mesh(Anjean::Runtime::Runtime& runtime,
         std::optional<Anjean::Core::MeshDescriptor> meshDescriptor = std::nullopt);
    std::uint32_t id = 0;
    std::uint32_t vertexCount = 0;
    std::vector<Anjean::Core::MeshVertex> vertices{};

  private:
  };
} // namespace Anjean::Runtime