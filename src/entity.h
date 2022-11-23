#ifndef ENTITY_H
#define ENTITY_H

enum EntityType {
  BOULDER_TYPE,
  EXIT_TYPE,
  PIT_TYPE,
  PLAYER_TYPE,
  WALL_TYPE
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


struct Link {
  struct Entity * element;
  struct Link * next;
};

struct Link * create_entity_list();
void draw_entity_list(struct Link * list);
void destroy_entity_list(struct Link * list);
void append_to_entity_list(struct Link * list, struct Entity * entity);
int entity_list_length(struct Link * list);
struct Entity * find_entity_at_point_in_list(struct Link * list, int x, int y);
void shift_entity_list(struct Link * list);
void remove_entity_from_list(struct Link * list, struct Entity * entity);

#endif
