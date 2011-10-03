#ifndef ARTEMIS_INTERVAL_ENTITY_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_SYSTEM_H

#include <list>
#include "entity_system.hpp"

class IntervalEntitySystem : public EntitySystem
{
    public:
        IntervalEntitySystem(long interval, std::list<ComponentId> comp_ids);
    protected:
        bool checkProcessing();
    private:
        long acc_;
        long interval_;
};

#endif
