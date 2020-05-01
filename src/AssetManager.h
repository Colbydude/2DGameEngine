#pragma once

#include <map>
#include <string>
#include "./EntityManager.h"
#include "./TextureManager.h"

class AssetManager
{
    private:
        EntityManager* manager;
        std::map<std::string, SDL_Texture*> textures;

    public:
        AssetManager(EntityManager* manager);
        ~AssetManager();

        void AddTexture(std::string textureId, const char* fileName);
        void ClearAssets();
        SDL_Texture* GetTexture(std::string textureId);
};
