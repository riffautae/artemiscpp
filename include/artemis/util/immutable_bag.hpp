#ifndef ARTEMIS_UTIL_IMMUTABLE_BAG_H
#define ARTEMIS_UTIL_IMMUTABLE_BAG_H

template <class E>
class ImmutableBag
{
    public:
        virtual E get(int index);
        virtual long get_size();
        virtual bool empty();
};

#endif
