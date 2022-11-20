#ifndef ENTITY_H
#define ENTITY_H

struct Entity {
  char ch;
  int color;
  int x;
  int y;
};

struct Entity * Entity__new(char ch, int color, int x, int y);
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
void EntityList__delete_link(struct Link * list, struct Link * link_to_remove);
void EntityList__delete_element(
  struct Link * list, struct Entity * entity_to_remove
);

#endif
