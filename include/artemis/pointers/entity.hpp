#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

namespace Artemis
{
    class Entity;

    typedef boost::weak_ptr<Entity> EntityWkPtr;
    typedef boost::shared_ptr<Entity> EntityPtr;
};
