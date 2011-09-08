#include "entity_system.hpp"

#include "boost/foreach.hpp"

EntitySystem::EntitySystem(ComponentType& ... types)
{
    actives = new Bag<Entity*>();

    BOOST_FOREACH( ComponentType* type, types )
    {
        type_flags_ |= ct->getBit();
    }
}

void EntitySystem::setSystemBit(SystemBits bit)
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
    bool contains = (system_bit_ & e->getSystemBits()) == system_bit_;
    bool interest = (type_flags_ & e->getTypeBits()) == type_bits_;

    if (interest && !contains && typeFlags > 0)
    {
        actives_->add(e);
        e.addSystemBit(system_bit_);
        added(e);
    }
    else if (! interest && contaings && type_flags_ > 0)
    {
        remove(e);
    }
}

void EntitySystem::remove(Entity* e)
{
    actives.remove(e);
    e->removeSystemBit(system_bit_);
    removed(e);
}

void EntitySystem::(World* world)
{
    this->world = world;
}

static (ComponentType*)[] EntitySystem::getMergedTypes(const ComponentType* requiredType, (ComponentType*)[] otherTypes)
{
    (ComponentType*)[] types = (ComponentType*)[1+otherTypes.length];
    types[0] = requiredType;
    BOOST_FOREACH(ComponentType* ct, otherTypes)
    {
        types[i+1] = ct;
    }
    return types;
}
