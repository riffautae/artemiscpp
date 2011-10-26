#include "boost/foreach.hpp"
#include "boost/shared_ptr.hpp"

#include "artemis/world.hpp"

#include "artemis/entity.hpp"
#include "artemis/entity_manager.hpp"
#include "artemis/group_manager.hpp"
#include "artemis/manager.hpp"
#include "artemis/system_manager.hpp"
#include "artemis/tag_manager.hpp"

#include "artemis/pointers/entity.hpp"

using namespace Artemis;

World::World()
    :
        entity_manager_(EntityManager(*this)),
        system_manager_(SystemManager(*this))
{
    group_manager_ = GroupManager();
    tag_manager_ = TagManager();

    refreshed_ = std::set<EntityPtr>();
    deleted_ = std::set<EntityPtr>();

    managers_ = ManagerMap();
}

World::~World()
{
}

EntityManager& World::get_entity_manager()
{
    return entity_manager_;
}

GroupManager& World::get_group_manager()
{
    return group_manager_;
}

SystemManager& World::get_system_manager()
{
    return system_manager_;
}

TagManager& World::get_tag_manager()
{
    return tag_manager_;
}

void World::setManager(boost::shared_ptr<Manager> manager)
{
    managers_[manager->get_id()] = manager;
}

ManagerPtr World::getManager(ManagerId manager)
{
    ManagerMap::iterator i =
        managers_.find(manager);
    if( i != managers_.end() )
    {
        return i->second;
    }
    else
    {
        return ManagerPtr(); //null ptr
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

void World::deleteEntity(EntityPtr e)
{
    if( deleted_.find(e) != deleted_.end() )
    {
        deleted_.insert(e);
    }
}

void World::refreshEntity(EntityPtr e)
{
    refreshed_.insert(e);
}

EntityPtr World::createEntity()
{
    return entity_manager_.create();
}

EntityPtr World::getEntity(EntityId entityId)
{
    return entity_manager_.getEntity(entityId);
}

void World::loopStart()
{
    if( !refreshed_.empty() )
    {
        BOOST_FOREACH(EntityPtr e, refreshed_)
        {
            entity_manager_.refresh(e);
        }
        refreshed_.clear();
    }
    
    if( !deleted_.empty() )
    {
        BOOST_FOREACH(EntityPtr e, deleted_)
        {
            entity_manager_.remove(e);
            group_manager_.remove(e);
            tag_manager_.remove(e);

            //TODO: this stuff
            /*BOOST_FOREACH(ManagerMap::value_type mans,

                   managers_)
            {
                mans.second.remove(e);
            }*/
        }
        deleted_.clear();
    }
}
