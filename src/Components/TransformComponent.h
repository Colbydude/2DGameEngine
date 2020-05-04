#pragma once

#include <SDL2/SDL.h>
#include "../Managers/EntityManager.h"
#include "../Game.h"
#include "../Types.h"

class TransformComponent: public Component
{
    public:
        int height;                 /** The height, in pixels, of the component. */
        Vector2 position;           /** The x and y position of the component. */
        int scale;                  /** The scale factor of the component. */
        Vector2 velocity;           /** The x and y velocity of the component. */
        int width;                  /** The width, in pixels, of the component. */

        /**
         * Construct a new instance of the transform component.
         *
         * @param posX
         * @param posY
         * @param velX
         * @param velY
         * @param w
         * @param h
         * @param s
         */
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
        {
            position = Vector2(posX, posY);
            velocity = Vector2(velX, velY);
            width = w;
            height = h;
            scale = s;
        }

        /**
         * Update the position of the component by the velocity.
         *
         * @param deltaTime
         */
        void Update(float deltaTime) override
        {
            position.x += velocity.x * deltaTime;
            position.y += velocity.y * deltaTime;
        }
};
