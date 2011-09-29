#include "util/bag.h"

template <E>
Bag::Bag()
{
    this(16);
}


template <E>
Bag::Bag(int capacity)
{
    data_ = new E[capacity]();
    alloc_ = capacity;
}

template <E>
Bag::Bag()
{
    //delete[] data_;
}

template <E>
E Bag::remove(int index)
{
    E o = data_[index];
    data_[index] = data_[--size_];
    alloc_--;
    return (E)o;
}


template <E>
E
Bag::remove_last()
{
    if( size > 0 )
    {
        E o = data_[--size_];
        alloc_--;
        return (E) o;
    }

    return null;
}

template <E>
bool
Bag::remove(E o)
{
    for( int i=0; i<size_; i++)
    {
        E o1 = data_[i];

        if( o == o1 )
        {
            data_[i] = data_[--size_];
            alloc_--;
            return true;
        }
    }

    return false;
}

template <E>
bool
Bag::contains(E o)
{
    for( int i=0; size_ > i; i++)
    {
        if( o == data_[i])
        {
            return true;
        }
    }
    return false;
}


template <E>
bool
Bag::remove_all(Bag<E> bag)
{
    bool modified = false;

    for( int i = 0; i < bag.get_size(); i++ )
    {
        E o1 = bag[i];

        for( int j=0; j< size_; j++)
        {
            E o2 = data_[j];

            if( o1 == o2 )
            {
                remove(j);
                j--;
                modified = true;
                break;
            }
        }
    }

    return modified;
}

template<E>
E& Bag::operator[](int index)
{
    return (E) data_[index];
}

template<E>
int Bag::get_size()
{
    return size_;
}

template<E>
int
Bag::capacity()
{
    return alloc_;
}

template<E>
bool
Bag::empty()
{
    return size_ == 0;
}

template<E>
void Bag::insert(E o) const
{
    if( size_ == alloc_)
    {
        grow();
    }

    data_[size_++] = o;
    
}

template<E>
int Bag::grow()
{
    int new_capacity = (data_.length * 3) / 2 + 1;
    grow(new_capacity);
}

template<E>
int Bag::grow(int new_capacity)
{
    E (*old_data)[] = data_;
    data = new E[new_capacity];

    for( int i=0; i<size_; i++ )
    {
        data_[i] = old_data[i];
    }

    delete[] old_data;
    
    alloc_ = new_capacity;
}

////////////////////

template<E>
void Bag::clear()
{
    for( int i=0; i < size_; i++)
    {
        data_[i] = null;
    }

    size_ = 0;
}

template<E>
void Bag::insert_all(Bag<E> items)
{
    for( int i=0; items.get_size() > i; i++ )
    {
        insert(items[i]);
    }
}
