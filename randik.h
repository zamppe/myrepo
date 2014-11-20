#ifndef RANDIK_H
#include <time.h>

class Randik{
public:
  Randik(time_t seed);
  ~Randik();
  int getRandomInt(int, int);
private:
  time_t seed;
};



#endif // RANDIK_H
