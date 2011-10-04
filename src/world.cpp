#include "boost/foreach.hpp"

#include "entity.hpp"
#include "entity_manager.hpp"
#include "group_manager.hpp"
#include "manager.hpp"
#include "system_manager.hpp"
#include "tag_manager.hpp"
#include "world.hpp"

World::World()
{
    entity_manager_ = new EntityManager(this);
    group_manager_ = new GroupManager(this);
    system_manager_ = new SystemManager(this);
    tag_manager_ = new TagManager(this);

    refreshed_ = std::set<Entity*>();
    deleted_ = std::set<Entity*>();

    managers_ = std::map<ManagerId, Manager*>();
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
    managers_[manager->get_id()] = manager;
}

template<class T>
T* World::getManager(ManagerId manager)
{
    std::map<ManagerId, Manager*>::iterator i =
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
    if( deleted_.find(e) != deleted_.end() )
    {
        deleted_.insert(e);
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
    if( !refreshed_.empty() )
    {
        BOOST_FOREACH(Entity* e, refreshed_)
        {
            entity_manager_->refresh(e);
        }
        refreshed_.clear();
    }
    
    if( !deleted_.empty() )
    {
        BOOST_FOREACH(Entity* e, deleted_)
        {
            entity_manager_->remove(e);
            group_manager_->remove(e);
            tag_manager_->remove(e);
            delete e;
        }
        deleted_.clear();
    }
}
