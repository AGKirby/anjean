#pragma once

#include <cstdint>
#include "../RuntimeTypes.h"


namespace Anjean::Runtime
{
    class Runtime;

    void BindNativeRuntime(Runtime* runtime);
}

extern "C"
{
    struct AnjeanVec3
    {
        float x;
        float y;
        float z;
    };

        int Anjean_Runtime_CreateGameObject(
        std::uint32_t* outGameObjectId
    );

    int Anjean_Runtime_CreateCamera(
        std::uint32_t* outCameraId
    );

    int Anjean_Runtime_SetCurrentCamera(
        std::uint32_t cameraId
    );
    
    int Anjean_Runtime_GetCurrentCamera(std::uint32_t* outCameraId);
    
    int Anjean_GameObject_GetPosition(
        std::uint32_t gameObjectId,
        AnjeanVec3* outPosition
    );

    int Anjean_GameObject_SetPosition(
        std::uint32_t gameObjectId,
        AnjeanVec3 position
    );

    int Anjean_GameObject_SetTexture(
      std::uint32_t gameObjectId,
      const char* filename,
      std::uint32_t width,
      std::uint32_t height,
      std::uint32_t channels
    );
    
    int Anjean_GameObject_SetMesh(
      std::uint32_t gameObjectId,
      std::uint32_t meshId
    );

    int Anjean_Camera_SetFieldOfView(
        std::uint32_t cameraId,
        float fieldOfView
    );

    int Anjean_Camera_SetNearClippingPlane(
        std::uint32_t cameraId,
        float nearClippingPlane
    );

    int Anjean_Camera_SetFarClippingPlane(
        std::uint32_t cameraId,
        float farClippingPlane
    );

    int Anjean_Camera_SetAspectRatio(
        std::uint32_t cameraId,
        float aspectRatio
    );

    
    int Anjean_Input_IsKeyDown(int KeyCode);
}