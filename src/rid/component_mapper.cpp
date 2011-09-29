#include "component_mapper.hpp"
#include "component_type_manager.hpp"

template <Component T>
ComponentMapper::ComponentMapper(World* world)
{
    this->em = world->getEntityManager();
    this->type = ComponentTypeManager::getTypeFor(typeid(T));
}

template <Component T>
T* ComponentMapper::get(Entity* e)
{
    return dynamic_cast<T*>(em_->getComponent(e, this->type_));
}
