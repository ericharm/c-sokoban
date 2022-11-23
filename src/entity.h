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

struct Entity * Entity__new(enum EntityType type, int x, int y);
void Entity__destroy(struct Entity * entity);
void Entity__draw(struct Entity * entity);
void Entity__move(struct Entity * entity, int x, int y);


struct Link {
  struct Entity * element;
  struct Link * next;
};

struct Link * Link__new(struct Entity * element);
struct Link * EntityList__new();
void EntityList__draw(struct Link * list);
void EntityList__destroy(struct Link * list);
void EntityList__push(struct Link * list, struct Entity * entity);
int EntityList__size(struct Link * list);
struct Entity * EntityList__element_at(struct Link * list, int x, int y);
void shift_entity_list(struct Link * list);
void EntityList__delete_element(struct Link * list, struct Entity * entity);

#endif
