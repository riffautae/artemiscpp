#ifndef ARTEMIS_DELAYED_ENTITY_SYSTEM_H
#define ARTEMIS_DELAYED_ENTITY_SYSTEM_H

#include "component_type.hpp"
#include "entity.hpp"
#include "entity_system.hpp"
#include "util/typedefs.hpp"
#include "util/immutable_bag.hpp"

class DelayedEntitySystem : public EntitySystem
{
    public:
        DelayedEntitySystem(ComponentType*... types);
        void processEntities(ImmutableBag<Entity*> entities);
        bool checkProcessing();
        virtual void processEntities(ImmutableBag<Entity*> entities, int accumulated_delta)=0;
        void startDelayedRun(int delay);
        int get_initial_time_delay();
        int getRemainingTimeUntilProcessing();
        bool is_running();
        void stop();
    private:
        int delay_;
        bool running_;
        int acc_;

        typedef EntitySystem super;
}
        
#endif
