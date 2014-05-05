#ifndef __DLL_H__
#define __DLL_H__
#include <stdio.h>

template <class T>
class DLL;

template <class T>
class Node{
private:
  T _data;
  Node<T>* _next;
  Node<T>* _prev;  
 
  Node(T data, Node* next, Node* prev);
 
  friend class DLL<T>;
};

template <class T>
class DLL{
private:
  Node<T>* _head;
  Node<T>* _cur;
  Node<T>* _tail;

public:
  DLL();
  void Push(T data);
  T Pop();
  void Delete();
  void Append(T data);
  void Insert(T data);
  bool goPrev();
  bool goNext();
  void goTail();
  void goHead();
  bool isEmpty();
  ~DLL();
};

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev){
  _data=data;
  _next=next;
  _prev=prev;
}

template <class T>
DLL<T>::DLL(){
  _head=(Node<T>*)0;
  _cur=(Node<T>*)0;
  _tail=(Node<T>*)0;
}

template <class T>
void DLL<T>::Push(T data){
  Node<T>* newNode = new Node<T>(data, _head, (Node<T>*)0);
  if(_head){
    _head->_prev=newNode;
  }
  
  _head = newNode;
    
  if(_cur==NULL){
    _cur=newNode;
  }

  if(_tail==NULL){
    _tail=newNode;
  }
}

template <class T>
T DLL<T>::Pop(){
  Node<T>* toDel = _head;
  _head = _head->_next;
  T toRet=0;

  if(toDel){
    toRet = toDel->_data;
  }

  if(_head){
    _head->_prev=(Node<T>*)0;
  }

  return toRet;
}
  
template <class T>
void DLL<T>::Delete(){
  Node<T>* toDel = _cur;
  if(toDel){
    if(toDel->_prev==NULL && toDel->_next == NULL){
      _head=(Node<T>*)0;
      _cur=(Node<T>*)0;
      _tail=(Node<T>*)0;
    }
    else if(toDel->_prev==NULL && toDel->_next){
      toDel->_next->_prev = (Node<T>*)0;
      _cur=toDel->_next; 
      _head=toDel->_next;
    }
    else if(toDel->_prev && toDel->_next == NULL){
      toDel->_prev->_next=(Node<T>*)0;
      _cur=toDel->_prev;
      _tail=toDel->_prev; 
    }
    else{
      toDel->_prev->_next = toDel->_next;
      toDel->_next->_prev = toDel->_prev;
      _cur=toDel->_prev;
    }
    delete toDel;
  }
}
  
template <class T>
void DLL<T>::Append(T data){
  Node<T>* newNode = new Node<T>(data, (Node<T>*)0, (Node<T>*)0);
  if(_tail){//if there is at least one node in the list
    _tail->_next=newNode;
    newNode->_prev=_tail;
  }
  else{
    _head=newNode;
    _cur=newNode;
  }
  _tail=newNode; 
}

template <class T>
void DLL<T>::Insert(T data){
  Node<T>* newNode = new Node<T>(data, (Node<T>*)0, (Node<T>*)0);
  
  if(_cur==NULL){//list is empty
    _head=newNode;
    _tail=newNode;
  }
  else if(_cur->_prev==NULL && (_cur->_next || _cur->_next == NULL)){//current is at head or only has one node
    newNode->_next=_cur;
    newNode->_next->_prev = newNode;
    _head = newNode; 
  }
  else if(_cur->_prev && _cur->_next == NULL){//current is at tail
    newNode->_next = _cur;
    _cur->_prev->_next = newNode; 
  }
  else{
    newNode->_next = _cur;
    newNode->_prev = _cur->_prev;
    _cur->_prev->_next = newNode;
    _cur->_next->_prev = newNode;
  }
    
  _cur = newNode;
}  

template <class T>
bool DLL<T>::goPrev(){
  bool success=true;

  if(_cur->_prev!=NULL){
    _cur=_cur->_prev;
  }
  else{
    success=false;
  }

  return success;
}
  
template <class T>
bool DLL<T>::goNext(){
  bool success=true;
 
  if(_cur->_next!=NULL){
    _cur=_cur->_next;
  }
  else{
    success=false;
  }

  return success;
}

template <class T>
void DLL<T>::goTail(){
  while(goNext());
}

template <class T>
void DLL<T>::goHead(){
  while(goPrev());
}

template <class T>
bool DLL<T>::isEmpty(){
  return !_head;
}

template <class T>
DLL<T>::~DLL(){
  while(_head){
    Pop();
  }
}

#endif
