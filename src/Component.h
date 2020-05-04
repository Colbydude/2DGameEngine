#pragma once

#include "./Entity.h"

class Entity;

class Component
{
    public:
        Entity* owner;              /** Pointer to the entity this component belongs to. */

        virtual ~Component() {}

        virtual void Initialize() {}
        virtual void Render() {}
        virtual void Update(float deltaTime) {}
};
