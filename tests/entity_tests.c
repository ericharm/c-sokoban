#import "../src/entity.c"
#include <assert.h>

// TODO: move describe to a shared place
void describe_test(char * description) {
  printf("%s", description);
  printf("\n");
}

void test_create_entity_list() {
  describe_test("test create entity list");
  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);
}

void test_append_to_entity_list() {
  describe_test("test append to entity list");
  struct Link * list = EntityList__new();
  EntityList__push(list, Entity__new(PLAYER_TYPE, 0, 0));

  assert(EntityList__size(list) == 1);
  assert(list->element->ch == '@');
  assert(list->next == NULL);
}

void test_shift_entity_list() {
  describe_test("test shift entity list");
  struct Link * list = EntityList__new();
  EntityList__push(list, Entity__new(PLAYER_TYPE, 0, 0));
  EntityList__push(list, Entity__new(WALL_TYPE, 0, 0));

  assert(EntityList__size(list) == 2);

  shift_entity_list(list);
  assert(EntityList__size(list) == 1);
  assert(list->element->type == WALL_TYPE);

  shift_entity_list(list);
  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
}

void test_delete_element_from_beginning_of_list_with_one_element() {
  describe_test("test deleting element from beginning of list with one element");

  struct Entity * hero = Entity__new(PLAYER_TYPE, 0, 0);

  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  EntityList__push(list, hero);
  assert(EntityList__size(list) == 1);
  assert(list->element == hero);

  EntityList__delete_element(list, hero);
  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
}

void test_delete_element_from_beginning_of_list_with_multiple_elements() {
  describe_test("test deleting element from beginning of list with multiple elements");

  struct Entity * hero = Entity__new(PLAYER_TYPE, 0, 0);
  struct Entity * wall = Entity__new(WALL_TYPE, 0, 0);

  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  EntityList__push(list, hero);
  assert(EntityList__size(list) == 1);
  assert(list->element == hero);

  EntityList__push(list, wall);
  assert(EntityList__size(list) == 2);
  assert(list->element == hero);

  EntityList__delete_element(list, hero);
  assert(EntityList__size(list) == 1);
  assert(list->element == wall);
}

void test_delete_element_from_end_of_list_with_multiple_elements() {
  describe_test("test deleting element from end of list with multiple elements");

  struct Entity * hero = Entity__new(PLAYER_TYPE, 0, 0);
  struct Entity * wall = Entity__new(WALL_TYPE, 0, 0);

  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  EntityList__push(list, hero);
  assert(EntityList__size(list) == 1);
  assert(list->element == hero);

  EntityList__push(list, wall);
  assert(EntityList__size(list) == 2);
  assert(list->element == hero);

  EntityList__delete_element(list, wall);
  assert(EntityList__size(list) == 1);
  assert(list->element == hero);
}

void test_delete_element_from_middle_of_list() {
  describe_test("test deleting element from middle of list");

  struct Entity * hero = Entity__new(PLAYER_TYPE, 0, 0);
  struct Entity * wall = Entity__new(WALL_TYPE, 0, 0);
  struct Entity * boulder = Entity__new(BOULDER_TYPE, 0, 0);

  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  EntityList__push(list, hero);
  assert(EntityList__size(list) == 1);
  assert(list->element == hero);

  EntityList__push(list, wall);
  assert(EntityList__size(list) == 2);
  assert(list->element == hero);

  EntityList__push(list, boulder);
  assert(EntityList__size(list) == 3);
  assert(list->element == hero);

  EntityList__delete_element(list, wall);
  assert(EntityList__size(list) == 2);
  assert(list->element == hero);
  assert(list->next->element == boulder);
}


void run_entity_tests() {
  test_create_entity_list();
  test_append_to_entity_list();
  test_shift_entity_list();
  test_delete_element_from_beginning_of_list_with_one_element();
  test_delete_element_from_beginning_of_list_with_multiple_elements();
  test_delete_element_from_end_of_list_with_multiple_elements();
  test_delete_element_from_middle_of_list();
}
