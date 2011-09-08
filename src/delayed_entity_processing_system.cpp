#include "delayed_entity_processing_system.hpp"

DelayedEntityProcessingSystem::DelayedEntityProcessingSystem(ComponentType requiredType, ComponentType... otherTypes)
{
    DelayedEntitySystem::getMergedTypes(requiredType, otherTypes);
}

void
processEntities(ImmutableBag<Entity*> entities, int accumulatedDelta)
{
    for (int i = 0, s = entities.size(); s > i; i++)
    {
        process(entities.get(i), acumulatedDelta);
    }
}
