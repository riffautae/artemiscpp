#ifndef ARTEMIS_WORLD_H
#define ARTEMIS_WORLD_H

#include <set>
#include <map>
#include "boost/shared_ptr.hpp"

#include "artemis/pointers/entity.hpp"
#include "artemis/pointers/manager.hpp"

#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    class Entity;
    class EntityManager;
    class GroupManager;
    class Manager;
    class SystemManager;
    class TagManager;
    class World;

    /**
     * The primary instance for the framework.
     * It contains all the managers.
     *
     * You must use this to create, delete and retrieve entities.
     *
     * It is also important to set the delta each game loop iteration.
     */
    class World
    {
        private:
            boost::shared_ptr<EntityManager> entity_manager_;
            boost::shared_ptr<GroupManager> group_manager_;
            boost::shared_ptr<SystemManager> system_manager_;
            boost::shared_ptr<TagManager> tag_manager_;

            long delta_;
            std::set<EntityPtr> refreshed_;
            std::set<EntityPtr> deleted_;

            typedef std::map<ManagerId, ManagerPtr> ManagerMap;
            ManagerMap managers_;

        public:
            World();
            ~World();
            boost::shared_ptr<EntityManager> get_entity_manager();
            boost::shared_ptr<GroupManager> get_group_manager();
            boost::shared_ptr<SystemManager> get_system_manager();
            boost::shared_ptr<TagManager> get_tag_manager();

            /**
             * Allows for setting a custom manager.
             * @param manager to be added
             */
            void setManager(boost::shared_ptr<Manager> manager);

            /**
             * Returns a manager of the specified type
             *
             * @param <T>
             * @param id of the manager to return.
             */
            ManagerPtr getManager(ManagerId id);

            /**
             * Time since last game loop
             * @return delta in milliseconds.
             */
            int get_delta();

            /**
             * Specify the delta for the game here.
             *
             * @param delta time since last game loop.
             */
            void set_delta(int delta);

            /**
             * Delete the provided entity from the world.
             * @param e entity
             */
            void deleteEntity(EntityPtr e);

            /**
             * Refresh all changes to components for this entity.
             * After adding or removing components, you must call this method.
             * It will update all relevant systems.
             * It is typical to call this after adding components to a newly
             * created entity.
             *
             * @param e entity
             */
            void refreshEntity(EntityPtr e);

            /**
             * Create and return a new or reused entity instance.
             * @return entity
             */
            EntityPtr createEntity();

            /**
             * Get an entity having the specified id.
             * @param id
             * @return entity
             */
            EntityPtr getEntity(EntityId id);

            /**
             * Let framework take care of internal business.
             */
            void loopStart();
    };
};
#endif
