#ifndef ARTEMIS_ENTITY_MANAGER_H
#define ARTEMIS_ENTITY_MANAGER_H

#include "util/typedefs.hpp"
#include "util/bag.hpp"
#include "util/immutable_bag.hpp"

#include "component.hpp"
#include "component_type.hpp"
#include "entity.hpp"
#include "world.hpp"


class EntityManager
{
    public:
        EntityManager(World* world);
        ~EntityManager();

        bool isActive(EntityID entity_id);
        int get_entity_count();
        long get_total_created();
        long get_total_removed();
    protected:
        Entity* create();
        void addComponent(Entity* e, ComponentType* type);
        void getComponent(Entity* e, ComponentType* type);
        void removeComponent(Entity* e, ComponentType* type);

        ImmutableBag<Component*> getComponents(const Entity* e);
        
        Entity* getEntity(int entity_id);

        void remove(Entity* e);
        void refresh(Entity* e);
    private:
        World* world_;
        Bag<Entity*> active_entities_;
        Bag<Entity*> removeed_and_available_;
        int next_available_id_;
        int count_;
        long unique_entity_id_;
        long total_created_;
        long total_removed_;
        Bag<Bag<Component*>*>* components_by_type_;
        Bag<Component*>* entity_components_;

        void removeComponentsOfEntity(Entity &entity);

#endif
