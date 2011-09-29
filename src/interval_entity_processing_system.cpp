#include "interval_entity_processing_system.hpp"

InterValEntityProcessingSystem::InterValEntityProcessingSystem(
        int interval, ComponentType* requiredType,
        ComponentType* ... otherTypes)
{
    IntervalEntitySystem::IntervalEntitySystem(interval,
            getMergedTypes(requiredType, otherTypes));
}

void InterValEntityProcessingSystem::processEntities(
        ImmutableBag<Entity*>* entities)
{
    BOOST_FOREACH(Entity* e, *entities)
    {
        process(e);
    }
}
