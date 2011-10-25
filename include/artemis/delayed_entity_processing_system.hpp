#ifndef DELAYEDENTITYPROCESSINGSYSTEM_H
#define DELAYEDENTITYPROCESSINGSYSTEM_H

#include <string>

#include "artemis/delayed_entity_system.hpp"

namespace Artemis
{
    class DelayedEntityProcessingSystem : public DelayedEntitySystem
    {
        public:
            /**
             * Create a new DelayedEntityProcessingSystem. It requires at least one component.
             * @param requiredType the required component type.
             * @param otherTypes the other component types.
             */
            DelayedEntityProcessingSystem(std::list<ComponentId> comp_ids, World& world);

        protected:
            /**
             * Process an entity that this system is interested in.
             * @param e the entity to process.
             */
            virtual void process(EntityPtr e, int accumulatedDelta) =0;

            virtual void processEntities(std::list<EntityPtr> entities, long accumulatedDelta);

        private:
            typedef DelayedEntitySystem super;

    };
};

#endif
