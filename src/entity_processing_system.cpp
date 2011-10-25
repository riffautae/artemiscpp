#include "artemis/entity_processing_system.hpp"

#include "boost/foreach.hpp"

using namespace Artemis;
EntityProcessingSystem::EntityProcessingSystem(std::list<ComponentId> comp_ids, World& world) :
    EntitySystem::EntitySystem(comp_ids, world)
{
}

void EntityProcessingSystem::processEntities(std::list<EntityPtr> entities)
{
    BOOST_FOREACH(EntityPtr e, entities)
    {
        process(e);
    }
}

bool EntityProcessingSystem::checkProcessing()
{
   return true;
} 
