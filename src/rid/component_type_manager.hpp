#ifndef COMPONENTTYPEMANAGER_H
#define COMPONENTTYPEMANAGER_H

#include <map>
#include <string>
#include <typeinfo>

#include "component_type.hpp"
#include "util/typedefs.hpp"

class ComponentTypeManager
{
    public:
        static ComponentType getTypeFor(type_info c);
        static ComponentType getTypeFor(ComponentName n);
        static long getBit(ComponentType comp);
        static int getId(ComponentType comp);
    private:
        static std::map<type_info, ComponentType> component_types_info_;
        static std::map<ComponentName, ComponentType> component_types_str_;
}

#endif
