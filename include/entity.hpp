#ifndef ARTEMIS_ENTITY_H
#define ARTEMIS_ENTITY_H

#include <string>

#include "entity_manager.hpp"
#include "entity_system.hpp"
#include "util/typedefs.hpp"

class Component;
class World;

class Entity
{
    friend class EntityManager;
    friend class EntitySystem;
    // getters/setters
    public:
        EntityId get_id();
        EntityId get_unique_id();
        bool is_active();
    protected:
        void set_unique_id(EntityId unique_id);
        EntityId get_system_bits();
        void set_system_bits(SystemBits system_bits);
        ComponentBits get_comp_bits();
        void set_comp_bits(ComponentBits comp_bits);

    // other
    public:
        void setGroup(GroupId group);
        void setTag(TagId tag);

        std::string toString();

        void refresh();
        void remove();
        void reset();
    protected:
        Entity(World* world, EntityId id);
        void addSystemId(SystemId Id);
        void removeSystemId(SystemId Id);
        void addCompId(ComponentId id);
        void removeCompId(ComponentId id);

    private:
        EntityId id_;
        EntityId unique_id_;
        ComponentBits comp_bits_;
        SystemBits system_bits_;

        World* world_;
        EntityManager* entity_manager_;
};

#endif
