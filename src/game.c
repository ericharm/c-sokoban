#include <stdlib.h>
#include "game.h"
#include "entity.c"
#include "player.c"
#include "boulder.c"

struct Game * Game__new() {
  struct Game * game = malloc(sizeof(struct Game));
  game->player = Player__new(5, 5);
  game->boulder = Boulder__new(7, 5);
  /* game->boulderList = EntityList__new(); */
  /* EntityList__push(game->boulderList, Boulder__new(2, 2)); */
  /* EntityList__push(game->boulderList, Boulder__new(8, 2)); */
  return game;
}

void Game__destroy(struct Game * game) {
  Entity__destroy(game->player);
  Entity__destroy(game->boulder);
  /* EntityList__destroy(game->boulderList); */
  free(game);
}

void Game__draw(struct Game * game) {
  Entity__draw(game->player);
  Entity__draw(game->boulder);
}

void Game__handle_input(struct Game * game, int ch) {
  Player__handle_input(game->player,ch);
}
