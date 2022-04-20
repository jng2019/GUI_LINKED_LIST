#ifndef VECTORLIST_H
#define VECTORLIST_H
#include "linkedList.h"

#include <iostream>

template <typename E>
class VectorList
{
    private:
        unsigned cap;   //IN/OUT - capacity of vector
        unsigned sz;    //IN/OUT - size of vector
        E *data;      //IN/OUT - points to memory address of dynamically created array

        void expand();
        void expand(int amount);
    public:

        /***************
        ** CONSTRUCTORS **
        ***************/
        VectorList();        //CONSTRUCTOR

        VectorList(const VectorList<E> &copy);
        VectorList<E> operator=(const VectorList<E> &copy);

        /***************
        ** DESTRUCTOR **
        ***************/
        ~VectorList();

        /***************
        ** ACCESSORS **
        ***************/
        unsigned size( ) const;
        unsigned capacity( ) const;
        bool empty( ) const;
        E& at( unsigned index ) const;

        /***************
        ** MUTATORS **
        ***************/
        void push_back( E &list );
        void pop_back( );
        void clear( );
        void resize( unsigned size );
};



template <typename E>
VectorList<E>::VectorList()
{
    sz=0;
    cap=0;
    data = nullptr;
}

template <typename E>
VectorList<E>::VectorList(const VectorList<E> &copy)
{
    cout << "copy constructor has been calld\n";
    sz=copy.sz;
    cap=copy.cap;

    for(int i = 0; i < sz; i++)
    {
        data[i] = copy.data[i];
    }
}

template <typename E>
VectorList<E> VectorList<E>::operator=(const VectorList<E> &copy)
{
    if (this == &copy)
        return *this;
    if (sz!=0)
        delete data;
    sz=copy.sz;
    cap=copy.cap;

    for(int i = 0; i < sz; i++)
    {
        data[i] = copy.data[i];
    }
    return *this;

}

template <typename E>
VectorList<E>::~VectorList()
{
    sz=0;
    cap=0;
    delete data;
}

/***************
** ACCESSORS **
***************/
template <typename E>
unsigned VectorList<E>::size( ) const
{
    return sz;
}

template <typename E>
unsigned VectorList<E>::capacity() const
{
    return cap;
}

template <typename E>
bool VectorList<E>::empty() const
{
    return sz==0;
}

template <typename E>
E& VectorList<E>::at( unsigned index ) const
{
    if (index < sz)
        return data[index];
}

/***************
** MUTATORS **
***************/
template <typename E>
void VectorList<E>::push_back( E &list )
{
    resize(++sz);
    if(sz>cap)
        expand();
    std::cout << "size: " << sz;
   data[0]=list;
}

template <typename E>
void VectorList<E>::pop_back( )
{

}

template <typename E>
void VectorList<E>::clear( )
{

}
template <typename E>
void VectorList<E>::resize( unsigned size )
{
    sz = size;
    if(sz>cap)
    {
        if(sz*2>size-cap)
            expand();
        else
            expand(size-cap);
    }
}

template <typename E>
void VectorList<E>::expand()
{
    if(cap==0)
        cap=1;
    else
    {
        cap*=2;
        VectorList<E> temp;
        data = new
        for(int i = 0; i < sz;i++)
        {
            temp.push_back(data[i]);
        }
        delete data;
        data = new E[cap];
        data = temp.data;
    }
}

template <typename E>
void VectorList<E>::expand(int amount)
{
    cap+=amount;
    VectorList<E> temp;
    for(int i = 0; i < sz;i++)
    {
        temp.push_back(data[i]);
    }
    delete data;
    data = new E[cap];
    data = temp.data;
}
#endif // VECTORLIST_H
