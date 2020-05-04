#pragma once

#include <SDL2/SDL.h>
#include "./TransformComponent.h"
#include "../AssetManager.h"
#include "../Component.h"
#include "../TextureManager.h"
#include "../Types.h"

class SpriteComponent: public Component
{
    private:
        SDL_Rect destinationRectangle;                      /** The destination rectangle to render to. */
        SDL_Rect sourceRectangle;                           /** The source rectangle on the texture. */
        SDL_Texture* texture;                               /** The sprite texture. */
        TransformComponent* transform;                      /** The companion transform component. */

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;        /** The render flip state. */

        /**
         * Construct a new instance of the sprite component.
         *
         * @param assetTextureId The texture identifier.
         */
        SpriteComponent(string assetTextureId)
        {
            SetTexture(assetTextureId);
        }

        /**
         * Initialize the sprite with default settings.
         */
        void Initialize() override
        {
            transform = owner->GetComponent<TransformComponent>();

            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = transform->width;
            sourceRectangle.h = transform->height;
        }

        /**
         * Render the sprite.
         */
        void Render() override
        {
            TextureManager::Render(texture, sourceRectangle, destinationRectangle, spriteFlip);
        }

        /**
         * Set the texture for the sprite.
         */
        void SetTexture(string assetTextureId)
        {
            texture = Game::assetManager->GetTexture(assetTextureId);
        }

        /**
         * Update the sprite.
         *
         * @param deltaTime
         */
        void Update(float deltaTime) override
        {
            destinationRectangle.x = static_cast<int>(transform->position.x);
            destinationRectangle.y = static_cast<int>(transform->position.y);
            destinationRectangle.w = transform->width * transform->scale;
            destinationRectangle.h = transform->height * transform->scale;
        }
};
