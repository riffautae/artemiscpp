#ifndef ARTEMIS_UTIL_ENTITY_SYSTEM
#define ARTEMIS_UTIL_ENTITY_SYSTEM

#include "util/typedefs.hpp"
#include "util/bag.hpp"
#include "util/immutable_bag.hpp"

class EntitySystem
{
    public:
        EntitySystem();
        EntitySystem(ComponentType& ... types);

    protected:
        World* world_;

        void change(Entity& e);
        void process();
        void setSystemBit(SystemBits bit);

        virtual void begin();
        virtual void end();
        virtual bool checkProcessing();
        virtual void processEntities(ImmutableBag<Entity*>& entities);
        virtual void initialize();
        virtual void added(Entity* e);
        virtual void removed(Entity* e);

        static (ComponentType*)[] getMergedTypes(const ComponentType* requiredType, const (ComponentType*)[] otherTypes);

    private:
        SystemBits system_bit_;
        TypeFlags type_flags_;
        Bag<Entity*> actives_;

        void remove(Entity* e);
        void setWorld(World* world);
}

#endif
