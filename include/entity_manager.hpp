#ifndef ARTEMIS_ENTITY_MANAGER_H
#define ARTEMIS_ENTITY_MANAGER_H

#include "util/typedefs.hpp"
#include "util/immutable_bag.hpp"
#include "util/bag.hpp"

#include "component.hpp"
#include "entity.hpp"
#include "world.hpp"


class EntityManager
{
    public:
        EntityManager(World* world);
        ~EntityManager();

        bool isActive(EntityId entity_id);
        int get_entity_count();
        long get_total_created();
        long get_total_removed();
    protected:
        Entity* create();
        void addComponent(Entity* e, ComponentId id);
        void getComponent(Entity* e, ComponentId id);
        void removeComponent(Entity* e, ComponentId id);

        ImmutableBag<Component*>* getComponents(Entity* e);
        
        Entity* getEntity(EntityId entity_id);

        void remove(Entity* e);
        void refresh(Entity* e);
    private:
        World* world_;
        Bag<Entity*> active_entities_;
        Bag<Entity*> removed_and_available_;
        int next_available_id_;
        int count_;
        long unique_entity_id_;
        long total_created_;
        long total_removed_;
        Bag<Bag<Component*>*> components_by_id_;
        Bag<Component*> entity_components_;

        void removeComponentsOfEntity(Entity* entity);
};

#endif
