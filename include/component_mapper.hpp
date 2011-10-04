#ifndef ARTEMIS_COMPONENTMAPPER_H
#define ARTEMIS_COMPONENTMAPPER_H

#include "util/typedefs.hpp"

class Entity;
class EntityManager;
class World;

template <class T>
class ComponentMapper
{
    public:
        ComponentMapper(ComponentId id, World* world); 
        T* get(Entity* e);
    private:
        ComponentId id_;
        EntityManager* em_;
};

#endif
