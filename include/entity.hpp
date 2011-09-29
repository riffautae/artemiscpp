#ifndef ARTEMIS_ENTITY_H
#define ARTEMIS_ENTITY_H

#include <string>

#include "entity_manager.hpp"
#include "world.hpp"
#include "util/immutable_bag.hpp"
#include "util/typedefs.hpp"

class Component;

class Entity
{
    // getters/setters
    public:
        int get_id();
        long get_unique_id();
        bool is_active();
    protected:
        void set_unique_id(long unique_id);
        long get_system_bits();
        void set_system_bits(long system_bits);
        long get_type_bits();
        void set_type_bits(long type_bits);

    // other
    public:
        void addComponent(Component* component);
        void addComponent(ComponentId id);
        void removeComponent(Component* component);
        void removeComponent(ComponentId id);
        Component* getComponent(ComponentId id);
        ImmutableBag<Component*>* getComponents();

        void setGroup(GroupId group);
        void setTag(std::string tag);

        std::string toString();

        void refresh();
        void remove();
        void reset();
    protected:
        Entity(World* world, int id);
        void addSystemId(SystemId bit);
        void removeSystemId(long bit);
        void addCompId(ComponentId id);
        void removeCompId(ComponentId id);
    private:
        int id_;
        EntityId unique_id_;
        ComponentBits comp_bits_;
        SystemBits system_bits_;

        World* world_;
        EntityManager* entity_manager_;
};

#endif
