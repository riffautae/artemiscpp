#ifndef ARTEMIS_TAG_MANAGER_H
#define ARTEMIS_TAG_MANAGER_H

#include <map>

#include "artemis/pointers/entity.hpp"
#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    /**
     * If you need to tag any entity, use this. A typical usage would be to tag
     * entities such as "PLAYER". After creating an entity call register().
     */
    class TagManager
    {
        private:
            std::map<TagId, EntityPtr> entity_by_tag_;
            std::map<EntityId, TagId> tag_by_entity_;

        public:
            void remove(EntityPtr e);
            TagManager();
            void set(TagId tag, EntityPtr e);
            void unset(TagId tag);
            bool isSet(TagId tag);
            EntityPtr getEntity(TagId tag);
    };
};
#endif
