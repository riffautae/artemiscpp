#include "boost/foreach.hpp"

#include "group_manager.hpp"

GroupManager::GroupManager(World* world)
{
    world_ = world;
    entities_by_group_ = MapEnt();
    group_by_entity_ = MapGroup();
}

GroupManager::~GroupManager()
{
    std::pair<GroupId, MapEntInner*> p;
    BOOST_FOREACH(p, entities_by_group_)
    {
        delete p.second;
    }
    entities_by_group_.clear();
}

void GroupManager::set(GroupId group, Entity* e)
{
    remove(e); // only one group per entity

    MapEnt::iterator i = entities_by_group_.find(group);
    MapEntInner* entities;
    // dont have this group?
    if( i == entities_by_group_.end() )
    {
        entities = new MapEntInner();
        entities_by_group_[group] = entities;
    }
    else
    {
        entities = i->second;
    }
    (*entities)[e->get_id()] = e;

    group_by_entity_[e->get_id()] = group;
}

std::map<EntityId, Entity*> GroupManager::getEntities(GroupId group)
{
    MapEnt::iterator i = entities_by_group_.find(group);
    if( i != entities_by_group_.end() )
    {
        MapEntInner ret = (*((*i).second)); // D:
        return ret;
    }
    return MapEntInner();
}

void GroupManager::remove(Entity* e)
{
    MapGroup::iterator groupi = group_by_entity_.find(e->get_id());
    if( groupi != group_by_entity_.end() )
    {
        GroupId group = (*groupi).second;
        group_by_entity_.erase(e->get_id());

        MapEnt::iterator ie = entities_by_group_.find(group);
        if( ie != entities_by_group_.end() )
        {
            MapEntInner* entities = (*ie).second;
            entities->erase(e->get_id());
        }
    }
}

GroupId GroupManager::getGroupOf(Entity* e)
{
    MapGroup::iterator i = group_by_entity_.find(e->get_id());
    if( i != group_by_entity_.end() )
    {
        return (*i).second;
    }
    return NULL_GROUP;
}

bool GroupManager::isGrouped(Entity* e)
{
    MapGroup::iterator i = group_by_entity_.find(e->get_id());
    return ( i == group_by_entity_.end() );
}
