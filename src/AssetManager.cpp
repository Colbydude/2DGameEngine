#include "./AssetManager.h"

/**
 * Construct a new instance of the asset manager.
 *
 * @param manager A pointer to the entity manager.
 */
AssetManager::AssetManager(EntityManager* manager): manager(manager)
{

}

/**
 * Add a texture to our list of textures.
 *
 * @param textureId The texture identifier.
 * @param fileName File name/path to the image asset.
 */
void AssetManager::AddTexture(std::string textureId, const char* fileName)
{
    textures.emplace(textureId, TextureManager::LoadTexture(fileName));
}

/**
 * Clear out all assets.
 */
void AssetManager::ClearAssets()
{
    textures.clear();
}

/**
 * Get a texture from the texture manager with the given texture ID.
 *
 * @param textureId The texture identifier.
 */
SDL_Texture* AssetManager::GetTexture(std::string textureId)
{
    return textures[textureId];
}
