#ifndef ARTEMIS_ENTITY_SYSTEM
#define ARTEMIS_ENTITY_SYSTEM

#include "util/bag.hpp"
#include "util/immutable_bag.hpp"
#include "util/typedefs.hpp"

class Entity;
class World;

class EntitySystem
{
    public:
        EntitySystem();
        EntitySystem(ComponentId compIds[]);

    protected:
        World* world;

        void change(Entity* e);
        virtual void process();
        void setSystemBit(SystemBits bit);

        virtual void begin();
        virtual void end();
        virtual bool checkProcessing();
        virtual void processEntities(ImmutableBag<Entity*>& entities);
        virtual void initialize();
        virtual void added(Entity* e);
        virtual void removed(Entity* e);

    private:
        SystemId system_id_;
        ComponentBits comp_bits_;
        Bag<Entity*> actives_;

        void remove(Entity* e);
        void setWorld(World* world);
};

#endif
