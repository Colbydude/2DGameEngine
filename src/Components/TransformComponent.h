#pragma once

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../Game.h"
#include "../../lib/glm/glm.hpp"

class TransformComponent: public Component
{
    public:
        int height;
        glm::vec2 position;
        int scale;
        glm::vec2 velocity;
        int width;

        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
        {
            position = glm::vec2(posX, posY);
            velocity = glm::vec2(velX, velY);
            width = w;
            height = h;
            scale = s;
        }

        void Update(float deltaTime) override
        {
            position.x += velocity.x * deltaTime;
            position.y += velocity.y * deltaTime;
        }
};
