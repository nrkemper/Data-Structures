#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

class LinkedList;

class Node{

private:
  int _data;
  Node* _next;
  
  Node(int data, Node* next); 
  friend class LinkedList; 
};

class LinkedList{
private: 
  Node* _head;
 
public:
  LinkedList();
  LinkedList(const LinkedList& l);
  void Push(int data);
  void Append(int data);
  void operator=(const LinkedList& l);
  int Pop();
  ~LinkedList();
};

#endif
