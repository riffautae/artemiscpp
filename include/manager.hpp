#ifndef ARTEMIS_MANAGER_H
#define ARTEMIS_MANAGER_H

#include "util/typedefs.hpp"

class Manager
{
    public:
        ManagerId get_id();
    protected:
        ManagerId id_;
};

#endif
