#ifndef ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H

#include "utils/immutable_bag.hpp"

class InterValEntityProcessingSystem : public IntervalEntitySystem
{
    public:
        IntervalEntityProcessingSystem(
                int interval, ComponentType* requiredType,
                ComponentType* ... otherTypes);

    protected:
        virtual void process(Entity* e);
        void processEntities(ImmutableBag<Entity*>* entities);
};

#endif
