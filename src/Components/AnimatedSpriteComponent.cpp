#include "./AnimatedSpriteComponent.h"
#include "./TransformComponent.h"
#include "../AssetManager.h"
#include "../TextureManager.h"

/**
 * Construct a new instance of the animated sprite component.
 */
AnimatedSpriteComponent::AnimatedSpriteComponent()
{
    //
}

/**
 * Initialize the animated sprite with default settings.
 */
void AnimatedSpriteComponent::Initialize()
{
    transform = owner->GetComponent<TransformComponent>();

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;

    currentIndex = 0;
    animSpeed = 60;
}

/**
 * Play the sprite animation.
 *
 * @param animIndex The Y-axis index on the sprite sheet.
 * @param animSpeed The animation speed.
 */
void AnimatedSpriteComponent::Play(unsigned int animIndex, int animSpeed)
{
    currentIndex = animIndex;
    this->animSpeed = animSpeed;
    isPlaying = true;
}

/**
 * Pause the sprite animation.
 */
void AnimatedSpriteComponent::Pause()
{
    isPlaying = false;
}

/**
 * Render the animated sprite.
 */
void AnimatedSpriteComponent::Render()
{
    TextureManager::Render(texture, srcRect, destRect, spriteFlip);
}

/**
 * Sets the texture for the component.
 *
 * @param assetTextureId The texture identifier.
 * @param playOnStart Whether or not to start animating immediately.
 */
void AnimatedSpriteComponent::SetAnimatedTexture(string assetTextureId, bool playOnStart)
{
    texture = Game::assetManager->GetTexture(assetTextureId);
    SetAnimationFrames();
    isPlaying = playOnStart;
}

/**
 * Set the animations on the sprite based on the sheet width and height.
 */
void AnimatedSpriteComponent::SetAnimationFrames()
{
    int textureWidth;
    int textureHeight;

    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

    for (int i = 0; i < textureHeight / srcRect.h; i++) {
        Animation animData = Animation(i, textureWidth / srcRect.w);
        animations.emplace(i, animData);
    }
}

/**
 * Stop the animation and reset the timer.
 */
void AnimatedSpriteComponent::Stop()
{
    isPlaying = false;
    animTimer = 0;
}

/**
 * Animate the sprite if playing.
 *
 * @param deltaTime
 */
void AnimatedSpriteComponent::Update(float deltaTime)
{
    if (isPlaying) {
        animTimer += deltaTime * 1000;
        srcRect.x = srcRect.w * static_cast<int>(
            (static_cast<int>(animTimer) / animSpeed) % animations.at(currentIndex).numFrames
        );
    }

    srcRect.y = currentIndex * transform->height;
    destRect.x = static_cast<int>(transform->position.x);
    destRect.y = static_cast<int>(transform->position.y);
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;
}
