#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "entity.h"
#include "entity_list.h"
#include "level_reader.h"
#include "point.h"

struct Game * create_game() {
  struct Game * game = malloc(sizeof(struct Game));
  game->entities = create_entity_list();
  game->player = create_entity(PLAYER_TYPE, 0, 0);
  load_level_into_game(game->entities, game->player, "data/level_1.lvl");
  return game;
}

void destroy_game(struct Game * game) {
  destroy_entity(game->player);
  destroy_entity_list(game->entities);
  free(game);
}

void draw_game(struct Game * game) {
  draw_entity(game->player);
  draw_entity_list(game->entities);
}

struct Point * _next_location(struct Entity * entity, int x, int y) {
  struct Point * point = create_point(entity->x + x, entity->y + y);
  return point;
}

void _move_player(struct Game * game, int x, int y) {
  struct Point * player_next = _next_location(game->player, x, y);
  struct Entity * entity = find_entity_at_point_in_list(
    game->entities, player_next->x, player_next->y
  );

  if (entity == NULL) move_entity(game->player, player_next->x, player_next->y);
  destroy_point(player_next);
}

void _push_boulder(struct Link * entities, struct Entity * entity, int x, int y) {
  struct Point * boulder_next = _next_location(entity, x, y);
  struct Entity * obstacle = find_entity_at_point_in_list(
    entities, boulder_next->x, boulder_next->y
  );

  if (obstacle == NULL) move_entity(entity, boulder_next->x, boulder_next->y);
  else if (obstacle->type == PIT_TYPE) {
    remove_entity_from_list(entities, obstacle);
    remove_entity_from_list(entities, entity);
  }
  destroy_point(boulder_next);
}

void handle_game_input(struct Game * game, int ch) {
  int x = 0;
  int y = 0;
  if (ch == KEY_LEFT) x--;
  else if (ch == KEY_RIGHT) x++;
  else if (ch == KEY_UP) y--;
  else if (ch == KEY_DOWN) y++;

  struct Point * player_next = _next_location(game->player, x, y);
  struct Entity * entity = find_entity_at_point_in_list(
    game->entities, player_next->x, player_next->y
  );

  if (entity) {
    if (entity->type == BOULDER_TYPE) _push_boulder(game->entities, entity, x, y);
    else if (entity->type == EXIT_TYPE) exit(0);
  }

  _move_player(game, x, y);
  destroy_point(player_next);
}
