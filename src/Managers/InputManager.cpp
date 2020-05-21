#include "./InputManager.h"

/**
 * Get the current keyboard state.
 */
Uint8 InputManager::GetCurrentKeyboardState()
{
    return *currentKeyboardState;
}

/**
 * Initialize the InputManager and set the default action maps.
 */
void InputManager::Initialize()
{
    ResetActionMaps();
}

/**
 * If mapped gamepad button or key is pressed.
 *
 * @param actionMap
 */
bool InputManager::IsActionMapPressed(ActionMap* actionMap)
{
    for (int i = 0; i < actionMap->keyboardKeys.size(); i++) {
        if (IsKeyPressed(actionMap->keyboardKeys[i])) {
            return true;
        }
    }

    // @TODO Gamepad actions.

    return false;
}

/**
 * If mapped gamepad button or key is released this frame.
 *
 * @param actionMap
 */
bool InputManager::IsActionMapReleased(ActionMap* actionMap)
{
    for (int i = 0; i < actionMap->keyboardKeys.size(); i++) {
        if (IsKeyReleased(actionMap->keyboardKeys[i])) {
            return true;
        }
    }

    // @TODO Gamepad actions.

    return false;
}

/**
 * If mapped gamepad button or key is pressed this frame.
 *
 * @param actionMap
 */
bool InputManager::IsActionMapTriggered(ActionMap* actionMap)
{
    for (int i = 0; i < actionMap->keyboardKeys.size(); i++) {
        if (IsKeyTriggered(actionMap->keyboardKeys[i])) {
            return true;
        }
    }

    // @TODO Gamepad actions.

    return false;
}

/**
 * If an action is pressed.
 *
 * @param action
 */
bool InputManager::IsActionPressed(Action action)
{
    return IsActionMapPressed(actionMaps[(int) action]);
}

/**
 * If the action is released this frame.
 *
 * @param action
 */
bool InputManager::IsActionReleased(Action action)
{
    return IsActionMapReleased(actionMaps[(int) action]);
}

/**
 * If the action is pressed this frame.
 *
 * @param action
 */
bool InputManager::IsActionTriggered(Action action)
{
    return IsActionMapTriggered(actionMaps[(int) action]);
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
 * If the key is released this frame.
 *
 * @param scancode
 */
bool InputManager::IsKeyReleased(SDL_Scancode scancode)
{
    return (!currentKeyboardState[scancode] && prevKeyboardState[scancode]);
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
