#include "entity_manager.hpp"

#include "component.hpp"
#include "entity.hpp"
#include "world.hpp"

EntityManager::EntityManager(World* world)
{
    world_ = world;

    active_entities_ = std::map<EntityId, Entity*>();
    removed_and_available_ = std::list<Entity*>();

    components_by_id_ = MapCompIdMap();
}

EntityManager::~EntityManager()
{
    /*delete active_entities_;
    delete removed_and_available_;
    delete components_by_type_;
    delete entity_components_; */
}

bool EntityManager::isActive(EntityId entity_id)
{
    return active_entities_.find(entity_id) != active_entities_.end();
}

int EntityManager::get_entity_count()
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

void EntityManager::addComponent(Entity* e, ComponentId comp_id)
{
    MapCompIdMap::iterator compi = components_by_id_.find(comp_id);
    MapEntIdComp* components;

    if( compi == components_by_id_.end() )
    {
        components = new MapEntIdComp();
        components_by_id_[comp_id] = components;
    }

    components[e->get_id()] = component;

    e->addCompId(comp_id);
}

Component* EntityManager::getComponent(Entity* e, ComponentId comp_id)
{
    MapCompIdMap::iterator compi = components_by_id_.find(comp_id);
    MapEntIdComp* components;

    if( compi != components_by_id_.end() )
    {
        return compi;
    }
    return NULL;
}

Entity* EntityManager::getEntity(EntityId entity_id) 
{
    return active_entities_.find(entity_id);
}

int EntityManager::getEntityCount()
{
    return count_;
}

long EntityManager::getTotalCreated()
{
    return total_created_;
}

long EntityManager::getTotalRemoved()
{
   return total_removed_;
}

std::list<Component*> EntityManager::getComponents(Entity* e)
{
    std::list<Component*> entity_components();
    MapCompIdMap::iterator component;
    BOOST_FOREACH(MapCompIdMap components, components_by_id_)
    {
        component = components.find(e->get_id());
        if( component != components.end() )
        {
            entity_components_.push_back(component);
        }
    }
    return entity_components_;
}
        
