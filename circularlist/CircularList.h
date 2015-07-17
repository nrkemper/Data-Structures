#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#pragma once 

#include <iostream>
using namespace std;

template <class T> class CircularList;
template <class T> class Iterator;


//----NODE CLASS----
template <class T>
class Node {

private:
        Node<T>*	_next;
        T           _data{};

        Node();

public:
        void SetData(T data);
        void Print() const;
        friend ostream& operator<<(ostream& os, const Node<T>& n);
        friend istream& operator>>(istream& is, Node<T>& n);

        friend class CircularList<T>;
        friend class Iterator<T>;
};



//----CIRCULAR LIST CLASS----
template <class T>
class CircularList {
        
private:
        Node<T>*	_head;
        int         _size;

public:

        CircularList();
        CircularList(const CircularList<T>& src);
        void Append(T data);
        void Push(T data);
        int Pop();
        int Remove(int i);
        int GetSize() const;
        void Print() const;
        CircularList<T>& operator=(const CircularList<T>& rhs);
        T& operator[](const int i);
        ~CircularList();

        friend class Iterator<T>;
};


//----ITERATOR CLASS----
template <class T>
class Iterator {

private:
        Node<T>*	_head, *_cur;
        int         _size;

public:
        Iterator();
        Iterator(const CircularList<T> c);
        int GoNext();
        int GoHead();
        T GetData() const;
        int GetSize() const;
        Iterator operator=(const CircularList<T>& rhs);

};




//----OVERLOADED OPERATORS----
template <class T> istream& operator>> (istream& is, CircularList<T>& cl);
template <class T> CircularList<T>& operator>> (T data, CircularList<T>& cl);
template <class T> ostream& operator<< (ostream& os, const CircularList<T>& cl);

//----NODE CLASS----
template <class T>
Node<T> :: Node()
{
        _next = (Node<T>*)0;
}

template <class T>
void Node<T> :: SetData(T data)
{
        _data = data;
}

template <class T>
void Node<T> :: Print() const
{
        cout << _data << endl;
}

template <class T>
ostream& operator<< (ostream& os, const Node<T>& n)
{
        return os << n._data << endl;
}

template <class T>
istream& operator>> (istream& is, Node<T>& n)
{
        return is >> n._coefficient >> n._exponent;
}



//----CIRCULAR LIST CLASS----
template <class T>
CircularList<T>::CircularList()
{
        _head = (Node<T>*)0;
        _size = 0;
}

template <class T>
CircularList<T>::CircularList(const CircularList<T>& src)
{
        if (this != &src)
                *this = src;
}

template <class T>
void CircularList<T>::Append(T data)
{
        Node<T>*    newNode = new Node<T>, *p;
        
        newNode->_data = data;
        newNode->_next = (Node<T>*)0;
        
        if (_head)
        {
                //if there are nodes in the list
                
                int i;
                
                for (i=0, p=_head ; i<_size-1 ; p=p->_next, i++);//points "p" to last node in list
                
                p->_next = newNode;
                newNode->_next = _head;
        }
        else
        {
                //if the list is empty
                
                _head = newNode;
                _head->_next = _head;
        }
        
        _size++;
        
}

template <class T>
void CircularList<T>::Push(T data)
{
        
        Node<T>* newNode = new Node<T>, *p;
        
        newNode->_data = data;
        newNode->_next = (Node<T>*)0;
        
        if (_head)
        {
                newNode->_next = _head;
                _head = newNode;
        }
        else
        {
                int     i;
                
                _head = newNode;
                _head->_next = _head;
                
                for (i=0, p=_head ; i<_size ; p=p->_next, i++); //points "p" to last node in list
                
                p->_next = _head;//points the last node's next to head to make the list circular
        }
        
        _size++;
}

template <class T>
int CircularList<T>::Pop()
{
        Node<T>         *toDel = NULL, *p;
        int             success=1;
        
        if (_size > 1)
        {
                int i;
                
                toDel = _head;			//makes head's next the new head
                _head = _head->_next;
                
                for (i=0, p=_head; i<_size-1 ; p=p->_next, i++); //points "p" to last node in list
                
                p->_next = _head;//sets last node in list to "head" to maintain a circular list
        }
        else if (_size == 1)
        {
                toDel = _head;
                _head = (Node<T>*)0;
        }
        else
        {
                success = 0;
        }
        
        if (success)
        {
                delete toDel;
                _size--;
        }
        
        return success;
}

template <class T>
int CircularList<T>::Remove(int i)
{
        int             success=1, x;
        Node<T>*        toDel = NULL,  *p;
        
        if (_size>1 && i>0 && i<_size-1)
        {
                //node is in the middle
                for (x=0 , p=_head ; x<i-1 ; x++, p=p->_next);
                
                toDel = p->_next;
                
                p->_next = p->_next->_next;
                
                delete toDel;
        }
        else if (i==0 && _size>1)
        {
                //node is at head
                toDel = _head;
                
                _head = _head->_next;
                
                for (x=0, p=_head ; x<_size-1 ; x++, p=p->_next);
                
                p->_next = _head;
        }
        else if (i==_size-1 && _size>1)
        {
                //node is at tail
                for (x=0 , p=_head ; x<i-1 ; x++, p=p->_next);
                
                toDel = p->_next;
                
                p->_next = _head;
        }
        else if (_size==1)
        {
                //there is one node
                toDel = _head;
                _head = (Node<T>*)0;
        }
        else
        {
                success = 0;
        }
        
        if (success)
        {
                delete toDel;
                _size--;
        }
        
        return success;
}

template <class T>
int CircularList<T> :: GetSize () const
{
        return _size;
}

template <class T>
void CircularList<T>::Print() const
{
        int			i;
        Node<T>*	p;
        
        for (i=0, p=_head ; i<_size ; p=p->_next, i++)
        {
                cout << p->_data;
                
                if (i<_size-1)
                        cout << " ";
        }
        
        cout << endl;
}

template <class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& rhs)
{
        int         i;
        Node<T>     newNode, *p;
        
        for (i=0, p=rhs._head ; i<rhs._size ; p=p->_next, i++)
        {
                newNode._coefficient = p->_coefficient;
                newNode._exponent = p->_exponent;
                Append(newNode);
        }
        
        return *this;
}

template <class T>
T& CircularList<T>::operator[](const int i)
{
        int         n;
        Node<T>     *p;
        
        for (n=0, p=_head ; n<i ; n++, p=p->_next);
        
        return p->_data;
}

template <class T>
CircularList<T>::~CircularList()
{
        while (_head)
                Pop();
}



//----ITERATOR CLASS----
template <class T>
Iterator<T>::Iterator()
{
        _head = _cur = (Node<T>*)0;
        _size = 0;
}

template <class T>
Iterator<T>::Iterator(const CircularList<T> c)
{
        _head = _head = c._head;
        _size = c._size;
}

template <class T>
int Iterator<T>::GoNext()
{
        int success = 1;
        
        if (_cur)
                _cur = _cur->_next;
        else
                success = 0;
        
        return success;
}

template <class T>
int Iterator<T>::GoHead()
{
        int success=1;
        
        if (_head)
                _cur = _head;
        else
                success = 0;
        
        return success;
}

template <class T>
T Iterator<T>::GetData() const
{
        return _cur->_data;
}

template <class T>
int Iterator<T>::GetSize() const
{
        return _size;
}

template <class T>
Iterator<T> Iterator<T>::operator=(const CircularList<T>& rhs)
{
        _cur = _head = rhs._head;
        _size = rhs._size;
        
        return *this;
}







//----OVERLOADED FUNCTIONS----
template <class T>
CircularList<T>& operator>>(T data, CircularList<T>& cl)
{
        cl.Append (data);
        return cl;
}


template <class T>
istream& operator>>(istream& is, CircularList<T>& cl)
{
        T       data;
        
        is >> data;
        cl.Append (data);
        
        return is;
}


template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& cl)
{
        Iterator<T>     i;
        int             x, size;
        
        for (i=cl, x=0, size=i.GetSize() ; x<size ; x++)
                os << i.GetData();
        
        return os;
}



#endif
