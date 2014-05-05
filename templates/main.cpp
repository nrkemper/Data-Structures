#include <stdio.h>
#include "tempdll.h"

int main(){
  DLL<double> dl;

  int i;
  for(i=0;i<200;i++){
    dl.Push((double)i);
  }  

  while(!dl.isEmpty()){
    printf("%f\n", dl.Pop());
  }
  return 0;
}
