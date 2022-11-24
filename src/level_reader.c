#include <stdlib.h>
#include <ncurses.h>
#include "entity.h"
#include "entity_list.h"
#include "level_reader.h"

void load_level_into_game(struct Link * entities, struct Entity * player, char * filename) {
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
}

