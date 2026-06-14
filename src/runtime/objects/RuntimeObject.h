#pragma once

#include <cstdint>

namespace Anjean::Runtime {
  class Runtime;

  class RuntimeObject {
  public:
    explicit RuntimeObject(Runtime& runtime) : runtime_(&runtime) {}

    virtual ~RuntimeObject() = default;

    Runtime& runtime() {
      return *runtime_;
    }

    const Runtime& runtime() const {
      return *runtime_;
    }

    std::uint32_t runtimeObjectId = 0;

  private:
    Runtime* runtime_;
  };
} // namespace Anjean::Runtime