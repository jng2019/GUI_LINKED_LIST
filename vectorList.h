#ifndef VECTORLIST_H
#define VECTORLIST_H
#include "linkedList.h"

template <typename E>
class VectorList
{
    private:
        unsigned cap;   //IN/OUT - capacity of vector
        unsigned sz;    //IN/OUT - size of vector
        LinkedList<E> *data;      //IN/OUT - points to memory address of dynamically created array

        void expand();
    public:

        /***************
        ** CONSTRUCTORS **
        ***************/
        VectorList();        //CONSTRUCTOR


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
        const LinkedList<E> & at( unsigned index ) const;

        /***************
        ** MUTATORS **
        ***************/
        void push_back( LinkedList<E> &list );
        void pop_back( );
        void clear( );
        void resize( unsigned size );
};

template <typename E>
void VectorList<E>::expand()
{
    if(cap==0)
        cap=1;
    else
        cap*=2;
    VectorList<E> temp;
    for(int i = 0; i < sz;i++)
    {
        temp.push_back(data[i]);
    }
    delete data;
    data = new LinkedList<E>[cap];
    data = temp.data;
}

template <typename E>
VectorList<E>::VectorList()
{
    sz=0;
    cap=0;
    data = new LinkedList<E>[0];
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
const LinkedList<E>& VectorList<E>::at( unsigned index ) const
{
    if (index < sz)
        return data[index];
}

/***************
** MUTATORS **
***************/
template <typename E>
void VectorList<E>::push_back( LinkedList<E> &list )
{
    resize(++sz);
    if(sz>cap)
        expand();
   data[sz-1]=list;
}
void pop_back( );
void clear( );
template <typename E>
void VectorList<E>::resize( unsigned size )
{
    unsigned oldSize=sz;
    sz = size;
    if(sz>cap)
    {
        if(sz*2>size-cap)
            expand();
        else
            expand(size-cap);
    }

}
#endif // VECTORLIST_H
