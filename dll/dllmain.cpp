#include "dll.h"
#include <stdio.h>
int main(){
  DLL l;

  int i;
  for(i=0;i<10;i++){
    l.Insert(i);
  }

  printf("Going to head\n");
  l.goHead();
  l.Delete();
  
  printf("Going to tail\n");
  l.goTail();
  l.Delete();
  
  for(i=0;i<3;i++)l.goPrev();
  l.Delete();
  return 0;
}
