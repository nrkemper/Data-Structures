#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#pragma once 

#include <iostream>
using namespace std;

template <class T>
class CircularList;

template <class T>
class Iterator;


/******************
 *   Node Class   *
 ******************/
template <class T>
class Node {

private:
	Node<T>*	_next;
	T		_data; 

	Node();

public:

	void SetData(T data);
	void Print() const;
	friend ostream& operator<<(ostream& os, const Node<T>& n);
	friend istream& operator>>(istream& is, Node<T>& n);

	friend class CircularList<T>;
	friend class Iterator<T>;
};



/***************************
 *   Circular List Class   *
 ***************************/
template <class T>
class CircularList {

private:
	Node<T>*	_head;
	int		_size;

public:

	CircularList();
	CircularList(const CircularList<T>& src);
	void Append(Node<T> n);
	void Push(Node<T> n);
	void Pop();
	int GetSize() const;
	void Print() const;
	CircularList<T>& operator=(const CircularList<T>& rhs);
	T& operator[](const int i);
	~CircularList();

	friend class Iterator<T>;
};


/**********************
 *   Iterator Class   *
 **********************/
template <class T>
class Iterator {

private:
	Node<T>*	_head, *_cur;
	int		_size;

public:
	Iterator();
	Iterator(const CircularList<T> c);
	int GoNext();
	int GoHead();
	T GetData() const;
	int GetSize() const;
	Iterator& operator=(const CircularList<T>& rhs);

};




/****************************
 *   Overloaded Operators   *
 ****************************/

template <class T>
CircularList<T>& operator>>(const Node<T>& lhs, CircularList<T>& rhs);
template <class T>
istream& operator>>(istream& is, CircularList<T>& cl);
template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& cl);









/*************************************
 *                                   *
 *
 *       Function Declarations       *
 *                                   *
 *                                   *
 *************************************/




/******************
*   Node Class   *
******************/
template <class T>
Node<T>::Node() {
	_data = (T)0;
	_next = (Node<T>*)0;
}

template <class T>
void Node<T>::SetData(T data) {
	_data = data;
}

template <class T>
void Node<T>::Print() const {
	cout << _data << endl;
}

template <class T>
ostream& operator<<(ostream& os, const Node<T>& n) {
	return os << _data << endl;
}

template <class T>
istream& operator>>(istream& is, Node<T>& n) {
	return is >> n._coefficient >> n._exponent;
}



/***************************
*   Circular List Class   *
***************************/
template <class T>
CircularList<T>::CircularList() {
	_head = (Node<T>*)0;
	_size = 0;
}

template <class T>
CircularList<T>::CircularList(const CircularList<T>& src) {
	if (this != &src) {
		*this = src;
	}
}

template <class T>
void CircularList<T>::Append(Node<T> n) {

	Node<T>* newNode = new Node<T>, *p;

	newNode->_data = n._data;
	newNode->_next = (Node<T>*)0;

	if (_head) {

		//if there are nodes in the list

		int i;


		for (i = 0, p = _head; i < _size - 1; p = p->_next, i++);//points "p" to last node in list

		p->_next = newNode;
		newNode->_next = _head;

	}
	else {

		//if the list is empty

		_head = newNode;
		_head->_next = _head;

	}

	_size++;

}

template <class T>
void CircularList<T>::Push(Node<T> n) {

	Node<T>* newNode = new Node<T>, *p;

	newNode->_data = n._data;
	newNode->_next = (Node<T>*)0;

	if (_head) {

		newNode->_next = _head;
		_head = newNode;

	}
	else {

		int i;

		_head = newNode;
		_head->_next = _head;

		for (i = 0, p = _head; i < _size; p = p->_next, i++); //points "p" to last node in list

		p->_next = _head;//points the last node's next to head to make the list circular

	}

	_size++;

}

template <class T>
void CircularList<T>::Pop() {

	Node<T>* toDel, *p;

	if (_size > 1) {
		int i;

		toDel = _head;			//makes head's next the new head
		_head = _head->_next;

		_size--;

		for (i = 0, p = _head; i < _size - 1; p = p->_next, i++); //points "p" to last node in list

		p->_next = _head;//sets last node in list to "head" to maintain a circular list

		delete toDel;
	}
	else if (_size == 1) {
		toDel = _head;
		_head = (Node<T>*)0;

		delete toDel;

		_size--;
	}
}

template <class T>
int CircularList<T>::GetSize() const {
	return _size;
}

template <class T>
void CircularList<T>::Print() const{
	int			i;
	Node<T>*	p;

	for (i = 0, p = _head; i < _size; p = p->_next, i++) {
		cout << *p;
	}
}

template <class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& rhs) {
	int		i;
	Node<T>	newNode, *p;

	for (i = 0, p = rhs._head; i < rhs._size; p = p->_next, i++) {
		newNode._coefficient = p->_coefficient;
		newNode._exponent = p->_exponent;
		Append(newNode);
	}

	return *this;
}

template <class T>
T& operator[](const int i){
	int n;
	Node<T>* p;

	for( n=0, p=_head; n<i; n++, p=p->_next );
	
	return p->_data;	
}

template <class T>
CircularList<T>::~CircularList() {
	while (_head) {
		Pop();
	}
}



/**********************
*   Iterator Class   *
**********************/
template <class T>
Iterator<T>::Iterator() {
	_head = _cur = (Node<T>*)0;
	_size = 0;
}

template <class T>
Iterator<T>::Iterator(const CircularList<T> c) {
	_head = _head = c._head;
	_size = c._size;
}

template <class T>
int Iterator<T>::GoNext() {

	int success = 1;

	if (_cur) {
		_cur = _cur->_next;
	}
	else {
		success = 0;
	}

	return success;
}

template <class T>
int Iterator<T>::GoHead() {

	int success = 1;

	if (_head) {
		_cur = _head;
	}
	else {
		success = 0;
	}

	return success;
}

template <class T>
T Iterator<T>::GetData() const {
	return _data;
}

template <class T>
int Iterator<T>::GetSize() const {
	return _size;
}

template <class T>
Iterator<T>& Iterator<T>::operator=(const CircularList<T>& rhs) {
	_cur = _head = rhs._head;
	_size = rhs._size;
	return *this;
}







/****************************
*   Overloaded Operators   *
****************************/

//TODO decide if I want to make ALL overloaded functions friend functions for consistency and to get rid of Iterator class definition within them
//adds a node to a CircularList via >> operator
template <class T>
CircularList<T>& operator>>(const Node<T>& lhs, CircularList<T>& rhs) {
	rhs.Append(lhs);
	return rhs;
}


//TODO fix this... not working properly. Going to work on more exciting things :)
template <class T>
istream& operator>>(istream& is, CircularList<T>& cl) {
	int		coefficient, exponent;
	Node<T>	newNode;

	is >> coefficient >> exponent >> newNode;

	cl.Append(newNode);

	return is;
}

//outputs the content of the linked list via << operator
template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& cl) {

	int		x, size;
	Iterator<T>	i;

	i = cl;

	size = i.GetSize();

	for (x = 0; x < size; x++) {
		os << i.GetData();
		i.GoNext();
	}
	return os;
}

#endif
