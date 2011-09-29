#include "delayed_entity_system.hpp"
#include "world.hpp"

DelayedEntitySystem::DelayedEntitySystem(ComponentId compIds[])
    : super(compIds)
{
}

void DelayedEntitySystem::processEntities(ImmutableBag<Entity*> entities)
{
    processEntities(entities, acc_);
    stop();
}

bool DelayedEntitySystem::checkProcessing()
{
    if( running_ )
    {
        acc_ += world->get_delta();

        if( acc_ >= delay_)
        {
            return true;
        }
    }
    return false;
}

void DelayedEntitySystem::startDelayedRun(int delay)
{
    delay_ = delay;
    acc_ = 0;
    running_ = true;
}

int DelayedEntitySystem::get_initial_time_delay()
{
    return delay_;
}

int DelayedEntitySystem::getRemainingTimeUntilProcessing()
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
