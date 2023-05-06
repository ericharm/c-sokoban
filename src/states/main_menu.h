#ifndef MAIN_MENU_H
#define MAIN_MENU_H

enum MenuOptionType {
  MAIN_MENU_OPTION_PLAY,
  MAIN_MENU_OPTION_QUIT
};

struct MenuOption {
  char * label;
  enum MenuOptionType type;
  int index;
  int x;
  int y;
};

struct MenuOption *create_menu_option(
  char *label,
  enum MenuOptionType type,
  int index,
  int x,
  int y
);

void destroy_menu_option(struct MenuOption * option);

struct MainMenu {
  struct MenuOption * options[2];
  int selected;
};

struct MainMenu * create_main_menu();
void destroy_main_menu(struct MainMenu * main_menu);
void draw_main_menu(struct MainMenu * main_menu);
void handle_main_menu_input(struct App * app, struct MainMenu * level_select, int ch);

#endif

