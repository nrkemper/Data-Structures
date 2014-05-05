#include "dll.h"
#include <stdio.h>

Node::Node(int data, Node* next, Node* prev){
  _data=data;
  _next=next;
  _prev=prev;
}

DLL::DLL(){
  _head=(Node*)0;
  _cur=(Node*)0;
  _tail=(Node*)0;
}

void DLL::Push(int data){
  Node* newNode = new Node(data, _head, (Node*)0);
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

int DLL::Pop(){
  Node* toDel = _head;
  _head = _head->_next;
  int toRet=0;

  if(toDel){
    toRet = toDel->_data;
  }

  if(_head){
    _head->_prev=(Node*)0;
  }

  return toRet;
}
  
void DLL::Delete(){
  Node* toDel = _cur;
  if(toDel){
    if(toDel->_prev==NULL && toDel->_next == NULL){
      _head=(Node*)0;
      _cur=(Node*)0;
      _tail=(Node*)0;
    }
    else if(toDel->_prev==NULL && toDel->_next){
      toDel->_next->_prev = (Node*)0;
      _cur=toDel->_next; 
      _head=toDel->_next;
    }
    else if(toDel->_prev && toDel->_next == NULL){
      toDel->_prev->_next=(Node*)0;
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
  
void DLL::Append(int data){
  Node* newNode = new Node(data, (Node*)0, (Node*)0);
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

void DLL::Insert(int data){
  Node* newNode = new Node(data, (Node*)0, (Node*)0);
  
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

bool DLL::goPrev(){
  bool success=true;

  if(_cur->_prev!=NULL){
    _cur=_cur->_prev;
  }
  else{
    success=false;
  }

  return success;
}
  
bool DLL::goNext(){
  bool success=true;
 
  if(_cur->_next!=NULL){
    _cur=_cur->_next;
  }
  else{
    success=false;
  }

  return success;
}

void DLL::goTail(){
  while(goNext());
}

void DLL::goHead(){
  while(goPrev());
}

DLL::~DLL(){
  while(_head){
    printf("%d\n", Pop());
  }
}
