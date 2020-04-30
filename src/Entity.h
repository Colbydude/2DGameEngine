#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>
#include <vector>
#include "./Component.h"
#include "./EntityManager.h"

class Component;
class EntityManager;

class Entity
{
    private:
        std::vector<Component*> components;                             /** List of components the entity has. */
        bool isActive;                                                  /** Whether or not the entity is active. */
        EntityManager& manager;                                         /** Reference to the entity manager. */
        std::map<const std::type_info*, Component*> componentTypeMap;   /** Map of components corresponding types. */

    public:
        std::string name;                                               /** Identifier for the entity. */

        Entity(EntityManager& manager);
        Entity(EntityManager&, std::string name);

        void Destroy();
        bool IsActive() const;
        void Render();
        void Update(float deltaTime);

        /**
         * Add a component to the entity.
         *
         * @param args
         */
        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));

            newComponent->owner = this;
            components.emplace_back(newComponent);
            componentTypeMap[&typeid(*newComponent)] = newComponent;
            newComponent->Initialize();

            return *newComponent;
        }

        /**
         * Get a component from the entity.
         */
        template <typename T>
        T* GetComponent()
        {
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }

        /**
         * Determine if the entity has a component of the given type.
         */
        template <typename T>
        bool HasComponent() const
        {
            return componentTypeMap.count(&typeid(T)) > 0;
        }
};

#endif
