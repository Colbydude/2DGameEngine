#include "./EntityManager.h"

/**
 * Instantiate a new entity with the given identifier and add it to the list.
 *
 * @param entityName The name to identify the entity with.
 */
Entity& EntityManager::AddEntity(std::string entityName)
{
    Entity *entity = new Entity(*this, entityName);
    entities.emplace_back(entity);

    return *entity;
}

/**
 * Mark all entities as inactive.
 */
void EntityManager::ClearEntities()
{
    for (auto& entity: entities) {
        entity->Destroy();
    }
}

/**
 * Get all the entities in the manager.
 */
std::vector<Entity*> EntityManager::GetEntities() const
{
    return entities;
}

/**
 * Get the count of entities.
 */
unsigned int EntityManager::GetEntityCount()
{
    return entities.size();
}

/**
 * Whether or not the manager has entities.
 */
bool EntityManager::HasNoEntities()
{
    return entities.size() == 0;
}

/**
 * Render all the entities in the manager.
 */
void EntityManager::Render()
{
    for (auto& entity: entities) {
        entity->Render();
    }
}

/**
 * Update all entities in the manager.
 *
 * @param deltaTime
 */
void EntityManager::Update(float deltaTime)
{
    for (auto& entity: entities) {
        entity->Update(deltaTime);
    }
}
