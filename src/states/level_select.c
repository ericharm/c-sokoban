#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "../app.h"
#include "../centerizer.h"
#include "../level_reader.h"
#include "../point.h"
#include "level_select.h"

struct LevelChoice * create_level_choice(
    char * label,
    char * filename,
    int index,
    int x,
    int y
) {
  struct LevelChoice * level_choice = malloc(sizeof(struct LevelChoice));
  level_choice->label = label;
  level_choice->filename = filename;
  level_choice->index = index;
  level_choice->x = x;
  level_choice->y = y;
  return level_choice;
}

void destroy_level_choice(struct LevelChoice * choice) {
  free(choice->label);
  free(choice->filename);
  free(choice);
}

char * _get_level_label(int level_number) {
  char * label = malloc(sizeof(char) * 16);
  sprintf(label, "Level %d", level_number);
  return label;
}


char * _get_level_filename(int level_number) {
  char * filename = malloc(sizeof(char) * 32);
  sprintf(filename, "data/level_%d.lvl", level_number);
  return filename;
}

struct LevelSelect * create_level_select() {
  struct LevelSelect * level_select = malloc(sizeof(struct LevelSelect));
  for (int i = 0; i < 8; i++) {
    char * label = _get_level_label(i + 1);
    char * filename = _get_level_filename(i + 1);
    int x = (i % 2) * 10;
    int y = ((i + 2) / 2) * 2;
    level_select->options[i] = create_level_choice(label, filename, i, x, y);
  }
  level_select->selected = 0;
  return level_select;
}

void destroy_level_select(struct LevelSelect * level_select) {
  for (int i = 0; i < 8; i++) {
    destroy_level_choice(level_select->options[i]);
  }
  free(level_select);
}

void draw_level_select(struct LevelSelect * level_select) {
  struct Point * center = centerize(20, 12);
  for (int i = 0; i < 8; i++) {
    struct LevelChoice * choice = level_select->options[i];
    mvaddstr(choice->y + center->y, choice->x + center->x, choice->label);
  }
  struct LevelChoice * selected = level_select->options[level_select->selected];
  move(selected->y + center->y, selected->x + center->x - 2);
}

void handle_level_select_input(struct App * app, struct LevelSelect * level_select, int ch) {
  switch (ch) {
    case KEY_UP:
      level_select->selected -= 2;
      if (level_select->selected < 0) {
        level_select->selected = 7;
      }
      break;
    case KEY_DOWN:
      level_select->selected += 2;
      if (level_select->selected > 7) {
        level_select->selected = 0;
      }
      break;
    case KEY_RIGHT:
      level_select->selected++;
      if (level_select->selected > 7) {
        level_select->selected = 0;
      }
      break;
    case KEY_LEFT:
      level_select->selected--;
      if (level_select->selected < 0) {
        level_select->selected = 7;
      }
      break;

    case '\n':
      set_app_state(app, STATE_GAME);
      app->game = load_level(level_select->options[level_select->selected]->filename);
  }

}
