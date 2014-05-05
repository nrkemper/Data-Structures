#ifndef __BIRD_H__
#define __BIRD_H__
#include <string.h>
#include <stdio.h>

class Bird{
private:
  char _name[30];
public:
  Bird(){
    strncpy(_name, "Generic", 30);
  }
  Bird(const char* name){
    strncpy(_name, name, 30);
  }
  virtual void Fly() = 0;  
  ~Bird(){
    printf("%s is being destroyed\n", _name); 
  }
};

#endif
