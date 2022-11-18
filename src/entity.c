#include <stdlib.h>
#include <ncurses.h>
#include "entity.h"
#include "colors.c"

struct Entity * Entity__new(char ch, int color, int x, int y) {
  struct Entity * entity = malloc(sizeof(struct Entity));
  entity->ch = ch;
  entity->color = color;
  entity->x = x;
  entity->y = y;
  return entity;
}

void Entity__destroy(struct Entity * entity) {
  free(entity);
}

void Entity__draw(struct Entity * entity) {
  attron(COLOR_PAIR(entity->color));
  mvaddch(entity->y, entity->x, entity->ch);
  attroff(COLOR_PAIR(entity->color));
}

void Entity__move(struct Entity * entity, int x, int y) {
  entity->x = x;
  entity->y = y;
}

/* struct Link * Link__new(struct Entity * entity) { */
/*   struct Link * link = malloc(sizeof(struct Link)); */
/*   link->element = entity; */
/*   link->next = NULL; */
/*   return link; */
/* } */

/* struct Link * EntityList__new() { */
/*   struct Link * list = malloc(sizeof(struct Link)); */
/*   return list; */
/* } */

/* void EntityList__destroy(struct Link * list) { */
/*  // make sure to free memory for each element */
/*  // for each link */
/*  // and finally for the base link itself */
/* } */

/* void EntityList__push(struct Link * list, struct Entity * entity) { */
/*   struct Link * link = list; */
/*   while (link->next != NULL) link = link->next; */
/*   if (link->element != NULL) { */
/*     struct Link * newLink = Link__new(entity); */
/*     link->next = newLink; */
/*   } else link->element = entity; */
/* } */

/* int EntityList__size(struct Link * list) { */
/*   bool at_end_of_list = false; */

/*   struct Link * node = list; */
/*   int size = 0; */

/*   while (node->element != NULL && at_end_of_list != true) { */
/*     size++; */

/*     if (node->next != NULL) node = node->next; */
/*     else at_end_of_list = true; */
/*   } */
/*   return size; */
/* } */

/* void EntityList__delete_link(struct Link * list, struct Link * link_to_remove) { */
/*   bool at_end_of_list = false; */

/*   struct Link * node = list; */

/*   // what if it's the first node in the list? */
/*   while (node->element != NULL && at_end_of_list != true) { */
/*     struct Link * next = node->next; */
/*     if (next != NULL) { */
/*       if (next == link_to_remove) { */
/*         node->next = link_to_remove->next; */
/*         if (node->element != NULL) free(node->element); */
/*         free(link_to_remove); */
/*         return; */
/*       } else node = node->next; */
/*     } */
/*     else at_end_of_list = true; */
/*   } */
/* } */

/* void EntityList__delete_element( */
/*   struct Link * list, struct Entity * entity */
/* ) { */
/*   bool at_end_of_list = false; */

/*   struct Link * node = list; */

/*   while (node->element != NULL && at_end_of_list != true) { */
/*     struct Link * next = node->next; */
/*     if (next != NULL) { */
/*       if (next->element == entity) { */
/*         EntityList__delete_link(list, next); */
/*       } else node = node->next; */
/*     } */
/*     else at_end_of_list = true; */
/*   } */
/* } */
