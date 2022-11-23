#include <stdlib.h>
#include <ncurses.h>
#include "app.h"
#include "game.h"
#include "colors.h"

void _configure_colors() {
  start_color();
  init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
  init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

void _configure_curses() {
  initscr();
  _configure_colors();
  keypad(stdscr, true);
  noecho();
  curs_set(0);
}

struct App * create_app() {
  _configure_curses();
  struct App * app = malloc(sizeof(struct App));
  app->game = create_game();
  draw_app(app);
  return app;
}

void destroy_app(struct App * app) {
  destroy_game(app->game);
  free(app);
  clear();
  endwin();
}

void draw_app(struct App * app) {
  clear();
  draw_game(app->game);
  refresh();
}

void handle_app_input(struct App * app, int ch) {
  handle_game_input(app->game, ch);
}
