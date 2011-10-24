#ifndef ARTEMIS_INTERVAL_ENTITY_SYSTEM_H
#define ARTEMIS_INTERVAL_ENTITY_SYSTEM_H

#include <list>
#include "entity_system.hpp"

namespace Artemis
{
    /**
     * A system that processes entities at an interval in milliseconds.
     * A typical usage would be a collision system or physics system.
     */
    class IntervalEntitySystem : public EntitySystem
    {
        public:
            IntervalEntitySystem(long interval, std::list<ComponentId> comp_ids, World& world);
        protected:
            bool checkProcessing();
        private:
            long acc_;
            long interval_;
    };
};
#endif
