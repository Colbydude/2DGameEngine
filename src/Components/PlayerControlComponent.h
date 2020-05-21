#pragma once

#include <iostream>
#include "./SpriteComponent.h"
#include "./TransformComponent.h"
#include "../Managers/EntityManager.h"
#include "../Managers/InputManager.h"
#include "../Game.h"
#include "../Types.h"

class PlayerControlComponent: public Component
{
    private:
        int moveSpeed = 12;             /** Movement speed. */

    public:
        TransformComponent *transform;  /** The companion transform component. */
        SpriteComponent *sprite;        /** The companion sprite component. */

        void Initialize() override;
        void Update(float deltaTime) override;
};
