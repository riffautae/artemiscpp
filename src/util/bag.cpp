#include "util/bag.hpp"

template <E>
Bag::Bag<E>()
{
    this(16);
}


template <E>
Bag::Bag<E>(long capacity)
{
    data_ = new E[capacity]();
    alloc_ = capacity;
}

template <E>
Bag::Bag<E>()
{
    //delete[] data_;
}

template <E>
E Bag::remove<E>(long index)
{
    E o = data_[index];
    data_[index] = data_[--size_];
    alloc_--;
    return (E)o;
}


template <E>
E
Bag::removeLast<E>()
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
Bag::remove<E>(E o)
{
    for( long i=0; i<size_; i++)
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
Bag::contains<E>(E o)
{
    for( long i=0; size_ > i; i++)
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
Bag::removeAll<E>(Bag<E> bag)
{
    bool modified = false;

    for( long i = 0; i < bag.get_size(); i++ )
    {
        E o1 = bag[i];

        for( long j=0; j< size_; j++)
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
E& Bag::operator[]<E>(long index)
{
    return (E) data_[index];
}

template<E>
long
Bag::get_size<E>()
{
    return size_;
}

template<E>
long
Bag::capacity<E>()
{
    return alloc_;
}

template<E>
bool
Bag::empty<E>()
{
    return size_ == 0;
}

template<E>
void Bag::insert<E>(E o) const
{
    if( size_ == alloc_)
    {
        grow();
    }

    data_[size_++] = o;
    
}

template<E>
long Bag::grow<E>()
{
    long new_capacity = (data_.length * 3) / 2 + 1;
    grow(new_capacity);
}

template<E>
long Bag::grow<E>(long new_capacity)
{
    E (*old_data)[] = data_;
    data = new E[new_capacity];

    for( long i=0; i<size_; i++ )
    {
        data_[i] = old_data[i];
    }

    delete[] old_data;
    
    alloc_ = new_capacity;
}

////////////////////

template<E>
void Bag::clear<E>()
{
    for( long i=0; i < size_; i++)
    {
        data_[i] = null;
    }

    size_ = 0;
}

template<E>
void Bag::insertAll<E>(Bag<E> items)
{
    for( long i=0; items.get_size() > i; i++ )
    {
        insert(items[i]);
    }
}
