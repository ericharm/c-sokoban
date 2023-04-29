#include <stdlib.h>
#include <ncurses.h>
#include "point.h"
#include "colors.h"
#include "entity.h"

struct Entity * create_entity(enum EntityType type, int x, int y) {
  struct Entity * entity = malloc(sizeof(struct Entity));
  entity->type = type;
  entity->x = x;
  entity->y = y;

  switch (type) {
    case BOULDER_TYPE:
      entity->ch = '0';
      entity->color = CYAN;
      break;
    case EXIT_TYPE:
      entity->ch = 'X';
      entity->color = GREEN;
      break;
    case PIT_TYPE:
      entity->ch = '^';
      entity->color = YELLOW;
      break;
    case PLAYER_TYPE:
      entity->ch = '@';
      entity->color = MAGENTA;
      break;
    case WALL_TYPE:
      entity->ch = '#';
      entity->color = WHITE;
      break;
  }
  return entity;
}

void destroy_entity(struct Entity * entity) {
  free(entity);
}

void draw_entity(struct Entity * entity, struct Point * center) {
  attron(COLOR_PAIR(entity->color));
  mvaddch(entity->y + center->y, entity->x + center->x, entity->ch);
  attroff(COLOR_PAIR(entity->color));
}

void move_entity(struct Entity * entity, int x, int y) {
  entity->x = x;
  entity->y = y;
}

