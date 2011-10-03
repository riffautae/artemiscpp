#ifndef artemis_group_manager_H
#define artemis_group_manager_H

#include <tr1/unordered_map>

#include "entity.hpp"
#include "world.hpp"

#include "util/typedefs.hpp"

class World;

class GroupManager
{
    public:
        GroupManager(World* world);
        ~GroupManager();
        void set(GroupId group, Entity* e);
        std::map<EntityId, Entity*> getEntities(GroupId group);
        void remove(Entity* e);
        GroupId getGroupOf(Entity* e);
        bool isGrouped(Entity* e);

        static const GroupId NULL_GROUP = 0;

    private:
        World* world_;
        typedef std::map<EntityId, Entity*> MapEntInner; 
        typedef std::map<GroupId, MapEntInner*> MapEnt;
        MapEnt entities_by_group_;
        typedef std::map<EntityId, GroupId> MapGroup;
        MapGroup group_by_entity_;
};

#endif
