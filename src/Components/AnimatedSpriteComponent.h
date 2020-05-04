#pragma once

#include <SDL2/SDL.h>
#include "./TransformComponent.h"
#include "../Component.h"
#include "../Types.h"

/**
 * A simple animation container.
 *
 * @struct Animation
 */
struct Animation
{
    unsigned int startIndex;                                /** The index determined by the Y-axis position in the sprite sheet. */
    unsigned int numFrames;                                 /** Number of frames determined by the X-axis in the sprite sheet. */

    /**
     * Construct a new animation.
     *
     * @param startIndex
     * @param numFrames
     */
    Animation(unsigned int startIndex, unsigned int numFrames)
    {
        this->startIndex = startIndex;
        this->numFrames = numFrames;
    }
};

class AnimatedSpriteComponent : public Component
{
    private:
        std::map<unsigned int, Animation> animations;       /** Map of animations keyed by the Y-axis index of the sprite sheet. */
        float animTimer;                                    /** Animation ticks. */
        int animSpeed;                                      /** Animation frame time. */
        unsigned int currentIndex;                          /** Current animation index. */
        SDL_Rect destRect;                                  /** The destination rectangle to render to. */
        bool isPlaying;                                     /** Whether or not the animation is playing. */
        SDL_Rect srcRect;                                   /** The source rectangle on the texture. */
        SDL_Texture* texture;                               /** The sprite sheet texture. */
        TransformComponent* transform;                      /** The companion transform component. */

        void SetAnimationFrames();

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;        /** The render flip state. */

        AnimatedSpriteComponent();

        void Initialize() override;
        void Pause();
        void Play(unsigned int animIndex, int animSpeed = 60);
        void Render() override;
        void SetAnimatedTexture(string assetTextureId, bool playOnStart = true);
        void Stop();
        void Update(float deltaTime) override;
};
