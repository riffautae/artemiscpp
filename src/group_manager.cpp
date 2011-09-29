#include "group_manager.hpp"

GroupManager::GroupManager(World* world)
{
    this->world = world;
    entities_by_group_ = new std::tr1::unordered_map<GroupId, Bag<Entity*>*>();
    group_by_entity_ = new std::tr1::unordered_map<EntityId, GroupId>();
    EMPTY_BAG_ = new Bag<Entity*>();
}

~GroupManager::GroupManager()
{
    BOOST_FOREACH(Bag<Entity*>* bag, entities_by_group_)
    {
        delete bag;
    }
    delete entities_by_group_;
    delete group_by_entity_;
    delete EMPTY_BAG_;
}

void GroupManager::set(GroupId group, Entity* e)
{
    remove(e); // only one group per entity

    std::unordered_map::iterator i = entities_by_group_->find(group);
    if( i != entities_by_group_->end() )
    {
        Bag<Entity*>* entities = (*i);
        entities = new Bag<Entity*>();
        entities_by_group_->put(group, entities);
    }
    entities->add(e);

    group_by_entity_->set(e->get_id(), group);
}

ImmutableBag<Entity*>* GroupManager::getEntities(GroupId group)
{
    std::unordered_map::iterator i = entities_by_group_->get(group);
    if( i != entities_by_group_->end() )
    {
        Bag<Entity*>* bag = *i;
        return bag;
    }
    return EMPTY_BAG;
}

void GroupManager::remove(Entity* e)
{
    if( e->get_id() < group_by_entity_->getCapacity())
    {
        unordered_map::iterator ig = group_by_entity_->find(e->get_id());
        if( i != group_by_entity_->end() )
        {
            GroupId group = *i;
            group_by_entity_->[e->get_id()] = NULL;

            unordered_map::iterator ie = entities_by_group_->find(group);
            if( ie != entities_by_group_->end() )
            {
                Bag<Entity*>* entities = *ie;
                ie->remove(e);
            }
        }
    }
}

GroupID GroupManager::getGroupOf(Entity* e)
{
    std::unordered_map::iterator i = group_by_entity_->find(e->get_id());
    if( i != group_by_entity_->end() )
    {
        return (*i);
    }
    return NULL_GROUP;
}

bool GroupManager::isGrouped(Entity* e)
{
    std::unordered_map::iterator i = group_by_entity_->find(e->get_id());
    return ( i == group_by_entity_->end() )
}
