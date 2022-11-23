#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "entity.h"
#include "logger.h"
#include "point.h"

void _read_level(struct Game * game) {
  FILE * file = fopen("data/level_1.lvl", "r");

  int x = -1;
  int y = 0;

  int ch = fgetc(file);

  do {
    switch (ch) {
      case '\n':
        x = -1;
        y++;
        break;
      case '@':
        game->player = Entity__new(PLAYER_TYPE, x, y);
        break;
      case '0':
        EntityList__push(game->entities, Entity__new(BOULDER_TYPE, x, y));
        break;
      case '#':
        EntityList__push(game->entities, Entity__new(WALL_TYPE, x, y));
        break;
      case '^':
        EntityList__push(game->entities, Entity__new(PIT_TYPE, x, y));
        break;
      case 'X':
        EntityList__push(game->entities, Entity__new(EXIT_TYPE, x, y));
        break;
    }
    x++;
    ch = fgetc(file);
  } while (ch != EOF);

  fclose(file);

}

struct Game * Game__new() {
  struct Game * game = malloc(sizeof(struct Game));
  game->entities = EntityList__new();
  _read_level(game);
  return game;
}

void Game__destroy(struct Game * game) {
  Entity__destroy(game->player);
  EntityList__destroy(game->entities);
  free(game);
}

void Game__draw(struct Game * game) {
  Entity__draw(game->player);
  EntityList__draw(game->entities);
}

struct Point * _next_location(struct Entity * entity, int x, int y) {
  struct Point * point = Point__new(entity->x + x, entity->y + y);
  return point;
}

void _Game__move_player(struct Game * game, int x, int y) {
  struct Point * player_next = _next_location(game->player, x, y);
  struct Entity * entity = EntityList__element_at(
    game->entities, player_next->x, player_next->y
  );

  if (entity == NULL) {
    Entity__move(game->player, player_next->x, player_next->y);
  }
  Point__destroy(player_next);
}

void _Game__move_entity(struct Link * entities, struct Entity * entity, int x, int y) {
  struct Point * boulder_next = _next_location(entity, x, y);

  struct Entity * obstacle = EntityList__element_at(
    entities, boulder_next->x, boulder_next->y
  );

  if (obstacle == NULL) {
    Entity__move(entity, boulder_next->x, boulder_next->y);
  } else {
    if (obstacle->type == PIT_TYPE) {
      // remove pit and boulder
      EntityList__delete_element(entities, obstacle);
      EntityList__delete_element(entities, entity);
    }
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
    game->entities, player_next->x, player_next->y
  );

  if (entity) {
    struct Point * entity_next = _next_location(entity, x, y);

    if (entity->type == BOULDER_TYPE) {
      _Game__move_entity(game->entities, entity, x, y);
    } else if (entity->type == EXIT_TYPE) {
      exit(0);
    }
    Point__destroy(entity_next);
  }

  _Game__move_player(game, x, y);
  Point__destroy(player_next);
}
