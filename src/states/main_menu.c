#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "../app.h"
#include "../centerizer.h"
#include "../point.h"
#include "main_menu.h"

struct MenuOption * create_menu_option(
    char * label,
    int index,
    int x,
    int y
) {
  struct MenuOption * menu_option = malloc(sizeof(struct MenuOption));
  menu_option->label = label;
  menu_option->index = index;
  menu_option->x = x;
  menu_option->y = y;
  return menu_option;
}

void destroy_menu_option(struct MenuOption * option) {
  free(option->label);
  free(option);
}


struct MainMenu * create_main_menu() {
  struct MainMenu * main_menu = malloc(sizeof(struct MainMenu));
  main_menu->options[0] = create_menu_option("New Game", 0, 0, 0);
  main_menu->options[1] = create_menu_option("Quit", 1, 0, 2);
  main_menu->selected = 0;
  return main_menu;
}

void destroy_main_menu(struct MainMenu * main_menu) {
  for (int i = 0; i < 2; i++) {
    destroy_menu_option(main_menu->options[i]);
  }
  free(main_menu);
}

void draw_main_menu(struct MainMenu * main_menu) {
  struct Point * center = centerize(20, 12);
  for (int i = 0; i < 2; i++) {
    struct MenuOption * option = main_menu->options[i];
    mvaddstr(option->y + center->y, option->x + center->x, option->label);
  }
  struct MenuOption * selected = main_menu->options[main_menu->selected];
  move(selected->y + center->y, selected->x + center->x - 2);
}

void handle_main_menu_input(struct App * app, struct MainMenu * main_menu, int ch) {
  switch (ch) {
    case KEY_UP:
      main_menu->selected -= 1;
      if (main_menu->selected < 0) {
        main_menu->selected = 1;
      }
      break;
    case KEY_DOWN:
      main_menu->selected += 1;
      if (main_menu->selected > 1) {
        main_menu->selected = 0;
      }
      break;
    case KEY_RIGHT:
      main_menu->selected++;
      if (main_menu->selected > 1) {
        main_menu->selected = 0;
      }
      break;
    case KEY_LEFT:
      main_menu->selected--;
      if (main_menu->selected < 0) {
        main_menu->selected = 1;
      }
      break;

    case '\n':
      set_app_state(app, STATE_LEVEL_SELECT);
  }
}

