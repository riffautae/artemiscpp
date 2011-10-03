#include "entity_manager.hpp"

#include "component.hpp"
#include "entity.hpp"
#include "world.hpp"

EntityManager::EntityManager(World* world)
{
    world_ = world;

    active_entities_ = std::map<EntityId, Entity*>();
    removed_and_available_ = std::list<Entity*>();

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

Entity* EntityManager::create()
{
    Entity* e;
    if( !removed_and_available_.empty() )
    {
        e = new Entity(world_, next_available_id_++);
    }
    else
    {
        e = removed_and_available_.back();
        removed_and_available_.pop_back();
        e->reset();
    }
    e->set_unique_id(unique_entity_id_++);
    active_entities_[e->get_id()] = e;
    count_++;
    total_created_++;
    return e;
}

void EntityManager::addComponent(Entity* e, Component* component)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());

    // make sure we have this entity
    if( enti != components_by_ent_.end() )
    {
        MapCompInner* components;
        ComponentId comp_id = component->componentId;
        components = enti->second;
        MapCompInner::iterator inn = components->find(comp_id);
        // component is not already in the entity
        if( inn == components->end() )
        {
            (*components)[comp_id] = component;
            e->addCompId(comp_id);
        }
    }
}

Component* EntityManager::getComponent(Entity* e, ComponentId comp_id)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());
    MapComp* components;

    // we have the entity
    if( enti != components_by_ent_.end() )
    {
        MapCompInner* inn = enti->second;
        MapCompInner::iterator compi = inn->find(comp_id);
        // we have the component in this entity
        if( compi != inn->end() )
        {
            return compi->second;
        }
    }
    return NULL;
}

void EntityManager::removeComponent(Entity* e, ComponentId comp_id)
{
    MapComp::iterator enti = components_by_ent_.find(e->get_id());
    if( enti != components_by_ent_.end() )
    {
        MapCompInner* inn = enti->second;
        MapCompInner::iterator compi = inn->find(comp_id);
        if( compi != inn->end() )
        {
            inn->erase(compi);
            e->removeCompId(comp_id);
        }
    }
}

Entity* EntityManager::getEntity(EntityId entity_id) 
{
    return active_entities_.find(entity_id)->second;
}

std::map<ComponentId, Component*> EntityManager::getComponents(Entity* e)
{
    MapCompInner* entity_components;
    MapCompInner* ret;
    MapComp::iterator compi = components_by_ent_.find(e->get_id());

    // check for ent
    if( compi != components_by_ent_.end() )
    {
        // return a copy of its component map
        entity_components = compi->second;
        return (*entity_components);
    }
}
        
