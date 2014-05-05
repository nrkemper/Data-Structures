#ifndef __EAGLE_H__
#define __EAGLE_H__
#include "Bird.h"

class Eagle : public Bird{
public:
  Eagle() : Bird(){}
  Eagle(const char* name) : Bird(name){}

  void Fly(){
    printf("Eagle is flying");
  }
  
  ~Eagle(){
    printf("Eagle is dying\n");
  }
};


#endif
