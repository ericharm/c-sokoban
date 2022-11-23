#ifndef ENTITY_H
#define ENTITY_H

enum EntityType {
  BOULDER_TYPE, EXIT_TYPE, PIT_TYPE, PLAYER_TYPE, WALL_TYPE
};

struct Entity {
  char ch;
  int color;
  enum EntityType type;
  int x;
  int y;
};

struct Entity * create_entity(enum EntityType type, int x, int y);
void destroy_entity(struct Entity * entity);
void draw_entity(struct Entity * entity);
void move_entity(struct Entity * entity, int x, int y);

#endif
