#ifndef POINT_H
#define POINT_H

struct Point {
  int x;
  int y;
};

struct Point * create_point(int x, int y);
void destroy_point(struct Point * point);

#endif
