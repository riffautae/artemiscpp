#include "interval_entity_system.hpp"
#include "world.hpp"

using namespace Artemis;
IntervalEntitySystem::IntervalEntitySystem(
        long interval, std::list<ComponentId> comp_ids, World& world) : 
    EntitySystem::EntitySystem(comp_ids, world)
{
    this->interval_ = interval;
}

bool IntervalEntitySystem::checkProcessing()
{
    acc_ += world_.get_delta();
    if( acc_ >= interval_ )
    {
        acc_ -= interval_;
        return true;
    }
    return false;
}
