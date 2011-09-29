#include "component_mapper.hpp"

#include "world.hpp"

template <class T>
ComponentMapper<T>::ComponentMapper(ComponentId id, World* world)
{
    this->id_ = id;
    this->em_ = world->get_entity_manager();
}

template <class T>
T* ComponentMapper<T>::get(Entity* e)
{
    return dynamic_cast<T*>(em_->getComponent(e, id_));
}
