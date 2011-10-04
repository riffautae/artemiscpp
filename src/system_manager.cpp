#include "boost/foreach.hpp"

#include "system_manager.hpp"
#include "entity_system.hpp"
#include "world.hpp"

SystemManager::SystemManager(World* world)
{
    world_ = world;
    systems_ = std::map<EntityId, EntitySystem*>();
}

EntitySystem* SystemManager::addSystem(EntitySystem* system)
{
    system->set_world(world_);

    systems_[system->get_id()] = system;
    
    return system;
}

template <class T>
T* SystemManager::getSystem(SystemId id)
{
    std::map<SystemId, EntitySystem*>::iterator sysi = systems_.find(id);
    if( sysi != systems_.end() )
    {
        return dynamic_cast<T*>(*sysi);
    }
    else
    {
        return NULL;
    }
}

std::map<SystemId, EntitySystem*> SystemManager::getSystems()
{
    return systems_; // makes a copy
}

void SystemManager::initializeAll()
{
    std::pair<EntityId, EntitySystem*> p;
    BOOST_FOREACH(p, systems_)
    {
        p.second->initialize();
    }
}
