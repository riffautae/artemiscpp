#include "boost/foreach.hpp"

#include "delayed_entity_processing_system.hpp"

DelayedEntityProcessingSystem::DelayedEntityProcessingSystem(std::list<ComponentId> comp_ids) : DelayedEntitySystem::DelayedEntitySystem(comp_ids)
{
}

void DelayedEntityProcessingSystem::processEntities(std::list<Entity*> entities, long accumulatedDelta)
{
    BOOST_FOREACH(Entity* e, entities)
    {
        process(e, accumulatedDelta);
    }
}
