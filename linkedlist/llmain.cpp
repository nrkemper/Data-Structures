#include "linkedlist.h"
#include <stdio.h>
int main(){
  int i=0;
  
  LinkedList l;

  for(i=0;i<30;i++){
    l.Push(i);
  }

  printf("Popping: %d\n", l.Pop());
  printf("Popping: %d\n", l.Pop());
  printf("Popping: %d\n", l.Pop());

  printf("Pushing 203\n");
  l.Push(203);  
  printf("Appending 67\n");
  l.Append(67);  
  printf("Popping: %d\n", l.Pop());
  printf("Copying list to a new list\n");

  LinkedList l2;
  l2=l;
  printf("Testing copy constructor\n");
  LinkedList l3=l2;
  return 0;
}
