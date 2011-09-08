#ifndef DELAYEDENTITYPROCESSINGSYSTEM_H
#define DELAYEDENTITYPROCESSINGSYSTEM_H

#include <string>
#include "utils/immutable_bag.hpp"

#include "delayed_entity_system.hpp"
#include "entity.hpp"

class DelayedEntityProcessingSystem : public DelayedEntitySystem
{
    public:
        /**
         * Create a new DelayedEntityProcessingSystem. It requires at least one component.
         * @param requiredType the required component type.
         * @param otherTypes the other component types.
         */
        DelayedEntityProcessingSystem(ComponentType requiredType, ComponentType... otherTypes);

    protected:
        virtual void process(Entity* e, int accumulatedDelta) =0;

        void processEntities(ImmutableBag<Entity*> entities, int accumulatedDelta);

}

#endif
