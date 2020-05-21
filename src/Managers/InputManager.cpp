#include "./InputManager.h"

/**
 * Initialize the InputManager and set the default action maps.
 */
void InputManager::Initialize()
{
    ResetActionMaps();
}

/**
 * If an action is pressed.
 *
 * @param action
 */
bool InputManager::IsActionPressed(Action action)
{
    // @TODO
    return false;
}

/**
 * If the action is pressed this frame.
 *
 * @param action
 */
bool InputManager::IsActionTriggered(Action action)
{
    // @TODO
    return false;
}

/**
 * If the key is currently pressed.
 *
 * @param scancode
 */
bool InputManager::IsKeyPressed(SDL_Scancode scancode)
{
    return currentKeyboardState[scancode];
}

/**
 * If the key was just pressed this frame.
 *
 * @param scancode
 */
bool InputManager::IsKeyTriggered(SDL_Scancode scancode)
{
    return (currentKeyboardState[scancode] && !prevKeyboardState[scancode]);
}

/**
 * Reset to the default action maps.
 */
void InputManager::ResetActionMaps()
{
    actionMaps[(int) Action::Left] = new ActionMap();
    actionMaps[(int) Action::Left]->keyboardKeys.emplace_back(SDL_SCANCODE_LEFT);

    actionMaps[(int) Action::Right] = new ActionMap();
    actionMaps[(int) Action::Right]->keyboardKeys.emplace_back(SDL_SCANCODE_RIGHT);

    actionMaps[(int) Action::Jump] = new ActionMap();
    actionMaps[(int) Action::Jump]->keyboardKeys.emplace_back(SDL_SCANCODE_Z);

    actionMaps[(int) Action::Action] = new ActionMap();
    actionMaps[(int) Action::Action]->keyboardKeys.emplace_back(SDL_SCANCODE_X);
}

/**
 * Set the keyboard state internally.
 */
void InputManager::Update()
{
    prevKeyboardState = currentKeyboardState;
    currentKeyboardState = SDL_GetKeyboardState(NULL);
}
