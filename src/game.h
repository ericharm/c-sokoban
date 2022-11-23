#ifndef GAME_H
#define GAME_H

struct Game {
  struct Entity * player;
  struct Link * entities;
};

struct Game * create_game();
void destroy_game(struct Game * game);
void draw_game(struct Game * game);
void handle_game_input(struct Game * game, int ch);

#endif
