#ifndef ARTEMIS_DELAYED_ENTITY_SYSTEM_H
#define ARTEMIS_DELAYED_ENTITY_SYSTEM_H

#include <list>

#include "pointers/entity.hpp"

#include "entity.hpp"
#include "entity_system.hpp"


namespace Artemis
{
    /**
     * The purpose of this class is to allow systems to execute at varying
     * intervals.
     *
     * An example system would be an ExpirationSystem, that deletes entities
     * after a certain lifetime. Instead of running a system that decrements
     * a timeLeft value for each entity, you can simply use this system to
     * execute in a future at a time of the shortest lived entity, and then
     * reset the system to run at a time in a future of the next shortest
     * lived entity, etc.
     *
     * Another example system would be an AnimationSystem. You know when you
     * have to animate a certain entity, e.g. in 300 milliseconds. So you can
     * set the system to run in 300ms to perform the animation.
     *
     * This will save CPU cycles in some scenarios.
     *
     * Make sure you detect all circumstances that change. E.g. if you create
     * a new entity you should find out if you need to run the system sooner
     * than scheduled, or when deleting an entity, maybe something changed
     * and you need to recalculate when to run. Usually this applies when
     * entities are created, deleted, or changed.
     *
     * This class offeres public methods allowing external systems to use it.
     */
    class DelayedEntitySystem : public EntitySystem
    {
        public:
            DelayedEntitySystem(std::list<ComponentId> comp_ids, World& world);
            bool checkProcessing();
            void processEntities(std::list<EntityPtr> entities);

            /**
             * The entities to process with the accumulated delta.
             * @param entities read-only bag of entities
             */
            virtual void processEntities(std::list<EntityPtr> entities, long accumulated_delta)=0;

            /**
             * Start processing of entities after a certain amount of time (ms)
             *
             * Cancels current delayed run and starts a new one.
             *
             * @param delay time delay in miliseconds until processing starts.
             */
            void startDelayedRun(long delay);

            /**
             * Gets the inital delay that he system was ordered to process
             * entities after.
             *
             * @return the initial delay.
             */
            long get_initial_time_delay();
            long getRemainingTimeUntilProcessing();

            /**
             * Check if the system is counting down towards processing.
             *
             * @return true if it's counting down, false if it's not running.
             */
            bool is_running();
            
            /**
             * Aborts running the system in the future and stops it.
             * Call delayedRun() to start it again.
             */
            void stop();
        private:
            long delay_;
            bool running_;
            long acc_;
    };
};       
#endif
