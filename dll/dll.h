#ifndef __DLL_H__
#define __DLL_H__
#include <stdio.h>
class DLL;

class Node{
private:
  int _data;
  Node* _next;
  Node* _prev;  
  
  Node(int data, Node* next, Node* prev);
 
  friend class DLL;
};

class DLL{
private:
  Node* _head;
  Node* _cur;
  Node* _tail;

public:
  DLL();
  void Push(int data);
  int Pop();
  void Delete();
  void Append(int data);
  void Insert(int data);
  bool goPrev();
  bool goNext();
  void goTail();
  void goHead();
  ~DLL();
};

#endif
