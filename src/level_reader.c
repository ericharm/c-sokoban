#include <stdlib.h>
#include <ncurses.h>
#include "entity.h"
#include "entity_list.h"
#include "states/game.h"
#include "level_reader.h"

struct Game * load_level(char * filename) {
  struct Game * game = create_game();

  FILE * file = fopen(filename, "r");

  int x = 0;
  int y = 0;

  int ch = fgetc(file);

  do {
    switch (ch) {
      case '\n':
        x = -1;
        y++;
        game->height++;
        break;
      case '@':
        game->player->x = x;
        game->player->y = y;
        break;
      case '0':
        append_to_entity_list(game->entities, create_entity(BOULDER_TYPE, x, y));
        break;
      case '#':
        append_to_entity_list(game->entities, create_entity(WALL_TYPE, x, y));
        break;
      case '^':
        append_to_entity_list(game->entities, create_entity(PIT_TYPE, x, y));
        break;
      case 'X':
        append_to_entity_list(game->entities, create_entity(EXIT_TYPE, x, y));
        break;
    }
    x++;
    if (x > game->width) game->width = x;
    ch = fgetc(file);
  } while (ch != EOF);

  fclose(file);

  return game;
}

