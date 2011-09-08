#include <typeinfo>

#include "component_mapper.hpp"
#include "component_type_manager.hpp"

template <class T>
ComponentMapper::ComponentMapper(World const &world)
{
    this->em = world.getEntityManager();
    this->type = ComponentTypeManager::getTypeFor(typeid(T));
}

template <class T>
T ComponentMapper::get(Entity* e)
{
    return dynamic_cast<T>(em_->getComponent(e, this->type_));
}
