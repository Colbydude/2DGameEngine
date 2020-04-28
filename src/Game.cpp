#include <iostream>
#include "./AssetManager.h"
#include "./Components/SpriteComponent.h"
#include "./Components/TransformComponent.h"
#include "./Constants.h"
#include "./Game.h"

EntityManager entityManager;
AssetManager *Game::assetManager = new AssetManager(&entityManager);
SDL_Renderer* Game::renderer;

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

    LoadContent();

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

void Game::LoadContent()
{
    // @TEMP
    std::string textureFilePath = "./assets/sprites/StanHelsing.png";
    assetManager->AddTexture("test-sprite", textureFilePath.c_str());

    Entity &newEntity(entityManager.AddEntity("test"));
    newEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    newEntity.AddComponent<SpriteComponent>("test-sprite");
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
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255); // Cornflower Blue. :)
    SDL_RenderClear(renderer);

    if (entityManager.HasNoEntities())
    {
        return;
    }

    entityManager.Render();

    SDL_RenderPresent(renderer);
}

/**
 * Update the game objects.
 */
void Game::Update()
{
    // Sleep the execution until we reach the target frame time in ms.
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    // Only call delay if we are too fast to process this frame.
    if (timeToWait > 0 && timeToWait < FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }

    // Difference of ticks from last frame, converted to seconds.
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value.
    deltaTime = (deltaTime > 0.05f) ? 0.05 : deltaTime;

    // Set ticks to be used in the next update loop.
    ticksLastFrame = SDL_GetTicks();

    entityManager.Update(deltaTime);
}
