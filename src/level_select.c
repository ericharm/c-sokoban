#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "level_select.h"

struct LevelChoice * create_level_choice(int n, int x, int y) {
  struct LevelChoice * level_choice = malloc(sizeof(struct LevelChoice));
  /* level_choice->label = label; */
  /* level_choice->filename = filename; */
  level_choice->num = n;
  level_choice->x = x;
  level_choice->y = y;
  return level_choice;
}

void destroy_level_choice(struct LevelChoice * choice) {
  /* free(choice->label); */
  /* free(choice->filename); */
  free(choice);
}

char * _get_level_label(int n) {
  char label[] = {'L', 'e', 'v', 'e', 'l', ' ', '0', '\0'};
  char * label_ptr = label;
  return label_ptr;
}

char * _get_level_filename(int n) {
  char * filename = "data/level_";
  /* const char num = '0' + n; */
  /* strcat(filename, &num); */
  /* strcat(filename, ".lvl"); */
  return filename;
}

struct LevelSelect * create_level_select() {
  struct LevelSelect * level_select = malloc(sizeof(struct LevelSelect));
  for (int i = 0; i < 8; i++) {
    int x = i > 3 ? 10 : 0; //(i % 2) * 10;
    int y = (i + 1) * 2;
    if (i > 3) y -= 8;
    level_select->options[i] = create_level_choice(
        i, x, y
    );
  }
  return level_select;
}

void destroy_level_select(struct LevelSelect * level_select) {
  for (int i = 0; i < 8; i++) {
    destroy_level_choice(level_select->options[i]);
  }
  free(level_select);
}

void draw_level_select(struct LevelSelect * level_select) {
  for (int i = 0; i < 8; i++) {
    struct LevelChoice * choice = level_select->options[i];
    mvaddstr(choice->y, choice->x, "Level ");
    char num = '1' + choice->num;
    mvaddch(choice->y, choice->x + 6, num);
  }
}

void handle_level_select_input(struct LevelSelect * level_select, int ch) {

}
