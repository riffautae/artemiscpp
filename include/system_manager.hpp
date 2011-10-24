#ifndef ARTEMIS_SYSTEM_MANAGER_H
#define ARTEMIS_SYSTEM_MANAGER_H

#include <map>

#include "entity_system.hpp"

#include "util/typedefs.hpp"

namespace Artemis
{
    /**
     * If you need to communicate with systems from other systems then look
     * it up here.
     * Use the world instance to retrieve.
     */
    class SystemManager
    {
        private:
            World& world_;
            std::map<SystemId, boost::shared_ptr<EntitySystem> > systems_;
        public:
            SystemManager(World& world);
            SystemId addSystem(boost::shared_ptr<EntitySystem> system);
            std::map<SystemId, boost::shared_ptr<EntitySystem> > getSystems();
            boost::shared_ptr<EntitySystem> getSystem(SystemId id);

            /**
             * After adding all aystems to the world, you must initialize them
             * all.
             */
            void initializeAll();
    };
};
#endif
