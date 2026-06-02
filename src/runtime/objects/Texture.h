#pragma once

#include <memory>
#include <string>

#include "../RuntimeTypes.h"

namespace Anjean::Runtime
{
    class Texture
    {
      public:
        std::string filename;       
        int width;
        int height;
        int channels;

    };
}