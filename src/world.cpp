#include "world.hpp"

World::World()
{
    entity_manager_ = EntityManager(this);
    group_manager_ = GroupManager(this);
    system_manager_ = SystemManager(this);
    tag_manager_ = TagManager(this);

    refreshed = Bag<Entity*>();
    deleted = Bag<Entity*>();

    managers = hash_map<ManagerId, Manager*>();
}

EntityManager* World::get_entity_manager()
{
    return entity_manager_;
}

GroupManager* World::get_group_manager()
{
    return group_manager_;
}

SystemManager* World::get_system_manager()
{
    return system_manager_;
}

TagManager* World::get_tag_manager()
{
    return tag_manager_;
}

void World::setManager(Manager* manager)
{
    managers_[manager->getId] = manager;
}

template<Manager T>
T* World::getManager(ManagerId manager)
{
    hash_map::iterator<ManagerId, Manager*> i =
        managers_.find(manager);
    if( i != managers_.end() )
    {
        return dynamic_cast<T*>(i);
    }
    else
    {
        return NULL;
    }
}

int World::get_delta()
{
    return delta_;
}

void World::set_delta(int delta)
{
    delta_ = delta;
}

void World::deleteEntity(Entity* e)
{
    if( !deleted.contains(e) )
    {
        deleted.add(e);
    }
}

Entity* World::createEntity()
{
    return entity_manager_.create();
}

Entity* World::getEntity(EntityId entityId)
{
    return entity_manager_.getEntity(entityId);
}

void World::loopStart()
{
    if( !refreshed.isEmpty() )
    {
        BOOST_FOREACH(Entity* e, refreshed)
        {
            entity_manager_.refresh(e);
        }
        refreshed.clear()
    }
    
    if( !deleted.isEmpty() )
    {
        for(int i = 0; deleted.size() > i; i++)
        {
            Entity e* = deleted.get(i);
            entity_manager_.remove(e);
            group_manager_.remove(e);
            tag_mananger_.remove(e);
            delete e;
        }
        deleted.clear();
    }
}
