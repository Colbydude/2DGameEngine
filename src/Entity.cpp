#include "./Entity.h"
#include "./Types.h"

/**
 * Construct a new instance of the entity.
 *
 * @param manager Reference to the entity manager.
 */
Entity::Entity(EntityManager& manager): manager(manager)
{
    this->isActive = true;
}

/**
 * Construct a new instance of the entity
 *
 * @param manager Reference to the entity manager.
 * @param name The name to identify the entity with.
 */
Entity::Entity(EntityManager &manager, string name) : manager(manager), name(name)
{
    this->isActive = true;
}

/**
 * Mark the entity as inactive.
 */
void Entity::Destroy()
{
    this->isActive = false;
}

/**
 * Get whether the entity is active.
 */
bool Entity::IsActive() const
{
    return this->isActive;
}

/**
 * Render the entity and all its components.
 */
void Entity::Render()
{
    for (auto& component: components) {
        component->Render();
    }
}

/**
 * Update the entity and all its components.
 *
 * @param deltaTime
 */
void Entity::Update(float deltaTime)
{
    for (auto& component: components) {
        component->Update(deltaTime);
    }
}
