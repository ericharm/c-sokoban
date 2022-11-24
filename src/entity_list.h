#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

struct Link {
  struct Entity * element;
  struct Link * next;
};

struct Link * create_entity_list();
void draw_entity_list(struct Link * list, struct Point * center);
void destroy_entity_list(struct Link * list);
void append_to_entity_list(struct Link * list, struct Entity * entity);
int entity_list_length(struct Link * list);
struct Entity * find_entity_at_point_in_list(struct Link * list, int x, int y);
void shift_entity_list(struct Link * list);
void remove_entity_from_list(struct Link * list, struct Entity * entity);

#endif
