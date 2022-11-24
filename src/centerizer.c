#import <ncurses.h>
#import "point.h"

struct Point * centerize(int width, int height) {
  int x = COLS / 2;
  int y = LINES / 2;

  x -= width / 2;
  y -= height / 2;

  struct Point * point = create_point(x, y);
  return point;
}
