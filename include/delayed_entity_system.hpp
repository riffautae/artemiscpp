#ifndef ARTEMIS_DELAYED_ENTITY_SYSTEM_H
#define ARTEMIS_DELAYED_ENTITY_SYSTEM_H

#include <list>

#include "entity_system.hpp"

class DelayedEntitySystem : public EntitySystem
{
    public:
        DelayedEntitySystem(std::list<ComponentId> comp_ids);
        void processEntities(ImmutableBag<Entity*> entities);
        bool checkProcessing();
        void processEntities(std::list<Entity*> entities);
        virtual void processEntities(std::list<Entity*> entities, long accumulated_delta)=0;
        void startDelayedRun(long delay);
        long get_initial_time_delay();
        long getRemainingTimeUntilProcessing();
        bool is_running();
        void stop();
    private:
        long delay_;
        bool running_;
        long acc_;
};
        
#endif
