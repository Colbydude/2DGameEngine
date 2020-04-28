#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "./Component.h"
#include "./Entity.h"
#include "./EntityManager.h"

class AssetManager;

class Game
{
    private:
        bool isRunning;                     /** Whether or not the game is running. */
        SDL_Window* window;                 /** The main SDL window. */

    public:
        static AssetManager* assetManager;  /** The global asset manager. */
        static SDL_Renderer* renderer;      /** The main SDL renderer. */
        int ticksLastFrame;                 /** The amount of ticks last frame. */

        Game();
        ~Game();

        void Destroy();
        void Initialize(int width, int height);
        bool IsRunning() const;
        void LoadContent(); // @TEMP
        void ProcessInput();
        void Render();
        void Update();
};

#endif
