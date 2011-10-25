#ifndef artemis_group_manager_H
#define artemis_group_manager_H

#include <tr1/unordered_map>

#include "artemis/entity.hpp"

#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    /**
     * If you need to group your entities together, e.g. tanks going into
     * "units" group or explosions into "effects",
     * then use this manager, You must retrieve it using world instance.
     *
     * An entity can only belong to one group at a time.
     */
    class GroupManager
    {
        public:
            GroupManager();

            /**
             * Set the group of the entity
             *
             * @param group to set the entity into.
             * @param e entity to set into the group
             */
            void set(GroupId group, EntityPtr e);

            /**
             * Get all entities that belong to the provided group
             * @param group name of the group.
             * @return map of the entities in the group
             */
            std::map<EntityId, EntityWkPtr> getEntities(GroupId group);

            /**
             * Removes the entity from whatever group it is assigned to.
             * @param e the entity
             */
            void remove(EntityPtr e);

            /**
             * @param e entity
             * @return the Id of the group or NULL_GROUP
             */
            GroupId getGroupOf(EntityPtr e);

            /**
             * Checks if the entity belongs to any group.
             * @param e the entity to check
             * @return true if it is any group, false if none.
             */
            bool isGrouped(EntityPtr e);

            static const GroupId NULL_GROUP = 0;

        private:
            typedef std::map<EntityId, EntityWkPtr> MapEntInner; 
            typedef std::map<GroupId, MapEntInner> MapEnt;
            MapEnt entities_by_group_;
            typedef std::map<EntityId, GroupId> MapGroup;
            MapGroup group_by_entity_;
    };
};
#endif
