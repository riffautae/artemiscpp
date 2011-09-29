#ifndef ARTEMIS_UTIL_BAG_H
#define ARTEMIS_UTIL_BAG_H

#include "util/immutable_bag.hpp"

template <class E>
class Bag : public ImmutableBag<E>
{
    public:
        Bag();
        Bag(long capacity);
        ~Bag();
        E remove(long index);
        E removeLast();
        bool remove(E o);
        bool contains(E o);
        bool removeAll(Bag<E> bag);
        E& operator[](long index);
        long get_size();
        long get_capacity();
        bool empty();
        void insert(E o);
        void insertAll(Bag<E> items);
        void clear();

    private:
        E (*data_)[];
        long size_;
        long alloc_;

        void grow();
        void grow(long new_capacity);


};

#endif
