#include "system_manager.hpp"

SystemManager::SystemManager(World* world)
{
    world_ = world;
    systems_ = unordered_map<EntityId, EntitySystem*>();
    bagged_ = Bag<EntitySystem*>();
}

EntitySystem* SystemManager::setSystem(EntitySystem* system)
{
    system->setWorld(world_);

    systems[system->getId] = system;
    
    if( !bagged.contains(system) )
    {
        bagged.add(system);
    }

    system->setSystemBit(SystemBitManager::getBitFor(system->getId));

    return system;
}

template <EntitySystem* T>
T SystemManager::getSystem(EntityId id)
{
    unordered_map::iterator<T> i = systems.find(id);
    if( i != systems.end() )
    {
        return dynamic_cast<T>(systems[id]);
    }
    else
    {
        return NULL;
    }
}

Bag<EntitySystem*> SystemManager::getSystems()
{
    return bagged;
}

void SystemManager::initializeAll()
{
    BOOST_FOREACH(int i, bagged)
    {
        i.initialize();
    }
}
