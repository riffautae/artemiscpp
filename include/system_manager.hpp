#ifndef ARTEMIS_SYSTEM_MANAGER_H
#define ARTEMIS_SYSTEM_MANAGER_H

#include <tr1/unordered_map>

#include "util/bag.hpp"
#include "util/typedefs.hpp"

#include "entity_system.hpp"
#include "world.hpp"

class SystemManager
{
    private:
        World* world_;
        std::tr1::unordered_map<EntityId, EntitySystem*> systems_;
        Bag<EntitySystem*> bagged_;
    public:
        SystemManager(World* world);
        EntitySystem* setSystem(EntitySystem* system);
        template <EntitySystem* T> T getSystem(EntityID id);
        Bag<EntitySystem*> getSystems();
        void initializeAll();
};

#endif
