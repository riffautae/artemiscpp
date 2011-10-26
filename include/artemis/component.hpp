#ifndef ARTEMIS_COMPONENT_H
#define ARTEMIS_COMPONENT_H

#include "artemis/util/typedefs.hpp"

/**
 * A tag class. All components in the system must extend this class.
 */
namespace Artemis
{
    class Component {
        public:
            Component();
            virtual ComponentId getComponentId();
    };
};

#endif
