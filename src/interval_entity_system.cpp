#include "interval_entity_system.hpp"

IntervalEntitySystem::IntervalEntitySystem(
        int interval, ComponentType* ... types)
{
    EntitySystem::EntitySystem(types);
    this->interval_ = interval;
}

bool IntervalEntitySystem::checkProcessing()
{
    acc += world->get_delta();
    if( acc >= interval )
    {
        acc -= interval;
        return true;
    }
    return false;
}
