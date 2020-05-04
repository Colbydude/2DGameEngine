#pragma once

#include <vector>
#include "../Component.h"
#include "../Entity.h"
#include "../Types.h"

class Component;
class Entity;

class EntityManager
{
    private:
        std::vector<Entity*> entities;      /** List of all game entities. */

    public:
        Entity& AddEntity(string entityName);
        void ClearEntities();
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
        bool HasNoEntities();
        void Render();
        void Update(float deltaTime);
};
