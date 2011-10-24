#include "boost/foreach.hpp"

#include "group_manager.hpp"

using namespace Artemis;
GroupManager::GroupManager()
{
    entities_by_group_ = MapEnt();
    group_by_entity_ = MapGroup();
}

void GroupManager::set(GroupId group, EntityPtr e)
{
    remove(e); // only one group per entity

    MapEnt::iterator i = entities_by_group_.find(group);
    MapEntInner entities;
    // dont have this group?
    if( i == entities_by_group_.end() )
    {
        entities = MapEntInner();
        entities_by_group_[group] = entities;
    }
    else
    {
        entities = i->second;
    }
    entities[e->get_id()] = EntityWkPtr(e);

    group_by_entity_[e->get_id()] = group;
}

std::map<EntityId, EntityWkPtr> GroupManager::getEntities(GroupId group)
{
    MapEnt::iterator i = entities_by_group_.find(group);
    if( i != entities_by_group_.end() )
    {
        return i->second;
    }
    return MapEntInner();
}

void GroupManager::remove(EntityPtr e)
{
    MapGroup::iterator groupi = group_by_entity_.find(e->get_id());
    if( groupi != group_by_entity_.end() )
    {
        GroupId group = groupi->second;
        group_by_entity_.erase(e->get_id());

        MapEnt::iterator ie = entities_by_group_.find(group);
        if( ie != entities_by_group_.end() )
        {
            MapEntInner& entities = ie->second;
            entities.erase(e->get_id());
        }
    }
}

GroupId GroupManager::getGroupOf(EntityPtr e)
{
    MapGroup::iterator i = group_by_entity_.find(e->get_id());
    if( i != group_by_entity_.end() )
    {
        return i->second;
    }
    return NULL_GROUP;
}

bool GroupManager::isGrouped(EntityPtr e)
{
    MapGroup::iterator i = group_by_entity_.find(e->get_id());
    return ( i == group_by_entity_.end() );
}
