#include "boost/foreach.hpp"

#include "artemis/interval_entity_processing_system.hpp"
#include "artemis/entity.hpp"

using namespace Artemis;
IntervalEntityProcessingSystem::IntervalEntityProcessingSystem(
        long interval, std::list<ComponentId> comp_ids, World& world) : 
    IntervalEntitySystem::IntervalEntitySystem(
            interval, comp_ids, world)
{
}

void IntervalEntityProcessingSystem::processEntities(
        std::list<EntityPtr> entities)
{
    BOOST_FOREACH(EntityPtr e, entities)
    {
        process(e);
    }
}
