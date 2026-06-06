#include "NativeBindings.h"

#include "../Runtime.h"
#include "../RuntimeTypes.h"
#include "../objects/GameObject.h"
#include "../../Core/Core.h"
#include "../objects/Camera.h"

namespace
{
    Anjean::Runtime::Runtime* g_runtime = nullptr;

    constexpr int ANJEAN_OK = 0;
    constexpr int ANJEAN_ERR_NO_RUNTIME = -1;
    constexpr int ANJEAN_ERR_NULL_ARGUMENT = -2;
    constexpr int ANJEAN_ERR_GAME_OBJECT_NOT_FOUND = -3;
    constexpr int ANJEAN_ERR_UNKNOWN = -999;
    constexpr int ANJEAN_ERR_WRONG_OBJECT_TYPE = -5;
    constexpr int ANJEAN_ERR_MESH_NOT_FOUND = -6;

    Anjean::Runtime::Camera& getCameraById(std::uint32_t cameraId)
    {
        auto& object = g_runtime->getGameObjectById(cameraId);

        if (object.getGameObjectType() != Anjean::Runtime::ANJEAN_GAMEOBJECT_CAMERA)
        {
            throw std::bad_cast();
        }

        return static_cast<Anjean::Runtime::Camera&>(object);
    }
}

namespace Anjean::Runtime
{
    void BindNativeRuntime(Runtime* runtime)
    {
        g_runtime = runtime;
    }
}

extern "C"
{
  int Anjean_Runtime_CreateGameObject(std::uint32_t* outGameObjectId)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    if (!outGameObjectId)
    {
        return ANJEAN_ERR_NULL_ARGUMENT;
    }

    try
    {
        auto& object = g_runtime->createGameObject();
        *outGameObjectId = object.id;

        return ANJEAN_OK;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

  int Anjean_Runtime_CreateCamera(std::uint32_t* outCameraId)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    if (!outCameraId)
    {
        return ANJEAN_ERR_NULL_ARGUMENT;
    }

    try
    {
        auto& camera = g_runtime->createCamera();
        *outCameraId = camera.id;

        return ANJEAN_OK;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_Camera_SetFieldOfView(
    std::uint32_t cameraId,
    float fieldOfView
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& camera = getCameraById(cameraId);
        camera.fieldOfView = fieldOfView;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (const std::bad_cast&)
    {
        return ANJEAN_ERR_WRONG_OBJECT_TYPE;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_Camera_SetNearClippingPlane(
    std::uint32_t cameraId,
    float nearClippingPlane
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& camera = getCameraById(cameraId);
        camera.nearClippingPlane = nearClippingPlane;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (const std::bad_cast&)
    {
        return ANJEAN_ERR_WRONG_OBJECT_TYPE;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_Camera_SetFarClippingPlane(
    std::uint32_t cameraId,
    float farClippingPlane
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& camera = getCameraById(cameraId);
        camera.farClippingPlane = farClippingPlane;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (const std::bad_cast&)
    {
        return ANJEAN_ERR_WRONG_OBJECT_TYPE;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_Camera_SetAspectRatio(
    std::uint32_t cameraId,
    float aspectRatio
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& camera = getCameraById(cameraId);
        camera.aspectRatio = aspectRatio;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (const std::bad_cast&)
    {
        return ANJEAN_ERR_WRONG_OBJECT_TYPE;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_Runtime_SetCurrentCamera(std::uint32_t cameraId)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& camera = getCameraById(cameraId);

        g_runtime->setCurrentCamera(camera.id);

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (const std::bad_cast&)
    {
        return ANJEAN_ERR_WRONG_OBJECT_TYPE;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

  int Anjean_Runtime_GetCurrentCamera(std::uint32_t* outCameraId)
  {
      if (!g_runtime)
      {
          return ANJEAN_ERR_NO_RUNTIME;
      }

      if (!outCameraId)
      {
          return ANJEAN_ERR_NULL_ARGUMENT;
      }

      try
      {
          *outCameraId = g_runtime->getCurrentCamera().id;
          return ANJEAN_OK;
      }
      catch (const std::runtime_error&)
      {
          return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
      }
      catch (...)
      {
          return ANJEAN_ERR_UNKNOWN;
      }
  }


int Anjean_GameObject_GetPosition(
    std::uint32_t gameObjectId,
    AnjeanVec3* outPosition
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    if (!outPosition)
    {
        return ANJEAN_ERR_NULL_ARGUMENT;
    }

    try
    {
        auto& object = g_runtime->getGameObjectById(gameObjectId);

        outPosition->x = object.transform.position.x;
        outPosition->y = object.transform.position.y;
        outPosition->z = object.transform.position.z;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_GameObject_SetPosition(
    std::uint32_t gameObjectId,
    AnjeanVec3 position
)
{
    if (!g_runtime)
    {
        return ANJEAN_ERR_NO_RUNTIME;
    }

    try
    {
        auto& object = g_runtime->getGameObjectById(gameObjectId);

        object.transform.position.x = position.x;
        object.transform.position.y = position.y;
        object.transform.position.z = position.z;

        return ANJEAN_OK;
    }
    catch (const std::runtime_error&)
    {
        return ANJEAN_ERR_GAME_OBJECT_NOT_FOUND;
    }
    catch (...)
    {
        return ANJEAN_ERR_UNKNOWN;
    }
}

int Anjean_GameObject_SetMesh(
    std::uint32_t gameObjectId,
    std::uint32_t meshId
)
{
    if (!g_runtime)
    {
        return -1;
    }

    if (meshId == 0)
    {
        return ANJEAN_ERR_NULL_ARGUMENT;
    }

    try
    {
        auto& object = g_runtime->getGameObjectById(gameObjectId);

        std::vector<Anjean::Runtime::Mesh> meshes = g_runtime->getAllMeshes();

        for (const Anjean::Runtime::Mesh& mesh : meshes)
        {
            if (mesh.id == meshId)
            {
                object.mesh = mesh;
                return ANJEAN_OK;
            }
        }

        return -4; // mesh id not found
    }
    catch (...)
    {
        return -999;
    }
  }

  int Anjean_GameObject_SetTexture(
    std::uint32_t gameObjectId,
    const char* filename,
    std::uint32_t width,
    std::uint32_t height,
    std::uint32_t channels
)
{
    if (!g_runtime)
    {
        return -1;
    }

    if (!filename)
    {
        return -2;
    }

    try
    {
        auto& object = g_runtime->getGameObjectById(gameObjectId);

        Anjean::Runtime::Texture texture{};
        texture.filename = filename;
        texture.width = width;
        texture.height = height;
        texture.channels = channels;

        object.texture = texture;

        return 0;
    }
    catch (...)
    {
        return -999;
    }
  }

  int32_t Anjean_Input_IsKeyDown(int32_t keyCode)
  {
      if (!g_runtime)
      {
          return 0;
      }

      auto key = static_cast<Anjean::Runtime::Key>(keyCode);

      if (key <= Anjean::Runtime::Key::Unknown ||
          key >= Anjean::Runtime::Key::Count)
      {
          return 0;
      }

      return g_runtime->inputManager.isKeyDown(key) ? 1 : 0;
  }

}