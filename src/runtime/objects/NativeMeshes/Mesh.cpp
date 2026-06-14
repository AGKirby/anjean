#include "Mesh.h"

namespace Anjean::Runtime {
  Mesh::Mesh(Runtime& runtime, std::optional<Anjean::Core::MeshDescriptor> meshDescriptor)
      : RuntimeObject(runtime) {
    if (meshDescriptor.has_value()) {
      id = meshDescriptor.value().id ? meshDescriptor.value().id : 0;
      vertexCount = meshDescriptor.value().vertexCount
                        ? static_cast<std::uint32_t>(meshDescriptor.value().vertices.size())
                        : 0;
      vertices = meshDescriptor.value().vertices;
    }
  };

} // namespace Anjean::Runtime