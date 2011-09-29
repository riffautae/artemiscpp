#ifndef ARTEMIS_COMPONENTMAPPER_H
#define ARTEMIS_COMPONENTMAPPER_H

#include <string>

#include "component.hpp"
#include "entity.hpp"
#include "entity_manager.hpp"
#include "util/typedefs.hpp"

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
