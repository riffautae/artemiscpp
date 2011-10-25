#include "boost/foreach.hpp"

#include "artemis/system_manager.hpp"
#include "artemis/entity_system.hpp"
#include "artemis/world.hpp"

using namespace Artemis;
SystemManager::SystemManager(World& world) :
    world_(world)
{
    systems_ = std::map<EntityId, boost::shared_ptr<EntitySystem> >();
}

SystemId SystemManager::addSystem(boost::shared_ptr<EntitySystem> system)
{
    systems_[system->get_id()] = system;
    
    return system->get_id();
}

boost::shared_ptr<EntitySystem> SystemManager::getSystem(SystemId id)
{
    std::map<SystemId, boost::shared_ptr<EntitySystem> >::iterator sysi = systems_.find(id);
    if( sysi != systems_.end() )
    {
        return sysi->second;
    }
    else
    {
        return boost::shared_ptr<EntitySystem>();
    }
}

std::map<SystemId, boost::shared_ptr<EntitySystem> > SystemManager::getSystems()
{
    return systems_; // makes a copy
}

void SystemManager::initializeAll()
{
    std::pair<EntityId, boost::shared_ptr<EntitySystem> > p;
    BOOST_FOREACH(p, systems_)
    {
        p.second->initialize();
    }
}
