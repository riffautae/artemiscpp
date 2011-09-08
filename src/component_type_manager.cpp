#include "component_type_manager.hpp"

ComponentType ComponentTypeManager::getTypeFor(ComponentName name)
{
    std::map<type_info, ComponentType>::iterator it =
        component_types_str_.find(name);
    ComponentType type;
    if( it == component_types_str_.end() )
    {
        type = new ComponentType();
        component_types_str_.insert(name, type);
    }
    else
    {
        type = it.second();
    }
    return type;
}

ComponentType ComponentTypeManager::getTypeFor(type_info c)
{
    std::map<type_info, ComponentType>::iterator it =
        component_types_info_.find(c);
    ComponentType type;
    if( it == component_types_info_.end() )
    {
        type = new ComponentType();
        component_types_info_.insert(c, type);
    }
    else
    {
        type = it.second();
    }
    return type;
}

long ComponentTypeManager::getBit(ComponentType const &comp)
{
    return comp.getBit();
}

int ComponentTypeManager::getId(ComponentType const &comp)
{
    return comp.getId();
}
