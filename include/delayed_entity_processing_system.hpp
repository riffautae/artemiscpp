#ifndef DELAYEDENTITYPROCESSINGSYSTEM_H
#define DELAYEDENTITYPROCESSINGSYSTEM_H

#include <string>

#include "delayed_entity_system.hpp"
#include "util/immutable_bag.hpp"

class DelayedEntityProcessingSystem : public DelayedEntitySystem
{
    public:
        /**
         * Create a new DelayedEntityProcessingSystem. It requires at least one component.
         * @param requiredType the required component type.
         * @param otherTypes the other component types.
         */
        DelayedEntityProcessingSystem(std::list<ComponentId> comp_ids);

    protected:
        virtual void process(Entity* e, int accumulatedDelta) =0;

        virtual void processEntities(std::list<Entity*> entities, long accumulatedDelta);

    private:
        typedef DelayedEntitySystem super;

};

#endif
