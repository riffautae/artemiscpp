#ifndef ARTEMIS_UTIL_BAG_H
#define ARTEMIS_UTIL_BAG_H

#include "ImmutableBag.h"

template <E>
class Bag : public ImmutableBag<E>
{
    public:
        Bag();
        Bag(int capacity);
        ~Bag();
        E& remove(int index);
        E& remove_last();
        bool remove(E o);
        bool contains(E o);
        bool remove_all(Bag<E> bag);
        E& operator[](int index);
        E& operator[](int index, const E& o);
        int size();
        int capacity();
        bool empty();
        void insert(E o);
        void insert_all(Bag<E> items);
        void clear();

    private:
        E[] data;
        int size = 0;

        void grow();
        void grow(int new_capacity);


}

#endif
