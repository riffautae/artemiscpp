#include "boost/foreach.hpp"

#include "entity.hpp"
#include "entity_system.hpp"

EntitySystem::EntitySystem(std::list<ComponentId> compIds)
{
    actives_ = std::list<Entity*>();

    BOOST_FOREACH( ComponentId id, compIds )
    {
        comp_bits_ |= id;
    }
}

void EntitySystem::setSystemId(SystemId id)
{
    this->system_id_ = id;
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

void EntitySystem::change(Entity* e)
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

void EntitySystem::remove(Entity* e)
{
    actives_.remove(e);
    e->removeSystemId(system_id_);
    removed(e);
}

void EntitySystem::setWorld(World* world)
{
    world_ = world;
}

