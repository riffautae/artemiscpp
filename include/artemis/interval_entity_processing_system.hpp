#ifndef ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H

#include <list>

#include "artemis/entity.hpp"
#include "artemis/interval_entity_system.hpp"

namespace Artemis
{
    class Entity;

    /**
     * If you need to process entities at a certain interval then use this.
     * A typical usage would be to regenerate ammo or health at certain
     * intervals, no need to do that every game loop, but perhaps every
     * 100ms or every second.
     */
    class IntervalEntityProcessingSystem : public IntervalEntitySystem
    {
        public:
            /**
             * Requires at least one component.
             *
             * @param interval
             * @param comp_ids the components this system is interested in
             */
            IntervalEntityProcessingSystem(
                    long interval, std::list<ComponentId> comp_ids,
                    World& world);

        protected:
            virtual void process(EntityPtr e);
            void processEntities(std::list<EntityPtr> entities);
    };
};
#endif
