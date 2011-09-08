#include "entity_processing_system.hpp"

EntityProcessingSystem::EntityProcessingSystem(ComponentType& requiredType, ComponentType& ... otherTypes)
{
    EntitySystem::EntitySystem(getMergedTypes(requiredType, otherTypes));
}

void EntityProcessingSystem::processEntities(ImmutableBag<Entity*>& entities)
{
    for( int i = 0, s = entities->size(); s > i; i++ )
    {
        process(entities->get(i));
    }
}

bool EntityProcessingSystem::checkProcessing()
{
   return true;
} 
