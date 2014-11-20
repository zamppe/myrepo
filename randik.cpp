#include <stdlib.h>
#include "randik.h"

Randik::Randik(time_t seed){
  this->seed = seed;
}

Randik::~Randik(){
  ;
}

int Randik::getRandomInt(int a, int b){
  srand(this->seed);
  return a + (rand() % (int)(b - a + 1));
}
