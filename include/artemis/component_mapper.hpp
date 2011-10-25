#ifndef ARTEMIS_COMPONENTMAPPER_H
#define ARTEMIS_COMPONENTMAPPER_H

#include "artemis/util/typedefs.hpp"
#include "artemis/entity_manager.hpp"
#include "artemis/world.hpp"


namespace Artemis
{
    class Entity;

    /**
     * High performance component retrieval from entities. Use this whenever you
     * need to retrieve components from entities often and fast.
     *
     * @param <T>
     */

    template <class T>
    class ComponentMapper
    {
        public:
            ComponentMapper(ComponentId id, WorldPtr world)
            {
                this->id_ = id;
                this->em_ = world->get_entity_manager();
            }
            T* get(Entity* e)
            {
                return dynamic_cast<T>(em_->getComponent(e, id_));
            }
        private:
            ComponentId id_;
            EntityManager* em_;
    };
};
#endif
