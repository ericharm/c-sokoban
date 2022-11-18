#include <stdlib.h>
#include <ncurses.h>
#include "app.h"
#include "game.c"
/* #include "colors.c" */

void _configure_curses() {
  initscr();
  configure_colors();
  keypad(stdscr, true);
  noecho();
  curs_set(0);
}

struct App * App__new() {
  _configure_curses();
  struct App * app = malloc(sizeof(struct App));
  app->game = Game__new();
  App__draw(app);
  return app;
}

void App__destroy(struct App * app) {
  Game__destroy(app->game);
  free(app);
  clear();
  endwin();
}

void App__draw(struct App * app) {
  clear();
  Game__draw(app->game);
  refresh();
}

void App__handle_input(struct App * app, int ch) {
  Game__handle_input(app->game, ch);
}
