#ifndef ARTEMIS_ENTITY_MANAGER_H
#define ARTEMIS_ENTITY_MANAGER_H

#include <map>
#include <list>

#include "artemis/pointers/entity.hpp"
#include "artemis/pointers/component.hpp"

#include "artemis/entity.hpp"
#include "artemis/world.hpp"
#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    class Component;
    class Entity;
    class World;

    class EntityManager
    {
        friend class World;
        public:
            EntityManager(World& world);
            ~EntityManager();

            /**
             * Check if this entity is active, or has been deleted, within the
             * framework.
             *
             * @param entity_id the entity
             * @return active or not
             */
            bool isActive(EntityId entity_id);

            /**
             * @return how many entities are currently active
             */
            long get_entity_count();

            /**
             * @return how many entities have been created since start.
             */
            long get_total_created();

            /**
             * @return how many entities have been removed since start.
             */
            long get_total_removed();

            EntityPtr create();
            void remove(EntityPtr e);
            void refresh(EntityPtr e);
            EntityPtr getEntity(EntityId entity_id);

            void addComponent(EntityPtr e, ComponentPtr component);
            ComponentPtr getComponent(EntityPtr e, ComponentId comp_id);
            void removeComponent(EntityPtr e, ComponentId comp_id);
            std::map<ComponentId, ComponentPtr> getComponents(EntityPtr e);
        private:
            World& world_;
            std::map<EntityId, EntityPtr> active_entities_;
            std::list<EntityPtr> removed_and_available_;
            long next_available_id_;
            long count_;
            long unique_entity_id_;
            long total_created_;
            long total_removed_;
            typedef std::map<ComponentId, ComponentPtr> MapCompInner;
            typedef std::map<EntityId, MapCompInner> MapComp;
            MapComp components_by_ent_;

    };
};
#endif
