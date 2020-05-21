#pragma once

#include <SDL2/SDL_keyboard.h>
#include <vector>

/**
 * Game actions.
 */
enum class Action {
    Left,
    Right,
    Jump,
    Action,
    TotalActionCount
};

/**
 * Mapping of gamepad buttons/keys to actions, in order.
 */
class ActionMap
{
    public:
        // std::vector<SDL_GamePad?> gamePadButtons;
        std::vector<SDL_Scancode> keyboardKeys;
};

class InputManager
{
    private:
        inline static ActionMap *actionMaps[(int) Action::TotalActionCount];    /** List of action maps to use. */
        inline static const Uint8 *currentKeyboardState;                        /** The keyboard state this frame. */
        inline static const Uint8 *prevKeyboardState;                           /** The keyboard state last frame. */

        static bool IsActionMapPressed(ActionMap* actionMap);
        static bool IsActionMapReleased(ActionMap* actionMap);
        static bool IsActionMapTriggered(ActionMap* actionMap);

    public:
        static Uint8 GetCurrentKeyboardState();
        static void Initialize();
        static bool IsActionPressed(Action action);
        static bool IsActionReleased(Action action);
        static bool IsActionTriggered(Action action);
        static bool IsKeyPressed(SDL_Scancode scancode);
        static bool IsKeyReleased(SDL_Scancode scancode);
        static bool IsKeyTriggered(SDL_Scancode scancode);
        static void ResetActionMaps();
        static void Update();
};
