#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game
{
    private:
        bool isRunning;             /** Whether or not the game is running. */
        SDL_Renderer *renderer;     /** The main SDL renderer. */
        SDL_Window *window;         /** The main SDL window. */

    public:
        Game();
        ~Game();
        void Destroy();
        void Initialize(int width, int height);
        bool IsRunning() const;
        void ProcessInput();
        void Render();
        void Update();
};

#endif
