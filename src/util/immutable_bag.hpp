#ifndef ARTEMIS_UTIL_IMMUTABLE_BAG_H
#define ARTEMIS_UTIL_IMMUTABLE_BAG_H

template<E>
class ImmutableBag
{
    public:
        virtual E& get(int index);
        virtual int size();
        virtual bool empty();
}

#endif
