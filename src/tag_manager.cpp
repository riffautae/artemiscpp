#include "artemis/entity.hpp"
#include "artemis/tag_manager.hpp"

using namespace Artemis;
TagManager::TagManager()
{
    entity_by_tag_ = std::map<TagId, EntityPtr>();
    tag_by_entity_ = std::map<EntityId, TagId>();
}

void TagManager::set(TagId tag, EntityPtr e)
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

void TagManager::remove(EntityPtr e)
{
    std::map<EntityId, TagId>::iterator enti =
        tag_by_entity_.find(e->get_id());

    if( enti != tag_by_entity_.end() )
    {
        tag_by_entity_.erase(e->get_id());
        entity_by_tag_.erase((*enti).second);
    }
}
