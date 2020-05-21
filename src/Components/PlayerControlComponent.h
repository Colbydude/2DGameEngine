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
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;

        /**
         * Initialize the player control component.
         */
        void Initialize() override
        {
            sprite = owner->GetComponent<SpriteComponent>();
            transform = owner->GetComponent<TransformComponent>();
        }

        /**
         * Very basic player movement.
         *
         * @param deltaTime
         */
        void Update(float deltaTime) override
        {
            if (InputManager::IsKeyPressed(SDL_SCANCODE_LEFT)) {
                transform->velocity.x = -10;
            }
            if (InputManager::IsKeyPressed(SDL_SCANCODE_RIGHT)) {
                transform->velocity.x = 10;
            }
        }
};
