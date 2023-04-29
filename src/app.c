#include <stdlib.h>
#include <ncurses.h>
#include "app.h"
#include "colors.h"
#include "level_select.h"
#include "game.h"
#include "level_reader.h"

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
}

struct App * create_app() {
  _configure_curses();
  struct App * app = malloc(sizeof(struct App));
  app->game = load_level("data/level_1.lvl");
  app->level_select = create_level_select();
  app->state = STATE_LEVEL_SELECT;
  draw_app(app);
  return app;
}

void destroy_app(struct App * app) {
  destroy_game(app->game);
  destroy_level_select(app->level_select);
  free(app);
  clear();
  endwin();
}

void draw_app(struct App * app) {
  clear();
  switch (app->state) {
    case STATE_LEVEL_SELECT:
      draw_level_select(app->level_select);
      break;
    case STATE_GAME:
      draw_game(app->game);
      break;
  }
  refresh();
}

void handle_app_input(struct App * app, int ch) {
  switch (app->state) {
    case STATE_LEVEL_SELECT:
      handle_level_select_input(app, app->level_select, ch);
      break;
    case STATE_GAME:
      handle_game_input(app->game, ch);
      break;
  }
}

void set_app_state(struct App * app, enum State state) {
  app->state = state;
  draw_app(app);
}
