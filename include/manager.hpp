#ifndef ARTEMIS_MANAGER_H
#define ARTEMIS_MANAGER_H

#include "util/typedefs.hpp"

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
