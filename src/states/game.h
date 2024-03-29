#ifndef GAME_H
#define GAME_H

struct Game {
  struct Entity * player;
  struct Link * entities;
  int width;
  int height;
};

struct Game * create_game();
void destroy_game(struct Game * game);
void draw_game(struct Game * game);
void handle_game_input(struct App * app, struct Game * game, int ch);

#endif
