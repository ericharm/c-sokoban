#include <stdlib.h>
#include <ncurses.h>
#include "entity.h"
#include "colors.h"

struct Entity * Entity__new(enum EntityType type, int x, int y) {
  struct Entity * entity = malloc(sizeof(struct Entity));
  entity->type = type;
  entity->x = x;
  entity->y = y;

  switch (type) {
    case BOULDER_TYPE:
      entity->ch = '0';
      entity->color = GREEN;
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

struct Link * Link__new(struct Entity * entity) {
  struct Link * link = malloc(sizeof(struct Link));
  link->element = entity;
  link->next = NULL;
  return link;
}

struct Link * EntityList__new() {
  struct Link * list = malloc(sizeof(struct Link));
  return list;
}

void EntityList__destroy(struct Link * list) {
  struct Link * link = list;
  while (link != NULL && link->element != NULL) {
    free(link->element);
    struct Link * next = link->next;
    free(link);
    link = next;
  }
  free(link);
}

void EntityList__draw(struct Link * list) {
  bool at_end_of_list = false;

  struct Link * node = list;

  while (node->element != NULL && at_end_of_list != true) {
    Entity__draw(node->element);
    if (node->next != NULL) node = node->next;
    else at_end_of_list = true;
  }
}

void EntityList__push(struct Link * list, struct Entity * entity) {
  struct Link * link = list;
  while (link->next != NULL) link = link->next;
  if (link->element != NULL) {
    struct Link * newLink = Link__new(entity);
    link->next = newLink;
  } else link->element = entity;
}

int EntityList__size(struct Link * list) {
  bool at_end_of_list = false;

  struct Link * node = list;
  int size = 0;

  while (node->element != NULL && at_end_of_list != true) {
    size++;

    if (node->next != NULL) node = node->next;
    else at_end_of_list = true;
  }
  return size;
}

struct Entity * EntityList__element_at(struct Link * list, int x, int y) {
  bool at_end_of_list = false;

  struct Link * node = list;
  int size = 0;

  while (node->element != NULL && at_end_of_list != true) {
    if (node->element->x == x && node->element->y == y) {
      return node->element;
    }

    if (node->next != NULL) node = node->next;
    else at_end_of_list = true;
  }
  return NULL;
}

// TODO: refactor this mess
void EntityList__delete_link(struct Link * list, struct Link * link_to_remove) {
  // if it's the first node in the list
  if (list == link_to_remove) {
    if (list->next == NULL) list->element = NULL;
    else {
      // free memory from first link's element
      free(list->element);
      struct Link * next = list->next;
      // make first link look like second link
      list->element = next->element;
      list->next = next->next;
      // free memory from second link
      free(next);
    }
    return;
  }

  bool at_end_of_list = false;

  struct Link * node = list;

  while (node->element != NULL && at_end_of_list != true) {
    struct Link * next = node->next;
    if (next != NULL) {
      if (next == link_to_remove) {
        node->next = link_to_remove->next;
        if (node->element != NULL) free(node->element);
        free(link_to_remove);
        return;
      } else node = node->next;
    }
    else at_end_of_list = true;
  }
}

void EntityList__delete_element(
  struct Link * list, struct Entity * entity
) {
  bool at_end_of_list = false;

  struct Link * node = list;

  while (node->element != NULL && at_end_of_list != true) {

    if (node->element == entity) {
      EntityList__delete_link(list, node);
      return;
    }

    struct Link * next = node->next;
    if (next != NULL) {
      if (next->element == entity) {
        EntityList__delete_link(list, next);
        return;
      } else node = node->next;
    }
    else at_end_of_list = true;
  }
}
