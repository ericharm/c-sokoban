#ifndef LEVEL_SELECT_H
#define LEVEL_SELECT_H

struct LevelChoice {
  int num;
  int x;
  int y;
};

struct LevelSelect {
  struct LevelChoice * options[8];
};

struct LevelChoice * create_level_choice(int num, int x, int y);
void destroy_level_choice(struct LevelChoice * choice);

struct LevelSelect * create_level_select();
void destroy_level_select(struct LevelSelect * level_select);
void draw_level_select(struct LevelSelect * level_select);
void handle_level_select_input(struct LevelSelect * level_select, int ch);

#endif
