#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "listEmpty.h"

using namespace std;
/***************************************************
* AUTHOR   : Jonathan Ng
* Assignment 9   : Template linked list and exceptions
* CLASS    : CS003A
* SECTION  : 31195
* DUE DATE : April 18, 2022
****************************************************/
template<typename E>
struct Node{
    E data;
    Node *next;
    Node( E data ) : data(data), next(0) {}
};

template<typename E>
class LinkedList
{

private:
    Node<E> *head;  //IN/OUT - front of the list
    Node<E> *tail;  //IN/OUT - end of the list
public:

    class Iterator
    {
    private:
        Node<E> *current;
    public:
        /******************
        ** CONSTRUCTORS **
        ******************/
        /****************************************************************
           ListIterator
             Creates an ListIterator that points to NULL
        ****************************************************************/
        Iterator();
        /****************************************************************
        ListIterator(Node *ptr)
        Creates an ListIterator that points to ptr
        ****************************************************************/
        Iterator(Node<E> *ptr);
        /******************
        ** ACCESSORS **
        ******************/
        /****************************************************************
        operator*
        This returns the value of the node current is pointing at
        ****************************************************************/
        E operator*();
        /****************************************************************
        operator==
        This returns true if two ListIterators are pointing at the same thing
        ****************************************************************/
        bool operator==(const E &right) const;
        /****************************************************************
        operator!=
        This returns true if two ListIterators are NOT pointing at the same thing
        ****************************************************************/
        bool operator!=(Iterator right) const;
        /******************
         ** MUTATORS **
         ******************/
        /****************************************************************
        operator++
        This returns an ListIterator pointing at the next node in the list
        ****************************************************************/
        Iterator operator++();
    };
        /******************
        ** CONSTRUCTORS **
        ******************/

        /****************************************************************
        LinkedList
          Creates a list of 0 items. Sets head and tail to null
        ****************************************************************/
        LinkedList();
        /****************************************************************
        List
          D - DoubleLinkedList to be copied

          This creates a new list that is a deep copy of the given list.
        ****************************************************************/
        LinkedList(const LinkedList& source);

        /***************
        ** DESTRUCTOR **
        ***************/

        /****************************************************************
        ~LinkedList
          Destroys linked list by deleting any memory and setting head and tail to null
        ****************************************************************/
        ~LinkedList();
        /*****************
        *** MUTATORS *****
        *****************/
        /****************************************************************
        operator=
          D - LinkedList to be copied

          This assigns the values of the nodes in the given list to "this" list. If the current list is not empty then the list is cleared before copying over the other list.
        ****************************************************************/
        LinkedList& operator=( const LinkedList& source );
        /****************************************************************
        push_front
            value - value of the new node inserted at beginning of list

        This adds a node at the beginning of list. Head points to the new node.
        If the new node is the firt node, then tail will also point to new node.
        ****************************************************************/
        void push_front( const E& value );
        /****************************************************************
        push_back
            value - integer value to be added to list

        This adds a new node at the end of the list. Tail points to the new node. If the new node is the first node then head will also point to new node
        ****************************************************************/
        void push_back( const E& value );
        /****************************************************************
        pop_front
          This removes the node at the front of the list. Head will
          point to the next node in the list.
          If the list is empty, then nothing is changed.
        ****************************************************************/
        void pop_front() ;//throw(ListEmpty);
        /****************************************************************
        clear
          This deallocates each node
        ****************************************************************/
        void clear();
        /****************************************************************
        sort
          This sorts the list into ascending order
        ****************************************************************/
        void select_sort();
        /****************************************************************
        insert_sorted
            value - integer value to be added to list

        This adds a new node to a sorted list. It will insert new node at the appropriate position so the list is still in ascending order
        ****************************************************************/
        void insert_sorted( const E& value );
        /****************************************************************
        remove
            value - integer value to be removed from                  the list

        This removes the first instance of an int value from the list. If that value can still be found in the list, true is returned, if not false is returned
        ****************************************************************/
        void remove_duplicates();
        /*****************
        ** ACCESSORS *****
        *****************/
        /****************************************************************
        display
          forward - indicates which direction list should be displayed, forwoard or reversed

          Prints the values of each 'Node' in the LinkedList. Default order is forward, but can be changed to reversed order
        ****************************************************************/
        void display() const;
        /****************************************************************
        begin
          This returns an iterator pointing to the first node
        ****************************************************************/
        Iterator begin();
        /****************************************************************
        end
          This returns an iterator pointing to nullptr
        ****************************************************************/
        Iterator end();
        /****************************************************************
        front
          This returns the value stored in the first node
        ****************************************************************/
        const E& front() const ;//throw(ListEmpty);
        /****************************************************************
        back
          This returns an the value stored in the last node
        ****************************************************************/
        const E& back() const ;//throw(ListEmpty);
        /****************************************************************
        length
          This returns the number of nodes there are in the list
        ****************************************************************/
        int length() const;
        /****************************************************************
        sum
          This returns the sum of the nodes
        ****************************************************************/
        int sum() const;
        /****************************************************************
        isEmpty
        This returns if the list is empty
        ****************************************************************/
        bool isEmpty() const;

        string getString() const;

};

/*************************************************
  ListIterator   | ListIterator Class
    This sets Node pointer 'current' to null
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      ListIterator points to nullptr
*************************************************/
template <typename E>
LinkedList<E>::Iterator::Iterator()
{
    current = nullptr;
}

/*************************************************
  ListIterator   | ListIterator Class
    ptr - Node pointer that 'current' will be set to

    This sets Node pointer 'current' to given pointer
__________________________________________________
    Pre:
      ptr is part of a LinkedList
__________________________________________________
    Post:
      ListIterator is set to passed Node pointer
*************************************************/
template <typename E>
LinkedList<E>::Iterator::Iterator(Node<E> *ptr)
{
    current = ptr;
}

/*************************************************
  operator*   | ListIterator Class

    This returns the int value stored in 'current'
__________________________________________________
    Pre:
      current isn't null
__________________________________________________
    Post:
      data stored in current is returned
*************************************************/
template <typename E>
E LinkedList<E>::Iterator::operator*()
{
    return current->data;
}

/*************************************************
  operator==   | ListIterator Class
    right - iterator to be compared

    This compares the two iterators to see if they are equal.
__________________________________________________
    Pre:
      right is an ListIterator.
__________________________________________________
    Post:
      Returns true if two iterators point to the same value, returns false if they don't
*************************************************/
template <typename E>
bool LinkedList<E>::Iterator::operator==(const E &right) const
{
    // If both of the nodes are null
    if(right.current == nullptr && current == nullptr)
        return true;
    // If either of the nodes are null
    if(right.current == nullptr || current == nullptr)
        return false;
    // If the int values in nodes are equal
    if(right.current->data == current->data)
        return true;
    return false;
}

/*************************************************
  operator==   | ListIterator Class
    right - iterator to be compared

    This compares the two iterators to see if they are not equal.
__________________________________________________
    Pre:
      right is an ListIterator
__________________________________________________
    Post:
      Returns true if two iterators don't point to the same value, returns false if they do
*************************************************/
template <typename E>
bool LinkedList<E>::Iterator::operator!=(LinkedList<E>::Iterator right) const
{
    return current!=right.current;
}

/*************************************************
  operator++   | ListIterator Class

    This sets iterator to the next node in the list
__________________________________________________
    Pre:
      current isn't null and is a part of a LinkedList
__________________________________________________
    Post:
      current points to next node in list
*************************************************/
template <typename E> typename LinkedList<E>::Iterator
LinkedList<E>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

/****************************************************************
DoublyLinkedList || DoublyLinkedList Class
  Constructor - This is the default constructor and creates an empty linked list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      Head and tail point to nullptr
****************************************************************/
template <typename E>
LinkedList<E>::LinkedList(): head(nullptr), tail(nullptr){}


/****************************************************************
DoublyLinkedList(const DoublyLinkedList &D) || DoublyLinkedList Class
  Copy Constructor - This is the copy constructor and copies each node from D to the new doubly linked list
__________________________________________________
    Pre:
      D has been properly initialzed
__________________________________________________
    Post:
        The new DoublyLinkedList contains the same values in each node as D
****************************************************************/
template <typename E>
LinkedList<E>::LinkedList(const LinkedList& source)
{

    head = nullptr;
    tail = nullptr;
    Node<E> *current;
    current = source.head;
    while (current!=nullptr)
    {
        push_back(current->data);
        current = current->next;
    }
}

/****************************************************************
~DoublyLinkedList() || DoublyLinkedList Class
  Destructor - This is the destructor and deallocates each node in the linked list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      Each node in the list has been destroyed and head and tail are set to nullptr
****************************************************************/
template <typename E>
LinkedList<E>::~LinkedList()
{
    while (head != nullptr && tail != nullptr)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

/****************************************************************
operator=(const DoublyLinkedList &D) || DoublyLinkedList class
  Overloaded Assigmnet Operator - This is the overloaded assignment operator and copies each node from D into the doubly linked list
__________________________________________________
    Pre:
      D has been properly initialized
__________________________________________________
    Post:
      List has copied each node. Head of list doesn't point to D.head
****************************************************************/
template <typename E>
LinkedList<E> & LinkedList<E>::operator=( const LinkedList& source )
{
    Node<E> *current;
    // If the lists are the same
    if(this == &source)
        return *this;
    // If this list is not empty
    if (head != nullptr)
    {
        while(head != nullptr)
            this->pop_front();
    }


    current = source.head;
    // Copies over values from D list
    while(current != nullptr)
    {
        this->push_back(current->data);
        current = current->next;
    }

    return *this;
}

/****************************************************************
display(bool forward) || DoublyLinkedList Class
  ACCESSOR - This functions displays the value of each node forward or backwards depending on paramter
__________________________________________________
    Pre:
      list has predefined values
__________________________________________________
    Post:
      list is printed to the console
****************************************************************/
template <typename E>
void LinkedList<E>::display() const
{
    Node<E> *current;
    current = head;
    // displays node values
    while(current != nullptr)
    {
        cout << current->data;
        current = current->next;
        if(current != nullptr)
            cout << " ";
    }
}

/****************************************************************
push_front() || DoublyLinkedList class
  MUTATOR - This function adds a new node to the front of the doubly linked list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      head points to the new node, newNode points to the old head
****************************************************************/
template <typename E>
void LinkedList<E>::push_front(const E& value)
{
    Node<E> *newNode;     // IN - node to be added
    newNode = new Node<E>(value);

    // If there are no nodes in list
    if(head == nullptr)
    {
        newNode->next = nullptr;
        // Both head an tail point to new node
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Inserts new node in the first spot
        newNode->next = head;
        head = newNode;
    }
}

/****************************************************************
push_back() || DoublyLinkedList class
  MUTATOR - This function adds a new node to the end of the doubly linked list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      tail points to the new node, newNode prev points to the old tail
****************************************************************/
template <typename E>
void LinkedList<E>::push_back( const E& value )
{
    Node<E> *newNode;    // IN - node to be added
    newNode = new Node<E>(value);

    // If there are no nodes in list
    if(head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        // new node is added to last pos in list
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }
}

/****************************************************************
pop_front() || DoublyLinkedList Class
  MUTATOR - This function removes the first node in the doubly linked list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      head points to second element in list, size of list decreae by 1
****************************************************************/
template <typename E>
void LinkedList<E>::pop_front() //throw(ListEmpty)
{
    Node<E> *current;    // node to be removed

    current = head;

    try
    {
        if(head==nullptr)
            throw ListEmpty();
        // if last node is to be removed
        else if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            delete current;
        }
    }
    catch (ListEmpty LE)
    {
        cout << LE.what() << endl;
    }
}

/****************************************************************
front() || DoublyLinkedList class
ACCESSOR - This functions returns an int value of the first node in the list
__________________________________________________
    Pre:
      head!=nullptr
__________________________________________________
    Post:
        None
****************************************************************/
template <typename E>
const E& LinkedList<E>::front() const //throw(ListEmpty)
{
    try{
        if (head==nullptr)
            throw ListEmpty();
        return head->data;
    }
    catch (ListEmpty LE)
    {
        cout << LE.what() << endl;
    }
}

/****************************************************************
back() || DoublyLInkedList class
ACCESSOR - This functions returns an int value of the last node in the list
__________________________________________________
    Pre:
      tail!=nullptr
__________________________________________________
    Post:
        None
****************************************************************/
template <typename E>
const E& LinkedList<E>::back() const //throw(ListEmpty)
{
    try{
        if (tail==nullptr)
            throw ListEmpty();
        return tail->data;
    }
    catch (ListEmpty LE)
    {
        cout << LE.what() << endl;
    }
}

template <typename E>
void LinkedList<E>::clear()
{
    Node<E> *current;
    current = head;
    while (current!=nullptr)
        pop_front();
    head=nullptr;
    tail=nullptr;
}

/****************************************************************
select_sort() || DoublyLinkedList class
MUTATOR - This function sorts the list in ascending order
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
      elements of list are sorted in ascending order
****************************************************************/
template <typename E>
void LinkedList<E>::select_sort()
{
    Node<E> *curr(head);   // Traverses through list
    Node<E> *next;         // Traverses through list
    Node<E> *low;         // Saves spot of lowest                              node
    E temp;              // Used to swap values

    while(curr != nullptr)
    {
        // Lowest is set to curr
        next = curr->next;
        low = curr;

        // search through rest of list to find a             a lower value node
        while(next != nullptr)
        {
            // low is set to lowest value found
            if(next->data < low->data)
                low = next;
            // traverses through list
            next = next->next;
        }

        // If low was changed, values are swapped
        if(low->data != curr->data)
        {
            temp = curr->data;
            curr->data = low->data;
            low->data = temp;
        }

        // traverses through list
        curr = curr->next;
    }
}

/****************************************************************
insert_sorted(int value) || DoublyLinkedList
MUTATOR - This function assumes the list is already sorted and will insert VALUE into the appropriate location so the list will remain sorted
__________________________________________________
    Pre:
      List is not empty and is sorted
__________________________________________________
    Post:
      size of list increased by 1, list is still sorted
****************************************************************/
template <typename E>
void LinkedList<E>::insert_sorted( const E& value )
{
    Node<E> * newNode = new Node<E>(value);
    Node<E> * curr = head;
    Node<E> * prev = nullptr;

    while(curr != nullptr && curr->data < newNode -> data)
    {
        prev = curr;
        curr = curr -> next;
    }

//Insert the node
//into the list.

    if(prev == nullptr)
    {
        newNode -> next = curr;
        head = newNode;
    }
    else {
        prev->next = newNode;
        newNode->next = curr;
    }
    if(curr == nullptr)
    {
        tail = newNode;
    }
}

/****************************************************************
remove(int value) || DoublyLinkedList class
MUTATOR - This functions finds the first instance of the node that contains VALUE and will remove the node
__________________________________________________
    Pre:
      Value exists in the list
__________________________________________________
    Post:
      size of list decreaed by 1
****************************************************************/
template <typename E>
void LinkedList<E>::remove_duplicates()
{
    Node<E> * i_node = head;
    if(i_node != nullptr)
    {
        while(i_node ->next != nullptr)
        {
            Node<E> * j_node = i_node -> next;
            Node<E> * temp = i_node;
            while(j_node != nullptr)
            {
                if(j_node -> data == i_node -> data)
                {
                    temp -> next = j_node -> next;
                }else
                {
                    temp = j_node;
                }
                j_node = j_node -> next;

            }
            i_node = i_node -> next;
            if(i_node == nullptr)
            {
                break;
            }
        }
    }
}

/****************************************************************
begin() || DoublyLinkedList class
ACCESSOR - This functions returns an IntListIterator that points to the first node of the list
__________________________________________________
    Pre:
      head != nullptr
__________________________________________________
    Post:
        None
****************************************************************/
template <typename E> typename LinkedList<E>::Iterator
LinkedList<E>::begin()
{
    return (head);
}


/****************************************************************
end() || DoublyLinkedList class
ACCESSOR - This functions returns an IntListIterator that points to one past the last node of the list
__________________________________________________
    Pre:
      tail!=nullptr
__________________________________________________
    Post:
        None
****************************************************************/
template <typename E> typename LinkedList<E>::Iterator
LinkedList<E>::end()
{
    return (tail);
}

/****************************************************************
length() || DoublyLinkedLst
ACCESSOR - This functions returns how many nodes are in the list
__________________________________________________
    Pre:
      None
__________________________________________________
    Post:
        None
****************************************************************/
template <typename E>
int LinkedList<E>::length() const
{
    int count=0;
    Node<E> *current;
    current = head;
    while (current!=nullptr)
    {
        count++;
        current=current->next;
    }
    return count;
}

template <typename E>
int LinkedList<E>::sum() const
{
    int sum=0;
    Node<E> *current;
    current = head;
    while (current!=nullptr)
    {
        sum+=current->data;
        current=current->next;
    }
    return sum;
}

template <typename E>
bool LinkedList<E>::isEmpty() const
{
    return (head==nullptr);
}

template <typename E>
string LinkedList<E>::getString() const
{
    string output;
    Node<E> *current;
    current = head;
    while (current!=nullptr)
    {
        output+=to_string(current->data);
        current = current->next;
    }
    return output;
}

#endif // LINKEDLIST_H
