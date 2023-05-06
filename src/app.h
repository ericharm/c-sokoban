#ifndef APP_H
#define APP_H


enum State {
    STATE_MAIN_MENU,
    STATE_LEVEL_SELECT,
    STATE_GAME,
};

struct App {
  struct MainMenu * main_menu;
  struct LevelSelect * level_select;
  struct Game * game;
  enum State state;
};

struct App * create_app();
void destroy_app(struct App * app);
void draw_app(struct App * app);
void handle_app_input(struct App * app, int ch);
void set_app_state(struct App * app, enum State state);

#endif
