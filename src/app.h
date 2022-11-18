#ifndef APP_H
#define APP_H

/* #include "game.h" */

struct App {
  struct Game * game;
};

struct App * App__new();
void App__destroy(struct App * app);
void App__draw(struct App * app);
void App__handle_input(struct App * app, int ch);

#endif
