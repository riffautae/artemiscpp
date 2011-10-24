#include "boost/foreach.hpp"

#include "delayed_entity_processing_system.hpp"

using namespace Artemis;
DelayedEntityProcessingSystem::DelayedEntityProcessingSystem(std::list<ComponentId> comp_ids, World& world) 
    : DelayedEntitySystem::DelayedEntitySystem(comp_ids, world)
{
}

void DelayedEntityProcessingSystem::processEntities(std::list<EntityPtr> entities, long accumulatedDelta)
{
    BOOST_FOREACH(EntityPtr e, entities)
    {
        process(e, accumulatedDelta);
    }
}
