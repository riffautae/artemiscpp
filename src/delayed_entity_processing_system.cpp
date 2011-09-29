#include "delayed_entity_processing_system.hpp"

DelayedEntityProcessingSystem::DelayedEntityProcessingSystem(ComponentId compIds[]) : DelayedEntitySystem(compIds)
{
}

void DelayedEntityProcessingSystem::processEntities(ImmutableBag<Entity*> entities, int accumulatedDelta)
{
    for (int i = 0, s = entities.get_size(); s > i; i++)
    {
        process(entities.get(i), accumulatedDelta);
    }
}
