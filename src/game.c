#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "entity.h"
#include "logger.h"
#include "point.h"

struct Game * Game__new() {
  struct Game * game = malloc(sizeof(struct Game));
  game->player = Entity__new(PLAYER_TYPE, 5, 5);
  game->boulderList = EntityList__new();

  EntityList__push(game->boulderList, Entity__new(WALL_TYPE, 1, 2));
  EntityList__push(game->boulderList, Entity__new(WALL_TYPE, 5, 2));
  EntityList__push(game->boulderList, Entity__new(BOULDER_TYPE, 2, 2));
  EntityList__push(game->boulderList, Entity__new(BOULDER_TYPE, 8, 2));
  return game;
}

void Game__destroy(struct Game * game) {
  Entity__destroy(game->player);
  EntityList__destroy(game->boulderList);
  free(game);
}

void Game__draw(struct Game * game) {
  Entity__draw(game->player);
  EntityList__draw(game->boulderList);
}

struct Point * _next_location(struct Entity * entity, int x, int y) {
  struct Point * point = Point__new(entity->x + x, entity->y + y);
  return point;
}

void _Game__move_player(struct Game * game, int x, int y) {
  struct Point * player_next = _next_location(game->player, x, y);
  struct Entity * entity = EntityList__element_at(
    game->boulderList, player_next->x, player_next->y
  );

  if (entity == NULL) {
    Entity__move(game->player, player_next->x, player_next->y);
  }
  Point__destroy(player_next);
}

void _Game__move_entity(struct Link * boulders, struct Entity * entity, int x, int y) {
  struct Point * boulder_next = _next_location(entity, x, y);

  struct Entity * other_boulder = EntityList__element_at(
    boulders, boulder_next->x, boulder_next->y
  );

  if (other_boulder == NULL) {
    Entity__move(entity, boulder_next->x, boulder_next->y);
  }

  Point__destroy(boulder_next);
}

void Game__handle_input(struct Game * game, int ch) {
  int x = 0;
  int y = 0;
  if (ch == KEY_LEFT) x--;
  if (ch == KEY_RIGHT) x++;
  if (ch == KEY_UP) y--;
  if (ch == KEY_DOWN) y++;

  struct Point * player_next = _next_location(game->player, x, y);

  struct Entity * entity = EntityList__element_at(
    game->boulderList, player_next->x, player_next->y
  );

  if (entity) {
    struct Point * entity_next = _next_location(entity, x, y);

    if (entity->type == BOULDER_TYPE) {
      _Game__move_entity(game->boulderList, entity, x, y);
    }
    Point__destroy(entity_next);
  }

  _Game__move_player(game, x, y);
  Point__destroy(player_next);
}
