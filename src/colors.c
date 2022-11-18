#ifndef COLORS
#define COLORS
#define MAGENTA 1
#define YELLOW 2

#include <ncurses.h>

void configure_colors() {
  start_color();
  init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

#endif
