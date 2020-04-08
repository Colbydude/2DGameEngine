#include <iostream>
#include "./Constants.h"
#include "./Game.h"

/**
 * Construct a new instance of the game.
 */
Game::Game()
{
    this->isRunning = false;
}

Game::~Game()
{
    //
}

/**
 * Destroy and clean up game objects.
 */
void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * Initialize the game by setting up the game window and renderer.
 *
 * @param width The window width.
 * @param height The window height.
 */
void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;

        return;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        0
    );

    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;

        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;

        return;
    }

    isRunning = true;

    return;
}

/**
 * Get whether or not the game is running.
 */
bool Game::IsRunning() const
{
    return this->isRunning;
}

/**
 * Process user input, such as key presses.
 */
void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            isRunning = false;

            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }

            break;
        }
        default: {
            break;
        }
    }
}

/**
 * Render the game objects.
 */
void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

/**
 * Update the game objects.
 */
void Game::Update()
{
    //
}
