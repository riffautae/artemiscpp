#include "world.hpp"

World::World()
{
    entity_manager_ = new EntityManager(this);
    group_manager_ = new GroupManager(this);
    system_manager_ = new SystemManager(this);
    tag_manager_ = new TagManager(this);

    refreshed = std::set<Entity*>();
    deleted = std::set<Entity*>();

    managers = std::tr1::unordered_map<ManagerId, Manager*>();
}

World::~World()
{
    delete entity_manager_;
    delete group_manager_;
    delete system_manager_;
    delete tag_manager_;
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
    std::tr1::unordered_map::iterator<ManagerId, Manager*> i =
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
    if( deleted.find(e) != deleted.end() )
    {
        deleted.insert(e);
    }
}

void World::refreshEntity(Entity* e)
{
    refreshed_.insert(e);
}

Entity* World::createEntity()
{
    return entity_manager_->create();
}

Entity* World::getEntity(EntityId entityId)
{
    return entity_manager_->getEntity(entityId);
}

void World::loopStart()
{
    if( !refreshed.empty() )
    {
        BOOST_FOREACH(Entity* e, refreshed_)
        {
            entity_manager_->refresh(e);
        }
        refreshed.clear()
    }
    
    if( !deleted.empty() )
    {
        BOOST_FOREACH(Entity* e, deleted_)
        {
            entity_manager_->remove(e);
            group_manager_->remove(e);
            tag_mananger_->remove(e);
            delete e;
        }
        deleted.clear();
    }
}
