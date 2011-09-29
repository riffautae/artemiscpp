#ifndef ARTEMIS_SYSTEM_BIT_MANAGER_H
#define ARTEMIS_SYSTEM_BIT_MANAGER_H

#include <hash_map>

#include "util/typedefs.hpp"

class SystemBitManager
{
    public:
        SystemBitManager();
    protected:
        static SystemBits getBitFor(EntitySyetem* es);
    private:
        static int POS_;
        static hash_map<EntitySystem*, SystemBits> systemBit;

};

#endif
