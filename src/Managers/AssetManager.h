#pragma once

#include <map>
#include "./EntityManager.h"
#include "./TextureManager.h"
#include "../Types.h"

class AssetManager
{
    private:
        EntityManager* manager;                     /** Pointer to the entity manager. */
        std::map<string, SDL_Texture*> textures;    /** Map of textures keyed by their ID. */

    public:
        AssetManager(EntityManager* manager);
        ~AssetManager();

        void AddTexture(string textureId, const char* fileName);
        void ClearAssets();
        SDL_Texture* GetTexture(string textureId);
};
