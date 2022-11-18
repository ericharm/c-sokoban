#ifndef BOULDER_C
#define BOULDER_C
#include "entity.h"
#include "colors.c"

struct Entity * Boulder__new(int x, int y) {
  return Entity__new('0', YELLOW, x, y);
}

#endif
