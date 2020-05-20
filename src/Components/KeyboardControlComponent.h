#pragma once

#include <iostream>
#include "./SpriteComponent.h"
#include "./TransformComponent.h"
#include "../Managers/EntityManager.h"
#include "../Game.h"
#include "../Types.h"

class KeyboardControlComponent: public Component
{
    public:
        string leftKey;         // Left DPad
        string rightKey;        // Right DPad
        string jumpKey;         // A Button
        string actionKey;       // B Button

        TransformComponent *transform;
        SpriteComponent *sprite;

        KeyboardControlComponent()
        {
            //
        }

        KeyboardControlComponent(string leftKey, string rightKey, string jumpKey, string actionKey)
        {
            this->leftKey = GetSDLKeyStringCode(leftKey);
            this->rightKey = GetSDLKeyStringCode(rightKey);
            this->jumpKey = GetSDLKeyStringCode(jumpKey);
            this->actionKey = GetSDLKeyStringCode(actionKey);
        }

        string GetSDLKeyStringCode(string key)
        {
            if (key.compare("left") == 0) return "1073741904";  // Left Arrow
            if (key.compare("right") == 0) return "1073741903"; // Right Arrow

            return std::to_string(static_cast<int>(key[0]));
        }

        void Initialize() override
        {
            sprite = owner->GetComponent<SpriteComponent>();
            transform = owner->GetComponent<TransformComponent>();
        }

        void Update(float deltaTime) override
        {
            if (Game::event.type == SDL_KEYDOWN) {
                string keyCode = std::to_string(Game::event.key.keysym.sym);

                std::cout << keyCode << " pressed." << std::endl;

                if (keyCode.compare(leftKey) == 0) {
                    transform->velocity.x = -10;
                }
                if (keyCode.compare(rightKey) == 0) {
                    transform->velocity.x = 10;
                }
                if (keyCode.compare(jumpKey) == 0) {
                    // @TODO
                }
                if (keyCode.compare(actionKey) == 0) {
                    // @TODO
                }
            }

            if (Game::event.type == SDL_KEYUP) {
                string keyCode = std::to_string(Game::event.key.keysym.sym);

                std::cout << keyCode << " released." << std::endl;

                if (keyCode.compare(leftKey) == 0)
                {
                    transform->velocity.x = 0;
                }
                if (keyCode.compare(rightKey) == 0)
                {
                    transform->velocity.x = 0;
                }
                if (keyCode.compare(jumpKey) == 0)
                {
                    // @TODO
                }
                if (keyCode.compare(actionKey) == 0)
                {
                    // @TODO
                }
            }
        }
};
