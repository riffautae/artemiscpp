#ifndef ARTEMIS_TAG_MANAGER_H
#define ARTEMIS_TAG_MANAGER_H

#include <tr1/unordered_map>

#include "world.hpp"

class TagManager
{
    private:
        World* world_;
        std::tr1::unordered_map<TagId, Entity*> entity_by_tag_;

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
