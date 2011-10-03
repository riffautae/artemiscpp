#ifndef ARTEMIS_SYSTEM_BIT_MANAGER_H
#define ARTEMIS_SYSTEM_BIT_MANAGER_H

#include <map>

#include "util/typedefs.hpp"

class EntitySystem;

class SystemBitManager
{
    public:
        SystemBitManager();
    protected:
        static SystemBits getBitFor(EntitySystem* es);
    private:
        static long POS_;
        static std::map<EntitySystem*, SystemBits> system_bits_;

};

#endif
