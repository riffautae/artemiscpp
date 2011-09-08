#ifndef ARTEMIS_ENTITY_H
#define ARTEMIS_ENTITY_H

#include <string>

#include "component.h"
#include "component_type.h"
#include "entity_manager.h"
#include "world.h"
#include "util/immutable_bag.h"
#include "util/typedefs.h"

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
        void addComponent(ComponentName name);
        void removeComponent(Component* component);
        void removeComponent(ComponentType* type);
        void removeComponent(ComponentName type);
        Component* getComponent(ComponentType* type);
        Component* getComponent(ComponentName name);
        ImmutableBag<Component* C> getComponents();

        void setGroup(std::string group);
        void setTag(std::string tag);

        std::string toString();

        void refresh();
        void remove();
        void reset();
    protected:
        Entity(World* world, int id);
        void addSystemBit(long bit);
        void removeSystemBit(long bit);
        void addTypeBit(long bit);
        void removeTypeBit(long bit);
    private:
        int id_;
        long unique_id_;
        long type_bits_;
        long system_bits_;

        World world_;
        EntityManager entity_manager_;
}

#endif
