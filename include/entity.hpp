#ifndef ARTEMIS_ENTITY_H
#define ARTEMIS_ENTITY_H

#include <string>
#include "boost/shared_ptr.hpp"

#include "entity_manager.hpp"
#include "entity_system.hpp"
#include "util/typedefs.hpp"


namespace Artemis
{
    class Component;
    class World;

    /**
     * The entity class. Cannot be instantiated outside the framework, you must
     * create new entities using World
     */
    class Entity
    {
        friend class EntityManager;
        friend class EntitySystem;
        // getters/setters
        public:
            /**
             * The internal id for this entity within the framework. No other
             * entity will have the same ID, but ID's are reused so another 
             * entity may aquire this ID if the previous entity was deleted.
             */
            EntityId get_id();

            /**
             * Gets the unique ID of this entity. Because entity instances are
             * reused internally use this to differentiate instances.
             */
            EntityId get_unique_id();

            /**
             * Checks if the enity has been deleted.
             * @return true if its active.
             */
            bool is_active();
        protected:
            void set_unique_id(EntityId unique_id);
            EntityId get_system_bits();
            void set_system_bits(SystemBits system_bits);
            ComponentBits get_comp_bits();
            void set_comp_bits(ComponentBits comp_bits);

        // other
        public:
            std::string toString();

            void reset();
        protected:
            Entity(World& world, EntityId id);
            void addSystemId(SystemId Id);
            void removeSystemId(SystemId Id);

            /**
             * Add a component to this entity.
             * @param id of the component to add.
             */
            void addCompId(ComponentId id);

            /**
             * Removes a component from this entity.
             * @param id of the component to remove.
             */
            void removeCompId(ComponentId id);

        private:
            EntityId id_;
            EntityId unique_id_;
            ComponentBits comp_bits_;
            SystemBits system_bits_;

            World& world_;
            boost::shared_ptr<EntityManager> entity_manager_;
    };
};
#endif
