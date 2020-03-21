#ifndef Rubiks_Cube_Algo_h
#define Rubiks_Cube_Algo_h

#include "Arduino.h"

class rcalgo
{
  public:
    rcalgo();
    int solve(int inpsize,char* scramble,char* in);
};

#endif
