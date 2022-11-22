#ifndef GAME_H
#define GAME_H

struct Game {
  struct Entity * player;
  struct Link * entities;
};

struct Game * Game__new();
void Game__draw(struct Game * game);
void Game__destroy(struct Game * game);
void Game__handle_input(struct Game * game, int ch);

#endif
