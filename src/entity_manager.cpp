#include "entity_manager.hpp"

EntityManager::EntityManager(World* world)
{
    world_ = world;

    active_entities_ = new Bag<Entity*>();
    removed_and_available_ = new Bag<Entity*>();

    components_by_type_ = new Bag<Bag<Component*>*>();

    entity_components_ = new Bag<Component*>();
}

EntityManager::~EntityManager()
{
    delete active_entities_;
    delete removed_and_available_;
    delete components_by_type_;
    delete entity_components_;
}

bool EntityManager::is_active(EntityID entity_id)
{
    return active_entities_.get(entity_id) != NULL;
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
    Entity* e = removed_and_available.removeLast();
    if( e == NULL )
    {
        e = new Entity(world, next_available_id++);
    }
    else
    {
        e.reset();
    }
    e.set_unique_id(unique_entity_id_++);
    active_entities_.set(e.get_id(), e);
    count_++;
    total_created_++;
    return e;
}

void EntityManager::addComponent(Entity* e, ComponentType* type)
{
    if( type.get_id() >= components_by_type_->getCapacity() )
    {
        components_by_type_->set(type->get_id(), NULL);
    }

    Bag<Component*>* components = components_by_type_->get(type->get_id());
    if( components == NULL )
    {
        components = new Bag<Components*>();
        components_by_type_->set(type->get_id(), components);
    }

    components->set(e->get_id(), component);

    e.addTypeBit(type->get_bit());
}

void EntityManager::getComponent(Entity* e, ComponentType* type)
{
    Bag<Component*>* bag = components_by_type_->get(type->get_id());
    if( bag != NULL && e->get_id() < bag->get_capacity() )
    {
        return bag->get(e->getId());
    }
    return NULL;
}

Entity* EntityManager::getEntity(EntityID entity_id) 
{
    return active_entities_->get(entity_id);
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

ImmutableBag<Component*>* EntityManager::getComponents(const Entity* e)
{
    entity_components_->clear();
    for( int a = 0; components_by_type_.size() > a; a++ )
    {
        Bag<Component*>* components = components_by_type_.get(a);
        if( components != NULL && e.getId() < components->size() )
        {
            Component* component = components->get(e.getId());
            if( component != NULL)
            {
                entity_components_->add(component);
            }
        }
    }
    return entity_components_;
        
