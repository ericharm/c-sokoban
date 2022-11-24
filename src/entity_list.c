#include <stdlib.h>
#include <ncurses.h>
#include "point.h"
#include "entity_list.h"
#include "entity.h"

struct Link * _create_link(struct Entity * entity) {
  struct Link * link = malloc(sizeof(struct Link));
  link->element = entity;
  link->next = NULL;
  return link;
}

struct Link * create_entity_list() {
  struct Link * list = malloc(sizeof(struct Link));
  list->element = NULL;
  list->next = NULL;
  return list;
}

void destroy_entity_list(struct Link * list) {
  struct Link * link = list;
  while (link != NULL && link->element != NULL) {
    free(link->element);
    struct Link * next = link->next;
    free(link);
    link = next;
  }
  free(link);
}

void draw_entity_list(struct Link * list, struct Point * center) {
  bool at_end_of_list = false;
  struct Link * node = list;

  while (node->element != NULL && at_end_of_list != true) {
    draw_entity(node->element, center);
    if (node->next != NULL) node = node->next;
    else at_end_of_list = true;
  }
}

void append_to_entity_list(struct Link * list, struct Entity * entity) {
  struct Link * link = list;
  while (link->next != NULL) link = link->next;
  if (link->element != NULL) {
    struct Link * new_link = _create_link(entity);
    link->next = new_link;
  } else link->element = entity;
}

int entity_list_length(struct Link * list) {
  struct Link * node = list;
  if (node->element == NULL) return 0;
  int size = 1;

  while (node->next != NULL) {
    size++;
    node = node->next;
  }
  return size;
}

struct Entity * find_entity_at_point_in_list(struct Link * list, int x, int y) {
  struct Entity * element;
  struct Link * node = list;
  while ((element = node->element) != NULL && node->next != NULL) {
    if (element != NULL && element->x == x && element->y == y) return node->element;
    node = node->next;
  }
  return NULL;
}

void shift_entity_list(struct Link * list) {
  destroy_entity(list->element);
  list->element = NULL;
  if (list->next != NULL) *list = *list->next;
}

void remove_entity_from_list(struct Link * list, struct Entity * entity) {
  struct Link * node = list;
  if (node->element == entity) {
    shift_entity_list(node);
    return;
  }

  while (node->next != NULL) {
    struct Link * next = node->next;
    if (next->element == entity) {
      free(next->element);
      node->next = next->next;
      free(next);
      return;
    }
    node = node->next;
  }
}
