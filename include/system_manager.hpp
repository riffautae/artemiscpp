#ifndef ARTEMIS_SYSTEM_MANAGER_H
#define ARTEMIS_SYSTEM_MANAGER_H

#include <map>

#include "util/bag.hpp"
#include "util/typedefs.hpp"

class World;
class EntitySystem;

class SystemManager
{
    private:
        World* world_;
        std::map<SystemId, EntitySystem*> systems_;
    public:
        SystemManager(World* world);
        EntitySystem* addSystem(EntitySystem* system);
        template <class T>
        T* getSystem(SystemId id);
        std::map<EntityId, EntitySystem*> getSystems();
        void initializeAll();
};

#endif
