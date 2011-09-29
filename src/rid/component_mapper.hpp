#ifndef ARTEMIS_COMPONENTMAPPER_H
#define ARTEMIS_COMPONENTMAPPER_H

#include <string>

#include "component.h"
#include "component_type.hpp"
#include "entity.hpp"
#include "entity_manager.hpp"
#include "world.hpp"

#include "util/typedefs.hpp"


template <class T>
class ComponentMapper
{
    public:
        ComponentMapper(World* world); 
        get(Entity* e);
    private:
        ComponentType* type_;
        EntityManager* em_;
}

#endif
