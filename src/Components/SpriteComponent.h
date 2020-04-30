#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include "./TransformComponent.h"
#include "../Animation.h"
#include "../AssetManager.h"
#include "../Component.h"
#include "../TextureManager.h"

class SpriteComponent: public Component
{
    private:
        std::map<std::string, Animation> animations;
        unsigned int animationIndex = 0;
        int animationSpeed;
        std::string currentAnimationName;
        SDL_Rect destinationRectangle;
        bool isAnimated;
        bool isFixed;
        int numFrames;
        SDL_Rect sourceRectangle;
        SDL_Texture* texture;
        TransformComponent* transform;

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

        SpriteComponent(std::string assetTextureId)
        {
            isAnimated = false;
            isFixed = false;

            SetTexture(assetTextureId);
        }

        SpriteComponent(std::string id, int numFrames, int animationSpeed, bool isFixed)
        {
            isAnimated = true;

            this->animationSpeed = animationSpeed;
            this->isFixed = isFixed;
            this->numFrames = numFrames;

            Animation singleAnimation = Animation(0, numFrames, animationSpeed);
            animations.emplace("SingleAnimation", singleAnimation);
            this->animationIndex = 0;
            this->currentAnimationName = "SingleAnimation";

            Play(this->currentAnimationName);
            SetTexture(id);
        }

        void Initialize() override
        {
            transform = owner->GetComponent<TransformComponent>();

            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = transform->width;
            sourceRectangle.h = transform->height;
        }

        void Play(std::string animationName)
        {
            numFrames = animations[animationName].numFrames;
            animationIndex = animations[animationName].index;
            animationSpeed = animations[animationName].animationSpeed;
            currentAnimationName = animationName;
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
            if (isAnimated) {
                sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
            }

            sourceRectangle.y = animationIndex * transform->height;

            destinationRectangle.x = static_cast<int>(transform->position.x);
            destinationRectangle.y = static_cast<int>(transform->position.y);
            destinationRectangle.w = transform->width * transform->scale;
            destinationRectangle.h = transform->height * transform->scale;
        }
};

#endif
