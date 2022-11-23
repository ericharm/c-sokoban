#include <stdlib.h>
#include "point.h"

struct Point * create_point(int x, int y) {
  struct Point * point = malloc(sizeof(struct Point));
  point->x = x;
  point->y = y;
  return point;
}

void destroy_point(struct Point * point) {
  free(point);
}
