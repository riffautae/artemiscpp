#ifndef ARTEMIS_WORLD_H
#define ARTEMIS_WORLD_H

#include <set>
#include <map>

#include "util/typedefs.hpp"

template<class E> class Bag;
class Entity;
class EntityManager;
class GroupManager;
class Manager;
class SystemManager;
class TagManager;

class World
{
    private:
        EntityManager* entity_manager_;
        GroupManager* group_manager_;
        SystemManager* system_manager_;
        TagManager* tag_manager_;

        long delta_;
        std::set<Entity*> refreshed_;
        std::set<Entity*> deleted_;

        std::map<ManagerId, Manager*> managers_;

    public:
        World();
        ~World();
        EntityManager* get_entity_manager();
        GroupManager* get_group_manager();
        SystemManager* get_system_manager();
        TagManager* get_tag_manager();

        void setManager(Manager* manager);
        template<class T> T* getManager(ManagerId id);
        int get_delta();
        void set_delta(int delta);
        void deleteEntity(Entity* e);
        void refreshEntity(Entity* e);
        Entity* createEntity();
        Entity* getEntity(EntityId id);

        void loopStart();
};

#endif
