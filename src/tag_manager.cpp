#include "entity.hpp"
#include "tag_manager.hpp"

TagManager::TagManager(World* world)
{
    world_ = world;
    entity_by_tag_ = std::map<TagId, Entity*>();
    tag_by_entity_ = std::map<EntityId, TagId>();
}

void TagManager::set(TagId tag, Entity* e)
{
    entity_by_tag_[tag] = e;
    tag_by_entity_[e->get_id()] = tag;
}

void TagManager::unset(TagId tag)
{
    tag_by_entity_.erase(getEntity(tag)->get_id());
    entity_by_tag_.erase(tag);
}

bool TagManager::isSet(TagId tag)
{
    return entity_by_tag_.find(tag) != entity_by_tag_.end();
}

void TagManager::remove(Entity* e)
{
    std::map<EntityId, TagId>::iterator enti =
        tag_by_entity_.find(e->get_id());

    if( enti != tag_by_entity_.end() )
    {
        tag_by_entity_.erase(e->get_id());
        entity_by_tag_.erase((*enti).second);
    }
}
