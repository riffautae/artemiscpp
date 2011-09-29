#include "entity_system.hpp"

#include "boost/foreach.hpp"

EntitySystem::EntitySystem(ComponentIds compIds[])
{
    actives_ = Bag<Entity*>();

    BOOST_FOREACH( ComponentId id, compIds )
    {
        comp_bits_ |= id;
    }
}

void EntitySystem::setSystemBit(SystemBit bit)
{
    this->system_bit_ = bit;
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
    bool contains = (system_bit_ & e->get_system_bits()) == system_id_;
    bool interest = (comp_bits_ & e->get_comp_bits()) == comp_bits_;

    if (interest && !contains && comp_bits_ > 0)
    {
        actives_->add(e);
        e.addSystemBit(system_id_);
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
    e->removeSystemBit(system_bit_);
    removed(e);
}

void EntitySystem::(World* world)
{
    this->world = world;
}

