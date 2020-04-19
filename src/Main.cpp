#include <iostream>
#include "./Constants.h"
#include "./Game.h"

/**
 * The main entrypoint for the application.
 *
 * @param argc The count of arguments.
 * @param args The arguments passed in.
 */
int main(int argc, char *args[])
{
    Game *game = new Game();

    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    return 0;
}
