#include <stdio.h>
#include "linkedlist.h"

Node::Node(int data, Node* next){
  _data=data;
  _next=next;
}
    
LinkedList::LinkedList(){
  _head=NULL;
}

LinkedList::LinkedList(const LinkedList& l){
  _head=NULL;
  Node* p = l._head;
  while(p){
    Append(p->_data);
    p=p->_next;
  }
}

void LinkedList::Push(int data){
  Node* newNode = new Node(data, _head);
  _head = newNode;
}

void LinkedList::Append(int data){
  Node* newNode = new Node(data, (Node*)0);
  Node* p=_head;
  if(p){
    while(p->_next){
      p=p->_next;
    }
    p->_next = newNode;
  }
  else{
    _head=newNode;  
  }
}
void LinkedList::operator=(const LinkedList& l){ 
  while(_head){//delete everything currently in the list
    Pop();
  }

  Node* p = l._head;
  while(p){
    Append(p->_data);
    p=p->_next;
  }
}

int LinkedList::Pop(){
  Node* toDel = _head;
  int toRet=0;
  if(toDel){
    toRet = _head->_data;
    _head=_head->_next;
    delete toDel;
  }
  return toRet;
}

LinkedList::~LinkedList(){
  printf("Destroying list\n");
  while(_head){
    printf("%d\n",Pop());;
  }
}
