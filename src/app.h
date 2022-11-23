#ifndef APP_H
#define APP_H

struct App {
  struct Game * game;
};

struct App * create_app();
void destroy_app(struct App * app);
void draw_app(struct App * app);
void handle_app_input(struct App * app, int ch);

#endif
