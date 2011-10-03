#ifndef ARTEMIS_ENTITY_PROCESSING_SYSTEM
#define ARTEMIS_ENTITY_PROCESSING_SYSTEM

#include <list>

#include "entity_system.hpp"

class EntityProcessingSystem : public EntitySystem
{
    public:
        EntityProcessingSystem(std::list<ComponentId> comp_ids);

    protected:
        virtual void process(Entity* e);
        void processEntities(std::list<Entity*> entities);
        virtual bool checkProcessing();
};

#endif
