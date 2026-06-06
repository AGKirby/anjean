#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <stdexcept>

#include "objects/GameObject.h"
#include "objects/Camera.h"
#include "RuntimeTypes.h"
#include "scripting/ScriptingEngine.h"
#include "input/InputManager.h"

namespace Anjean::Runtime
{
    class Runtime
    {
    public:
        Runtime();

        void beginTick();
        void executeTick();
        void endTick();

        GameObject& createGameObject();
        Camera& createCamera();

        GameObject& getGameObjectById(std::uint32_t id);

        void setCurrentCamera(std::uint32_t cameraId);
        Camera& getCurrentCamera();

        std::vector<GameObject*> getRenderableSceneObjects();

        std::vector<Mesh> getAllMeshes();
        std::vector<Texture> getAllTextures();

        InputManager inputManager;

    private:
        std::vector<std::unique_ptr<GameObject>> sceneObjects;

        std::uint32_t nextGameObjectId = 1;
        std::uint32_t currentCameraId = 0;

        ScriptingEngine scriptingEngine;
    };
}