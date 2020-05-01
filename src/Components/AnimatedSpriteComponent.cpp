#include "./AnimatedSpriteComponent.h"
#include "./TransformComponent.h"
#include "../AssetManager.h"
#include "../TextureManager.h"

AnimatedSpriteComponent::AnimatedSpriteComponent()
{
    //
}

void AnimatedSpriteComponent::Initialize()
{
    texture = Game::assetManager->GetTexture("default");
    transform = owner->GetComponent<TransformComponent>();
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
    currentIndex = 0;
    animSpeed = 60;
}

void AnimatedSpriteComponent::Play(unsigned int animIndex, int animSpeed)
{
    currentIndex = animIndex;
    this->animSpeed = animSpeed;
    isPlaying = true;
}

void AnimatedSpriteComponent::Pause()
{
    isPlaying = false;
}

void AnimatedSpriteComponent::Render()
{
    TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
}

void AnimatedSpriteComponent::SetAnimatedTexture(std::string assetTextureId, bool playOnStart = true)
{
    texture = Game::assetManager->GetTexture(assetTextureId);
    SetAnimationFrames();
    isPlaying = playOnStart;
}

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

void AnimatedSpriteComponent::Stop()
{
    isPlaying = false;
    animTimer = 0;
}

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
