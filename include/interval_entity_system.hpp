#ifndef ARTEMIS_INTERVAL_ENTITY_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_SYSTEM_H

#include "component_type.hpp"
#include "entity_system.hpp"

class IntervalEntitySystem : public EntitySystem
{
    public:
        IntervalEntitySystem(int interval, ComponentType* ... types);
    protected:
        bool checkProcessing();
    private:
        int acc_;
        int interval_;
};

#endif
