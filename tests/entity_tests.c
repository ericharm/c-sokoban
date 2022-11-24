#include <assert.h>
#import "../src/entity.c"
#import "../src/entity_list.c"

void describe_test(char * description) {
  printf("%s", description);
  printf("\n");
}

void test_create_entity_list() {
  describe_test("test create entity list");
  struct Link * list = create_entity_list();

  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);
}

void test_append_to_entity_list() {
  describe_test("test append to entity list");
  struct Link * list = create_entity_list();
  append_to_entity_list(list, create_entity(PLAYER_TYPE, 0, 0));

  assert(entity_list_length(list) == 1);
  assert(list->element->ch == '@');
  assert(list->next == NULL);
}

void test_shift_entity_list() {
  describe_test("test shift entity list");
  struct Link * list = create_entity_list();
  append_to_entity_list(list, create_entity(PLAYER_TYPE, 0, 0));
  append_to_entity_list(list, create_entity(WALL_TYPE, 0, 0));

  assert(entity_list_length(list) == 2);

  shift_entity_list(list);
  assert(entity_list_length(list) == 1);
  assert(list->element->type == WALL_TYPE);
  assert(list->next == NULL);

  shift_entity_list(list);
  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);
}

void test_delete_element_from_beginning_of_list_with_one_element() {
  describe_test("test deleting element from beginning of list with one element");

  struct Link * list = create_entity_list();
  struct Entity * hero = create_entity(PLAYER_TYPE, 0, 0);

  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  append_to_entity_list(list, hero);
  assert(entity_list_length(list) == 1);
  assert(list->element == hero);
  assert(list->next == NULL);

  remove_entity_from_list(list, hero);
  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);
}

void test_delete_element_from_beginning_of_list_with_multiple_elements() {
  describe_test("test deleting element from beginning of list with multiple elements");

  struct Link * list = create_entity_list();
  struct Entity * hero = create_entity(PLAYER_TYPE, 0, 0);
  struct Entity * wall = create_entity(WALL_TYPE, 0, 0);

  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  append_to_entity_list(list, hero);
  assert(entity_list_length(list) == 1);
  assert(list->element == hero);
  assert(list->next == NULL);

  append_to_entity_list(list, wall);
  assert(entity_list_length(list) == 2);
  assert(list->element == hero);
  assert(list->next->element == wall);

  remove_entity_from_list(list, hero);
  assert(entity_list_length(list) == 1);
  assert(list->element == wall);
  assert(list->next == NULL);
}

void test_delete_element_from_end_of_list_with_multiple_elements() {
  describe_test("test deleting element from end of list with multiple elements");

  struct Link * list = create_entity_list();
  struct Entity * hero = create_entity(PLAYER_TYPE, 0, 0);
  struct Entity * wall = create_entity(WALL_TYPE, 0, 0);

  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  append_to_entity_list(list, hero);
  assert(entity_list_length(list) == 1);
  assert(list->element == hero);

  append_to_entity_list(list, wall);
  assert(entity_list_length(list) == 2);
  assert(list->element == hero);

  remove_entity_from_list(list, wall);
  assert(entity_list_length(list) == 1);
  assert(list->element == hero);
}

void test_delete_element_from_middle_of_list() {
  describe_test("test deleting element from middle of list");

  struct Link * list = create_entity_list();
  struct Entity * hero = create_entity(PLAYER_TYPE, 0, 0);
  struct Entity * wall = create_entity(WALL_TYPE, 0, 0);
  struct Entity * boulder = create_entity(BOULDER_TYPE, 0, 0);

  assert(entity_list_length(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);

  append_to_entity_list(list, hero);
  assert(entity_list_length(list) == 1);
  assert(list->element == hero);

  append_to_entity_list(list, wall);
  assert(entity_list_length(list) == 2);
  assert(list->element == hero);

  append_to_entity_list(list, boulder);
  assert(entity_list_length(list) == 3);
  assert(list->element == hero);

  remove_entity_from_list(list, wall);
  assert(entity_list_length(list) == 2);
  assert(list->element == hero);
  assert(list->next->element == boulder);
}

void run_entity_tests() {
  printf("\nExecuting Tests:\n\n");
  test_create_entity_list();
  test_append_to_entity_list();
  test_shift_entity_list();
  test_delete_element_from_beginning_of_list_with_one_element();
  test_delete_element_from_beginning_of_list_with_multiple_elements();
  test_delete_element_from_end_of_list_with_multiple_elements();
  test_delete_element_from_middle_of_list();
  printf("\n");
}
