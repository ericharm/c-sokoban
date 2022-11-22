#include <stdlib.h>
#include "point.h"

struct Point * Point__new(int x, int y) {
  struct Point * point = malloc(sizeof(struct Point));
  point->x = x;
  point->y = y;
  return point;
}

void Point__destroy(struct Point * point) {
  free(point);
}
