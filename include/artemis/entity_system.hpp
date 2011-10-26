#ifndef ARTEMIS_ENTITY_SYSTEM_H
#define ARTEMIS_ENTITY_SYSTEM_H

#include <list>

#include "artemis/entity.hpp"

#include "artemis/util/typedefs.hpp"

namespace Artemis
{
    class EntityManager;
    class SystemManager;
    class World;
    /**
     * The most raw entity system. It should not typically be used, but you can 
     * create your own entity system handling by extending this. It is recommended
     * that you use the other provided entity system implementations.
     * 
     * @author Arni Arent
     *
     */
    class EntitySystem
    {
        friend class SystemManager;
        friend class EntityManager;
        public:
            EntitySystem(std::list<ComponentId> compIds, World& world);

            void process();

            long numEntities();
        protected:
            World& world_;

            void change(EntityPtr e);

            SystemId get_id();
            void set_id(SystemId id);

            /**
             * Called before processing of entities begins
             */
            virtual void begin();

            /**
             * Called after the processing of entities ends
             */
            virtual void end();

            /**
             * @return true of the system should be processed, false if not.
             */
            virtual bool checkProcessing();

            /**
             * Any implementing entity system must implement this method and the
             * logic to process the given entities of the system.
             *
             * @param entities the entities this system contains.
             */
            virtual void processEntities(std::list<EntityPtr> entities)=0;
            virtual void initialize();

            /**
             * Called if the system has received an entity it is interested in,
             * e.g. created or a component was added to it.
             * @param e the entity that was added to this system.
             */
            virtual void added(EntityPtr e);

            /**
             * Called if an entity was removed from this system, e.g. deleted or
             * had one of it's components removed.
             * @param e the entity that was removed from this system
             */
            virtual void removed(EntityPtr e);

        private:
            SystemId system_id_;
            ComponentBits comp_bits_;
            std::list<EntityPtr> actives_;

            void remove(EntityPtr e);
    };
};
#endif
