#ifndef LEVEL_SELECT_H
#define LEVEL_SELECT_H


struct LevelChoice {
  char * label;
  char * filename;
  int index;
  int x;
  int y;
};

struct LevelSelect {
  struct LevelChoice * options[8];
  int selected;
};

struct LevelChoice *create_level_choice(
  char *label,
  char *filename,
  int index,
  int x,
  int y
);
void destroy_level_choice(struct LevelChoice * choice);

struct LevelSelect * create_level_select();
void destroy_level_select(struct LevelSelect * level_select);
void draw_level_select(struct LevelSelect * level_select);
void handle_level_select_input(struct App * app, struct LevelSelect * level_select, int ch);

#endif
