#pragma once

#include "GameObject.h"

namespace Anjean::Runtime
{
    class Camera : public GameObject
    {
      public:
        float fieldOfView = 60.0f;
        float nearClippingPlane = 0.1f;
        float farClippingPlane = 1000.0f;
        float aspectRatio = 16.0f / 9.0f;
        float aperture = 0.0f;
        float focalLength = 50.0f;

        GameObjectType getGameObjectType() const override
        {
            return ANJEAN_GAMEOBJECT_CAMERA;
        }
    };
}