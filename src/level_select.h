#ifndef LEVEL_SELECT_H
#define LEVEL_SELECT_H


struct LevelChoice {
  // LevelChoice represents a level choice in the level select menu.
  // It has a label: string to print to the screen when showing the level select menu,
  // it has an x: int and y: int coordinate to indicate where to print the label on the screen,
  // it has an index: int to inidicate its order in the sequence of level options,
  // and it has a filename: string to indicate the file from which to read its data
  // when the user selects it.
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
