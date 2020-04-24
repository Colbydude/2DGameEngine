#ifndef COMPONENT_H
#define COMPONENT_H

#include "./Entity.h"

class Entity;

class Component
{
    public:
        Entity* owner;              /** The entity this component belongs to. */

        virtual ~Component() {}

        virtual void Initialize() {}
        virtual void Render() {}
        virtual void Update(float deltaTime) {}
};

#endif;
