#include "entity_processing_system.hpp"

#include "boost/foreach.hpp"

EntityProcessingSystem::EntityProcessingSystem(std::list<ComponentId> comp_ids) : EntitySystem::EntitySystem(comp_ids)
{
}

void EntityProcessingSystem::processEntities(std::list<Entity*> entities)
{
    BOOST_FOREACH(Entity* e, entities)
    {
        process(e);
    }
}

bool EntityProcessingSystem::checkProcessing()
{
   return true;
} 
