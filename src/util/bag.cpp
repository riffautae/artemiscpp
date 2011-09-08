#include "util/bag.h"

template <E>
Bag::Bag()
{
    this(16);
}


template <E>
Bag::Bag(int capacity)
{
    data = new E[capacity];
}

template <E>
Bag::Bag()
{
    delete[] data;
}

template <E>
E Bag::remove(int index)
{
    E o = data[index];
    data[index] = data[--size];
    data[size] = null;
    return (E)o;
}


template <E>
E
Bag::remove_last()
{
    if( size > 0 )
    {
        E o = data[--size];
        data[size] = null;
        return (E) o;
    }

    return null;
}

template <E>
bool
Bag::remove(E o)
{
    for( int i=0; i<size; i++)
    {
        E o1 = data[i];

        if( o == o1 )
        {
            data[i] = data[--size];

            data[size] = null;

            return true;
        }
    }

    return false;
}

template <E>
bool
Bag::contains(E o)
{
    for( int i=0; size > i; i++)
    {
        if( o == data[i])
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

    for( int i = 0; i < bag.size(); i++ )
    {
        E o1 = bag[i];

        for( int j=0; j< size; j++)
        {
            E o2 = data[j];

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
    return (E) data[index];
}

template<E>
int Bag::size()
{
    return size;
}

template<E>
int
Bag::capacity()
{
    return data.length;
}

template<E>
bool
Bag::empty()
{
    return size == 0;
}

template<E>
void Bag::insert(E o) const
{
    if( size == data.length)
    {
        grow();
    }

    data[size++] = o;
    
}

template<E>
E& Bag::operator[](int index, const E& o)
{
    if( index >= data.length )
    {
        grow(index*2);
        size = index + 1;
    }
    else if( index >= size )
    {
        size = index+1;
    }
    data[index] = o;
    return o;
}

template<E>
void Bag::grow()
{
    int new_capacity = (data.length * 3) / 2 + 1;
    grow(new_capacity);
}

template<E>
void Bag::grow(int new_capacity)
{
    E[] old_data = data;
    data = new E[new_capacity];

    for( int i=0; i<old_data.size; i++ )
    {
        data[i] = old_data[i];
    }

    delete[] old_data;
}

////////////////////

template<E>
void Bag::clear()
{
    for( int i=0; i < size; i++)
    {
        data[i] = null;
    }

    size = 0;
}

template<E>
void Bag::insert_all(Bag<E> items)
{
    for( int i=0; items.size() > i; i++ )
    {
        insert(items[i]);
    }
}
