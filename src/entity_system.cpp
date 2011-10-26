#include "boost/foreach.hpp"

#include "artemis/entity.hpp"
#include "artemis/entity_system.hpp"

using namespace Artemis;
EntitySystem::EntitySystem(std::list<ComponentId> compIds, World& world) :
    world_(world)
{
    actives_ = std::list<EntityPtr>();

    BOOST_FOREACH( ComponentId id, compIds )
    {
        comp_bits_ |= id;
    }
}

void EntitySystem::set_id(SystemId id)
{
    this->system_id_ = id;
}

SystemId EntitySystem::get_id()
{
    return system_id_;
}

void EntitySystem::process()
{
    if( checkProcessing() )
    {
        begin();
        processEntities(actives_);
        end();
    }
}

long EntitySystem::numEntities()
{
    return actives_.size();
}

void EntitySystem::change(EntityPtr e)
{
    bool contains = (system_id_ & e->get_system_bits()) == system_id_;
    bool interest = (comp_bits_ & e->get_comp_bits()) == comp_bits_;

    if (interest && !contains && comp_bits_ > 0)
    {
        actives_.push_back(e);
        e->addSystemId(system_id_);
        added(e);
    }
    else if (! interest && contains && comp_bits_ > 0)
    {
        remove(e);
    }
}

void EntitySystem::remove(EntityPtr e)
{
    actives_.remove(e);
    e->removeSystemId(system_id_);
    removed(e);
}

bool EntitySystem::checkProcessing()
{
    return false;
}

void EntitySystem::begin()
{
}

void EntitySystem::end()
{
}

void EntitySystem::initialize()
{
}

void EntitySystem::added(EntityPtr e)
{
}

void EntitySystem::removed(EntityPtr e)
{
}
