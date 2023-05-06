#ifndef MAIN_MENU_H
#define MAIN_MENU_H

struct MenuOption {
  char * label;
  int index;
  int x;
  int y;
};

struct MainMenu {
  struct MenuOption * options[2];
  int selected;
};

struct MenuOption *create_menu_option(
  char *label,
  int index,
  int x,
  int y
);
void destroy_menu_option(struct MenuOption * option);

struct MainMenu * create_main_menu();
void destroy_main_menu(struct MainMenu * main_menu);
void draw_main_menu(struct MainMenu * main_menu);
void handle_main_menu_input(struct App * app, struct MainMenu * level_select, int ch);

#endif

