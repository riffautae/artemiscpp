#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

namespace Artemis
{
    class Manager;

    typedef boost::weak_ptr<Manager> ManagerWkPtr;
    typedef boost::shared_ptr<Manager> ManagerPtr;
};
