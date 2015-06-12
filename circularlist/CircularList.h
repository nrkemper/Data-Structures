#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#include <iostream>
using namespace std;

#pragma once 

class CircularList;
class Iterator;

//template <class T>


/*---Node Class---*/
class Node {

private:
	int		_coefficient, _exponent;
	Node*	_next;
	//T _data; 
	// TODO implement templating

public:

	Node() {
		_coefficient = _exponent = 0;
		_next = (Node*)0;
	}

	void SetCoefficient(int n) {
		_coefficient = n;
	}

	void SetExponent(int n) {
		_exponent = n;
	}


	void Print() const {
	
	}

	friend ostream& operator<<(ostream& os, const Node& n) {
		return os << "Coefficient: " << n._coefficient << endl << "Exponent: " << n._exponent << endl << endl;
	}

	//TODO want to be able to read in two ints from input stream and set them to exponent and coeff
	friend istream& operator>>(istream& is, Node& n) {
		return is >> n._coefficient >> n._exponent;
	}

	friend ostream& operator<<(ostream& os, const CircularList& cl);// TODO TAKE THIS OUT IF POSSIBLE
	friend class CircularList;
};



/*---Circular List Class---*/
class CircularList {

private:
	Node*	_head;
	int		_size;

public:
	
	CircularList() {
		_head = (Node*)0;
		_size = 0;
	}

	CircularList(const CircularList& src) {
		if (this != &src) {
			*this = src;
		}
	}

	void Append(Node n) {

		Node* newNode = new Node, *p;

		newNode->_coefficient	=	n._coefficient;
		newNode->_exponent		=	n._exponent;
		newNode->_next			=	(Node*)0;

		if (_head) {

			//if there are nodes in the list
			
			int i;


			for (i = 0, p = _head; i < _size - 1; p = p->_next, i++);//points "p" to last node in list

			p->_next = newNode;
			newNode->_next = _head;

		} else {
			
			//if the list is empty

			_head = newNode;
			_head->_next = _head;

		}

		_size++;

	}

	//TODO needs to be tested
	void Push(Node n) {

		Node* newNode = new Node, *p;
		newNode->_coefficient = n._coefficient;
		newNode->_exponent = n._exponent;
		newNode->_next = (Node*)0;

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

	void Pop() {

		Node* toDel, *p;

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
			_head = (Node*)0;

			delete toDel;

			_size--;
		}
	}

	int GetSize() const {
		return _size;
	}

	void Print() const{
		int i;
		Node* p;

		for (i = 0, p = _head; i < _size; p = p->_next, i++) {
			cout << *p;
		}
	}

	//
	CircularList& operator=(const CircularList& rhs) {
		int i;
		Node newNode, *p;

		for (i = 0, p = rhs._head; i < rhs._size; p = p->_next, i++) {
			newNode._coefficient = p->_coefficient;
			newNode._exponent = p->_exponent;
			Append(newNode);
		}

		return *this;
	}

	//outputs the content of the linked list via << operator
	friend ostream& operator<<(ostream& os, const CircularList& cl) {
		int i;
		Node* p;

		for (i = 0, p = cl._head; i < cl._size; p = p->_next, i++) {
			os << *p;
		}
		return os;
	}

	//adds a node to a CircularList via >> operator
	friend CircularList& operator>>(const Node& lhs, CircularList& rhs) {
		rhs.Append(lhs);
		return rhs;
	}

	//reads a new node from istream and adds it to the list
	//TODO implement this
	friend istream& operator>>(istream& is, const CircularList& cl) {
		//n.Append(n);
		return is; 
	}

	~CircularList() {
		while (_head) {
			Pop();
		}
	}

	friend class Iterator;
};

//TODO decide if I'm going to use an iterator. Would be useful for 
class Iterator {

private:
	Node*	_head, _cur;

public:
	Iterator() {

	}

	int GoNext() {

	}

	int GoHead() {
	
	}

	int GetData() {

	}

	friend Iterator& operator=(const CircularList& rhs) {

	}

	friend Iterator& operator=(const Iterator& i){

	}
};

/*--- =Operator ---*/
//assigns an iterator to a particular circular linked list
/*void operator=(Iterator& lhs, CircularList& rhs) {
	lhs._head = rhs.head;
	lhs._cur = rhs.head;
}*/
#endif