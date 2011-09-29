#ifndef artemis_group_manager_H
#define artemis_group_manager_H

#include <tr1/unordered_map>

#include "entity.hpp"
#include "world.hpp"

#include "util/bag.hpp"
#include "util/immutable_bag.hpp"
#include "util/typedefs.hpp"

class World;

class GroupManager
{
    public:
        GroupManager(World* world);
        ~GroupManager();
        void set(GroupId group, Entity* e);
        ImmutableBag<Entity*> getEntities(GroupId group);
        void remove(Entity* e);
        GroupId getGroupOf(Entity* e);
        bool isGrouped(Entity* e);

        static const GroupId NULL_GROUP = 0;

    private:
        World* world_;
        Bag<Entity*>* EMPTY_BAG_;
        std::tr1::unordered_map<GroupId, Bag<Entity*>*>* entities_by_group_;
        std::tr1::unordered_map<EntityId, GroupId>* group_by_entity_;
};

#endif
