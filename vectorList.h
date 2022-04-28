#ifndef VECTORLIST_H
#define VECTORLIST_H
#include "linkedList.h"

#include <iostream>
// #include <QDebug>

using namespace std;
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
        int size( ) const;
        E& at( unsigned index ) const;

        /***************
        ** MUTATORS **
        ***************/
        void push_back( E *list );;
        void resize( unsigned size );
};


/******************************
** CONSTRUCTORS **
******************************/
/****************************************************************
* VectorList();
*   Constructor; Initialize class attributes
*   size and capacity set to 0, dynamically create
*   an array and set data equal to the array
*   Parameters: none
*   Return: none
***************************************************************/
template <typename E>
VectorList<E>::VectorList()
{
    // qDebug() << "Default constructor has been calld\n";
    cout << "Default constructor has been calld" << std::endl;
    sz=0;
    cap=0;
    data = nullptr;
}
/****************************************************************
VectorList(const VectorList &D) || VectorList Class
  Copy Constructor - This is the copy constructor and copies each node from D to the new vectorlist
__________________________________________________
    Pre:
      copy has been properly initialzed
__________________________________________________
    Post:
        The new VectorList contains the same values in each node as copy
****************************************************************/
template <typename E>
VectorList<E>::VectorList(const VectorList<E> &copy)
{
    // qDebug() << "copy constructor has been calld\n";
    cout << "copy constructor has been calld\n" << std::endl;
    sz=copy.sz;
    cap=copy.cap;
    data = new E[cap];

    for(int i = 0; i < sz; i++)
    {
        data[i] = copy.data[i];
    }
}
/****************************************************************
operator=(const VectorList &D) || VectorList class
  Overloaded Assigmnet Operator - This is the overloaded assignment operator and copies each node from D into the VectorList
__________________________________________________
    Pre:
      copy has been properly initialized
__________________________________________________
    Post:
      List has copied each node. Head of list doesn't point to copy
****************************************************************/
template <typename E>
VectorList<E> VectorList<E>::operator=(const VectorList<E> &copy)
{
    // qDebug() << "Overloaded Assignment operator has been calld\n";
    cout << "Overloaded Assignment operator for vector list has been calld\n" << std::endl;
    if (this == &copy)
        return *this;
    if (sz!=0)
        delete [] data;
    sz=copy.sz;
    cap=copy.cap;

    data = new E[cap];

    for(int i = 0; i < sz; i++)
    {
        data[i] = copy.data[i];
    }
    return *this;

}
/***************
** DESTRUCTOR **
***************/
/****************************************************************
* ~IntVector()
*
*   Destructor; This method will deallocate all remaining
*   dynamically allocated memory
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: none
***************************************************************/
template <typename E>
VectorList<E>::~VectorList()
{
    sz=0;
    cap=0;
    delete [] data;
}

/***************
** ACCESSORS **
***************/
/****************************************************************
* unsigned size( )const;
*
*   Accessor; This method will return the size of the vector
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: unsigned
***************************************************************/
template <typename E>
int VectorList<E>::size( ) const
{
    return sz;
}

/****************************************************************
*   const int & at( unsigned index ) const
*
*   Accessor; This method will return the value of the vector
*   at the specified index
* --------------------------------------------------------------
*   Parameters: unsigned index
* --------------------------------------------------------------
*   Return: int
***************************************************************/
template <typename E>
E& VectorList<E>::at( unsigned index ) const
{
    if (index < sz)
    {
        return data[index];
    }
}

/***************
** MUTATORS **
***************/
/****************************************************************
*   void push_back(int value )
*
*   Mutator; This method will add VALUE to the end of the vector
* --------------------------------------------------------------
*   Parameters: int value
* --------------------------------------------------------------
*   Return: none
***************************************************************/
template <typename E>
void VectorList<E>::push_back( E *list )
{
    cout << "VECTOR LIST PUSH BACK CALLED" << endl;
    resize(++sz);
    if(sz>cap)
    {
        expand();
    }
   data[sz-1 ]= *list;
   cout << "finished push_back vector\n";

}
/****************************************************************
*   void resize(unsigned size)
*
*   Mutator; This method will resize the vector to contain
*   SIZE elements of value 0
* --------------------------------------------------------------
*   Parameters: unsigned size
* --------------------------------------------------------------
*   Return: none
***************************************************************/
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
/****************************************************************
*   void expand()
*
*   Mutator; This method will double the capacity of the vector
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: none
***************************************************************/
template <typename E>
void VectorList<E>::expand()
{
    if(cap==0)
    {
        cap=1;
        data = new E[cap];
        // need to allocate memory for data here
    }
    else
    {
        cout << "ran this\n";
        cap*=2;
        E *temp;
        temp = new E[cap];
        cout << "SIZE: " << sz << " CAP: " << cap << endl;
        for(int i = 0; i < sz-1;i++)
        {
            temp[i] = data[i];
        }
        delete [] data;
        data=temp;
        //delete [] temp;
        cout << "finished expand\n";
    }
}
/****************************************************************
*   void expand(unsigned amount)
*
*   Mutator; This method will increase the capacity of the vector
*   by AMOUNT passed in
* --------------------------------------------------------------
*   Parameters: unsigned amount
* --------------------------------------------------------------
*   Return: none
***************************************************************/
template <typename E>
void VectorList<E>::expand(int amount)
{
    cap+=amount;
    E* temp;
    temp = new E[cap];
    for(int i = 0; i < sz-1;i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = new E[cap];
    data = temp;
    delete [] temp;
}
#endif // VECTORLIST_H
