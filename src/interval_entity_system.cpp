#include "interval_entity_system.hpp"
#include "world.hpp"

IntervalEntitySystem::IntervalEntitySystem(
        long interval, std::list<ComponentId> comp_ids) : 
    EntitySystem::EntitySystem(comp_ids)
{
    this->interval_ = interval;
}

bool IntervalEntitySystem::checkProcessing()
{
    acc_ += world_->get_delta();
    if( acc_ >= interval_ )
    {
        acc_ -= interval_;
        return true;
    }
    return false;
}
