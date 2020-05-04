#include "./TextureManager.h"

/**
 * Render a texture with the given information.
 *
 * @param texture The source texture.
 * @param sourceRectangle A pointer to the source rectangle, or NULL for the entire texture.
 * @param destinationRectangle A pointer to the destination rectangle, or NULL for the entire rendering target.
 * @param flip An SDL_RendererFlip value stating which flipping actions should be performed on the texture.
 */
void TextureManager::Render(
    SDL_Texture* texture, SDL_Rect sourceRectangle,
    SDL_Rect destinationRectangle, SDL_RendererFlip flip
)
{
    SDL_RenderCopyEx(
        Game::renderer, texture, &sourceRectangle, &destinationRectangle,
        0.0, NULL, flip
    );
}

/**
 * Load a texture from a file.
 *
 * @param fileName File name/path to the image asset.
 */
SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}
