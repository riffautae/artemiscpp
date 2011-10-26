#include "boost/foreach.hpp"

#include "artemis/component.hpp"
#include "artemis/entity.hpp"
#include "artemis/entity_manager.hpp"
#include "artemis/world.hpp"
#include "artemis/pointers/entity.hpp"

using namespace Artemis;
EntityManager::EntityManager(World& world):
    world_(world)
{
    active_entities_ = std::map<EntityId, EntityPtr>();
    removed_and_available_ = std::list<EntityPtr>();

    components_by_ent_ = MapComp();
}

EntityManager::~EntityManager()
{
    //TODO: delete all entities and so on
    /*delete active_entities_;
    delete removed_and_available_;
    delete components_by_type_;
    delete entity_components_; */
}

bool EntityManager::isActive(EntityId entity_id)
{
    return active_entities_.find(entity_id) != active_entities_.end();
}

long EntityManager::get_entity_count()
{
    return count_;
}

long EntityManager::get_total_created()
{
    return total_created_;
}

long EntityManager::get_total_removed()
{
    return total_removed_;
}

EntityPtr EntityManager::create()
{
    EntityPtr e;
    if( removed_and_available_.empty() )
    {
        e = EntityPtr(new Entity(world_, next_available_id_++));
    }
    else
    {
        e = removed_and_available_.back();
        removed_and_available_.pop_back();
        e->reset();
    }
    e->set_unique_id(unique_entity_id_++);
    active_entities_[e->get_id()] = e;
    components_by_ent_[e->get_id()] = MapCompInner();
    count_++;
    total_created_++;
    return e;
}

void EntityManager::remove(EntityPtr e)
{
    active_entities_.erase(e->get_id());

    e->set_comp_bits(0);

    refresh(e);

    // all the compid->component mappings
    MapComp::iterator enti = components_by_ent_.find(e->get_id());
    if( enti != components_by_ent_.end() )
    {
        // the compid->component mapping for a specific entity
        MapCompInner& components = enti->second;

        // remove all the component from the entity
        e->set_comp_bits(0);

        // since they are shared pointers, this should delete them all
        components.clear();

        // remove the inner map
        components_by_ent_.erase(e->get_id());
    }

    count_--;
    total_removed_--;

    removed_and_available_.push_back(e);
}

void EntityManager::refresh(EntityPtr e)
{
    SystemManager& sm = world_.get_system_manager();
    std::map<SystemId, boost::shared_ptr<EntitySystem> > systems =
        sm.getSystems();

    typedef std::map<SystemId, boost::shared_ptr<EntitySystem> >::value_type 
        ESVT;
    BOOST_FOREACH(ESVT esvt, systems)
    {
        boost::shared_ptr<EntitySystem> es = esvt.second;
        es->change(e);
    }
}

void EntityManager::addComponent(EntityPtr e, ComponentPtr component)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());

    // make sure we have this entity
    if( enti != components_by_ent_.end() )
    {
        MapCompInner& components = enti->second;
        ComponentId comp_id = component->getComponentId();
        MapCompInner::iterator inn = components.find(comp_id);
        // component is not already in the entity
        if( inn == components.end() )
        {
            components[comp_id] = component;
            e->addCompId(comp_id);
        }
    }
}

ComponentPtr EntityManager::getComponent(EntityPtr e, ComponentId comp_id)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());

    // we have the entity
    if( enti != components_by_ent_.end() )
    {
        MapCompInner& inn = enti->second;
        MapCompInner::iterator compi = inn.find(comp_id);
        // we have the component in this entity
        if( compi != inn.end() )
        {
            return compi->second;
        }
    }
    return ComponentPtr(); //null
}

void EntityManager::removeComponent(EntityPtr e, ComponentId comp_id)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());
    if( enti != components_by_ent_.end() )
    {
        MapCompInner& inn = enti->second;
        MapCompInner::iterator compi = inn.find(comp_id);
        if( compi != inn.end() )
        {
            e->removeCompId(comp_id);
            inn.erase(compi);
        }
    }
}

EntityPtr EntityManager::getEntity(EntityId entity_id) 
{
    return active_entities_.find(entity_id)->second;
}

std::map<ComponentId, ComponentPtr> EntityManager::getComponents(EntityPtr e)
{
    MapComp::iterator compi = components_by_ent_.find(e->get_id());

    // check for ent
    if( compi != components_by_ent_.end() )
    {
        // return a copy of its component map
        return compi->second;
    }
}
        
