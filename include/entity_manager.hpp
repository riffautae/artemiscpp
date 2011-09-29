#ifndef ARTEMIS_ENTITY_MANAGER_H
#define ARTEMIS_ENTITY_MANAGER_H

#include <map>
#include <list>

#include "util/typedefs.hpp"


class Component;
class Entity;
class World;

class EntityManager
{
    public:
        EntityManager(World* world);
        ~EntityManager();

        bool isActive(EntityId entity_id);
        long get_entity_count();
        long get_total_created();
        long get_total_removed();
    protected:
        Entity* create();
        void addComponent(Entity* e, ComponentId comp_id);
        void getComponent(Entity* e, ComponentId comp_id);
        void removeComponent(Entity* e, ComponentId comp_id);

        std::list<Component*> getComponents(Entity* e);
        
        Entity* getEntity(EntityId entity_id);

        void remove(Entity* e);
        void refresh(Entity* e);
    private:
        World* world_;
        std::map<EntityId, Entity*> active_entities_;
        std::list<Entity*> removed_and_available_;
        int next_available_id_;
        int count_;
        long unique_entity_id_;
        long total_created_;
        long total_removed_;
        typedef std::map<EntityId, Component*> MapEntIdComp;
        typedef std::map<ComponentId, MapEntIdComp*> MapCompIdMap;
        MapCompIdMap components_by_id_;

        void removeComponentsOfEntity(Entity* entity);
};

#endif
