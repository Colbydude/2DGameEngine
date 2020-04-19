#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <string>
#include <vector>
#include "./Entity.h"
#include "./Component.h"

class EntityManager
{
    private:
        std::vector<Entity*> entities;      /** List of all game entities. */

    public:
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
        bool HasNoEntities();
        void Render();
        void Update(float deltaTime);
};

#endif
