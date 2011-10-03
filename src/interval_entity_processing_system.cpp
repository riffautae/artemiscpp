#include "boost/foreach.hpp"

#include "interval_entity_processing_system.hpp"
#include "entity.hpp"

IntervalEntityProcessingSystem::IntervalEntityProcessingSystem(
        long interval, std::list<ComponentId> comp_ids) : 
    IntervalEntitySystem::IntervalEntitySystem(interval,
            comp_ids)
{
}

void IntervalEntityProcessingSystem::processEntities(
        std::list<Entity*> entities)
{
    BOOST_FOREACH(Entity* e, entities)
    {
        process(e);
    }
}
