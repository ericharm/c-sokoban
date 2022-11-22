#ifndef POINT_H
#define POINT_H

struct Point {
  int x;
  int y;
};

struct Point * Point__new(int x, int y);
void Point__destroy(struct Point * point);

#endif
