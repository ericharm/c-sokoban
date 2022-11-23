#include <stdlib.h>
#include <ncurses.h>
#include "level_reader.h"
#include "entity.h"
#include "entity_list.h"

struct Entity * load_level_player(char * filename) {
  struct Entity * player = create_entity(PLAYER_TYPE, 0, 0);
  FILE * file = fopen(filename, "r");

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
        player->x = x;
        player->y = y;
        break;
    }
    x++;
    ch = fgetc(file);
  } while (ch != EOF && player->x == 0 && player->y == 0);

  fclose(file);
  return player;
}

struct Link * load_level_entities(char * filename) {
  struct Link * entities = create_entity_list();
  FILE * file = fopen(filename, "r");

  int x = -1;
  int y = 0;

  int ch = fgetc(file);

  do {
    switch (ch) {
      case '\n':
        x = -1;
        y++;
        break;
      case '0':
        append_to_entity_list(entities, create_entity(BOULDER_TYPE, x, y));
        break;
      case '#':
        append_to_entity_list(entities, create_entity(WALL_TYPE, x, y));
        break;
      case '^':
        append_to_entity_list(entities, create_entity(PIT_TYPE, x, y));
        break;
      case 'X':
        append_to_entity_list(entities, create_entity(EXIT_TYPE, x, y));
        break;
    }
    x++;
    ch = fgetc(file);
  } while (ch != EOF);

  fclose(file);
  return entities;
}
