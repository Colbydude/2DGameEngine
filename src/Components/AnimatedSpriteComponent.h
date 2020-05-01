#ifndef ANIMATEDSPRITECOMPONENT_H
#define ANIMATEDSPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include "../Component.h"
#include "./TransformComponent.h"

struct Animation
{
    unsigned int startIndex;
    unsigned int numFrames;

    Animation(unsigned int startIndex, unsigned int numFrames)
    {
        this->startIndex = startIndex;
        this->numFrames = numFrames;
    }
};

class AnimatedSpriteComponent : public Component
{
    private:
        std::map<unsigned int, Animation> animations;
        float animTimer;
        int animSpeed;
        unsigned int currentIndex;
        SDL_Rect destRect;
        bool isFixed;
        bool isPlaying;
        SDL_Rect srcRect;
        SDL_Texture* texture;
        TransformComponent* transform;

        void SetAnimationFrames();

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

        AnimatedSpriteComponent();

        void Initialize() override;
        void Pause();
        void Play(unsigned int animIndex, int animSpeed = 60);
        void Render() override;
        void SetAnimatedTexture(std::string assetTextureId, bool playOnStart = true);
        void Stop();
        void Update(float deltaTime) override;
};

#endif
