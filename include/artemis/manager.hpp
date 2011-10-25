#ifndef ARTEMIS_MANAGER_H
#define ARTEMIS_MANAGER_H

#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    class Manager
    {
        public:
            ManagerId get_id();
        protected:
            ManagerId id_;
    };
};
#endif
