#ifndef ARTEMIS_TAG_MANAGER_H
#define ARTEMIS_TAG_MANAGER_H

#include <map>

#include "world.hpp"
#include "util/typedefs.hpp"

class TagManager
{
    friend class World;
    private:
        World* world_;
        std::map<TagId, Entity*> entity_by_tag_;
        std::map<EntityId, TagId> tag_by_entity_;

    protected:
        void remove(Entity* e);
        
    public:
        TagManager(World* world);
        void set(TagId tag, Entity* e);
        void unset(TagId tag);
        bool isSet(TagId tag);
        Entity* getEntity(TagId tag);
};
#endif
