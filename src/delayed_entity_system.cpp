#include "artemis/delayed_entity_system.hpp"
#include "artemis/world.hpp"

using namespace Artemis;
DelayedEntitySystem::DelayedEntitySystem(std::list<ComponentId> comp_ids, World& world)
    : EntitySystem::EntitySystem(comp_ids, world)
{
}

void DelayedEntitySystem::processEntities(std::list<EntityPtr> entities)
{
    processEntities(entities, acc_);
    stop();
}

bool DelayedEntitySystem::checkProcessing()
{
    if( running_ )
    {
        acc_ += world_.get_delta();

        if( acc_ >= delay_)
        {
            return true;
        }
    }
    return false;
}

void DelayedEntitySystem::startDelayedRun(long delay)
{
    delay_ = delay;
    acc_ = 0;
    running_ = true;
}

long DelayedEntitySystem::get_initial_time_delay()
{
    return delay_;
}

long DelayedEntitySystem::getRemainingTimeUntilProcessing()
{
    if( running_ )
    {
        return delay_ - acc_;
    }
    return 0;
}

void DelayedEntitySystem::stop()
{
    running_ = false;
    acc_ = 0;
}
