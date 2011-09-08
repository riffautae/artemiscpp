#ifndef ARTEMIS_ENTITY_PROCESSING_SYSTEM
#define ARTEMIS_ENTITY_PROCESSING_SYSTEM

#include "entity_system.hpp"
#include "component_type.hpp"

class EntityProcessingSystem : public EntitySystem
{
    public:
        EntityProcessingSystem(ComponentType& requiredType, ComponentType& ... otherTypes);

    protected:
        virtual void process(Entity* e);
        void processEntities(ImmutableBag<Entity*>& entities);
        bool checkProcessing();
}

#endif
