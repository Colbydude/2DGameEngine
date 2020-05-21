#include "./PlayerControlComponent.h"

/**
 * Initialize the player control component.
 */
void PlayerControlComponent::Initialize()
{
    sprite = owner->GetComponent<SpriteComponent>();
    transform = owner->GetComponent<TransformComponent>();
}

/**
 * Very basic player movement.
 *
 * @param deltaTime
 */
void PlayerControlComponent::Update(float deltaTime)
{
    int holdL, holdR;
    int speed;

    holdL = InputManager::IsActionPressed(Action::Left);
    holdR = InputManager::IsActionPressed(Action::Right);

    // Cancel opposing keys
    if (holdL == 1 && holdR == 1)
    {
        holdL = 0;
        holdR = 0;
    }

    int moveX = (holdR - holdL) * moveSpeed;

    if (moveX != 0)
    {
        transform->position.x += moveX * deltaTime;
    }
}
