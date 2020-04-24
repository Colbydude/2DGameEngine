#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "./Component.h"
#include "./EntityManager.h"

class Component;
class EntityManager;

class Entity
{
    private:
        std::vector<Component*> components;     /** List of components the entity has. */
        bool isActive;                          /** Whether or not the entity is active. */
        EntityManager& manager;                 /** Reference to the entity manager. */

    public:
        std::string name;                       /** Identifier for the entity. */

        Entity(EntityManager& manager);
        Entity(EntityManager&, std::string name);

        void Destroy();
        bool IsActive() const;
        void Render();
        void Update(float deltaTime);

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));

            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->Initialize();

            return *newComponent;
        }
};

#endif
