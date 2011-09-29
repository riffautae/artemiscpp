#include "system_bit_manager.hpp"

SystemBitManager::SystemBitManager()
{
    POS = 0;
    systemBits = hash_map<EntitySystem*, SystemBits>();
}


