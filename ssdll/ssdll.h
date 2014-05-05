#ifndef __SSDLL_H__
#define __SSDLL_H__
#include <fstream>
#include <string.h>
using namespace std;

template <class T>
class SSDLL;

template <class T>
class Node{
private:
  T _data;
  Node<T>* _next;
  Node<T>* _prev;  
  Node(T data, Node* next, Node* prev);
 
  friend class SSDLL<T>;
};

template <class T>
class SSDLL : public fstream{
private:
  Node<T>* _head;
  Node<T>* _cur;
  Node<T>* _tail;
  char _fname[50]; 

public:
  SSDLL();
  SSDLL(const char* fname);
  void Push(T data);
  T Pop();
  void Delete();
  void Append(T data);
  void Insert(T data);
  bool goPrev();
  bool goNext();
  void goTail();
  void goHead();
  void Save();//do this
  void Save(const char* fname);//do this
  void Load();//do this
  void Load(const char* fname);//do this
  bool isEmpty();
  ~SSDLL();
};

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev){
  _data=data;
  _next=next;
  _prev=prev;
}

template <class T>
SSDLL<T>::SSDLL(){
  _head=(Node<T>*)0;
  _cur=(Node<T>*)0;
  _tail=(Node<T>*)0;
  strncpy(_fname, "dll.txt", 50);
}

template <class T>
SSDLL<T>::SSDLL(const char* fname){
  _head=(Node<T>*)0;
  _cur=(Node<T>*)0;
  _tail=(Node<T>*)0;
  strncpy(_fname, fname, 50); 
}

template <class T>
void SSDLL<T>::Push(T data){
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
T SSDLL<T>::Pop(){
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
void SSDLL<T>::Delete(){
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
void SSDLL<T>::Append(T data){
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
void SSDLL<T>::Insert(T data){
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
bool SSDLL<T>::goPrev(){
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
bool SSDLL<T>::goNext(){
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
void SSDLL<T>::goTail(){
  while(goNext());
}

template <class T>
void SSDLL<T>::goHead(){
  while(goPrev());
}

void SSDLL<T>::Save(){
  open(_fname, out);
 
  Node<T>* p = _head;

  while(p){
    write((char*)p, sizeof(Node<T>));
    p=p->_next;
  }
}

void SSDLL<T>::Save(const char* fname){

}

void SSDLL<T>::Load(){

}

void SSDLL<T>::Load(const char* fname){

}

template <class T>
bool SSDLL<T>::isEmpty(){
  return !_head;
}

template <class T>
SSDLL<T>::~SSDLL(){
  while(_head){
    Pop();
  }
}

#endif
