#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include "./TransformComponent.h"
#include "../AssetManager.h"
#include "../Component.h"
#include "../TextureManager.h"

class SpriteComponent: public Component
{
    private:
        SDL_Rect destinationRectangle;
        SDL_Rect sourceRectangle;
        SDL_Texture* texture;
        TransformComponent* transform;

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

        SpriteComponent(std::string assetTextureId)
        {
            SetTexture(assetTextureId);
        }

        void Initialize() override
        {
            transform = owner->GetComponent<TransformComponent>();

            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = transform->width;
            sourceRectangle.h = transform->height;
        }

        void Render() override
        {
            TextureManager::Draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
        }

        void SetTexture(std::string assetTextureId)
        {
            texture = Game::assetManager->GetTexture(assetTextureId);
        }

        void Update(float deltaTime) override
        {
            destinationRectangle.x = static_cast<int>(transform->position.x);
            destinationRectangle.y = static_cast<int>(transform->position.y);
            destinationRectangle.w = transform->width * transform->scale;
            destinationRectangle.h = transform->height * transform->scale;
        }
};

#endif
