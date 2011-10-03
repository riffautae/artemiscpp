#ifndef ARTEMIS_ENTITY_SYSTEM
#define ARTEMIS_ENTITY_SYSTEM

#include <list>

#include "util/bag.hpp"
#include "util/immutable_bag.hpp"
#include "util/typedefs.hpp"

class Entity;
class World;

class EntitySystem
{
    public:
        EntitySystem();
        EntitySystem(std::list<ComponentId> compIds);

    protected:
        World* world_;

        void change(Entity* e);
        virtual void process();
        void setSystemId(SystemId id);

        virtual void begin();
        virtual void end();
        virtual bool checkProcessing();
        virtual void processEntities(std::list<Entity*> entities);
        virtual void initialize();
        virtual void added(Entity* e);
        virtual void removed(Entity* e);

    private:
        SystemId system_id_;
        ComponentBits comp_bits_;
        std::list<Entity*> actives_;

        void remove(Entity* e);
        void setWorld(World* world);
};

#endif
