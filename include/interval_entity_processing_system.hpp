#ifndef ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_PROCESSING_SYSTEM_H

#include <list>

#include "interval_entity_system.hpp"

class Entity;

class IntervalEntityProcessingSystem : public IntervalEntitySystem
{
    public:
        IntervalEntityProcessingSystem(
                long interval, std::list<ComponentId> comp_ids);

    protected:
        virtual void process(Entity* e);
        void processEntities(std::list<Entity*> entities);
};

#endif
