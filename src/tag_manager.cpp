#include "tag_manager.hpp"

TagManager::TagManager(World* world)
{
    world_ = world;
    entity_by_tag_ = std::tr1::unordered_map<std::string, Entity*>();
}

void TagManager::set(TagId tag, Entity* e)
{
    entity_by_tag_[tag] = e;
}

void TagManager::unset(TagId tag)
{
    entity_by_tag_.erase(tag);
}

bool TagManager::isSet(TagId tag)
{
    return entity_by_tag_.find(tag) != entity_by_tag_.end();
}

void TagManager::remove(Entity* e)
{
    bool found = false;
    std::string etag;
    BOOST_FOREACH(std::string tag, entity_by_tag_)
    {
        Entity* mye = entity_by_tag_[tag];
        if( mye == e )
        {
            etag = tag;
            found = true;
        }
    }
    if( found )
    {
        entity_by_tag_.erase(etag);
    }
}
