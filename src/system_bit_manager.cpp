#include "system_bit_manager.hpp"

#include "entity_system.hpp"

SystemBitManager::SystemBitManager()
{
    POS_ = 0;
    system_bits_ = std::map<EntitySystem*, SystemBits>();
}

SystemBits SystemBitManager::getBitFor(EntitySystem* es){
    std::map<EntitySystem*, SystemBits>::iterator sysi;
    sysi = system_bits_.find(es);
    
    if(sysi != system_bits_.end() )
    {
        SystemId bit = (*sysi).second;
        bit = 1 << POS_;
        POS_++;
        system_bits_[es] = bit;
        return bit;
    }
    return 0xFF;
}

