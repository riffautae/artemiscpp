#ifndef ARTEMIS_UTIL_BAG_H
#define ARTEMIS_UTIL_BAG_H

#include "util/immutable_bag.hpp"

template <class E>
class Bag : public ImmutableBag<E>
{
    public:
        Bag();
        Bag(int capacity);
        ~Bag();
        E remove(int index);
        E remove_last();
        bool remove(E o);
        bool contains(E o);
        bool remove_all(Bag<E> bag);
        E& operator[](int index);
        int get_size();
        int get_capacity();
        bool empty();
        void insert(E o);
        void insert_all(Bag<E> items);
        void clear();

    private:
        E (*data_)[];
        int size_;
        int alloc_;

        void grow();
        void grow(int new_capacity);


};

#endif
