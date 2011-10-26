#ifndef ARTEMIS_ENTITY_PROCESSING_SYSTEM
#define ARTEMIS_ENTITY_PROCESSING_SYSTEM

#include <list>

#include "artemis/entity.hpp"
#include "artemis/entity_system.hpp"

namespace Artemis
{
    /**
     * A typical entity system. Use this when you need to process entities
     * possessing the provided component types.
     */
    class EntityProcessingSystem : public EntitySystem
    {
        public:
            /**
             * Create a new entity processing system. It requires at least one
             * component.
             * @param comp_ids the components it requires
             */
            EntityProcessingSystem(std::list<ComponentId> comp_ids, World& world);

            /**
             * Process an entity this system is interested in
             * @param e the entity to process
             */
            virtual void process(EntityPtr e)=0;
            void processEntities(std::list<EntityPtr> entities);

        protected:
            virtual bool checkProcessing();
    };
};
#endif
