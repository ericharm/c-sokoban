#import "../src/entity.c"
#include <assert.h>

// TODO: move describe to a shared place
void describe_test(char * description) {
  printf("%s", description);
  printf("\n");
}

void test_EntityList__new() {
  describe_test("test_EntityList__new()");
  struct Link * list = EntityList__new();

  assert(EntityList__size(list) == 0);
  assert(list->element == NULL);
  assert(list->next == NULL);
}

void test_EntityList__push() {
  describe_test("test_EntityList__push()");
  struct Link * list = EntityList__new();
  EntityList__push(list, Entity__new('@', 0, 0, 0));

  assert(EntityList__size(list) == 1);
  assert(list->element->ch == '@');
  assert(list->next == NULL);
}

void test_EntityList__delete_link() {
  describe_test("test_EntityList__delete_link()[first of one]");
  struct Link * list = EntityList__new();
  assert(EntityList__size(list) == 0);
  struct Entity * entity = Entity__new('@', 0, 0, 0);
  struct Link * link = Link__new(entity);
  list = link;
  assert(EntityList__size(list) == 1);
  EntityList__delete_link(list, link);
  assert(EntityList__size(list) == 0);
}

void test_EntityList__delete_link_first_of_two() {
  describe_test("test_EntityList__delete_link()[first of two]");

  struct Entity * hero = Entity__new('@', 0, 0, 0);
  struct Entity * wall = Entity__new('#', 0, 0, 0);

  struct Link * hero_link = Link__new(hero);
  struct Link * wall_link = Link__new(wall);

  struct Link * list = hero_link;

  assert(EntityList__size(list) == 1);

  list->next = wall_link;
  assert(EntityList__size(list) == 2);

  EntityList__delete_link(list, hero_link);

  assert(EntityList__size(list) == 1);
  assert(list->element == wall);
}


void test_EntityList__delete_element() {
  describe_test("test deleting element from beginning of list with multiple elements");

  struct Entity * hero = Entity__new('@', 0, 0, 0);
  struct Entity * wall = Entity__new('#', 0, 0, 0);

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

  /* describe_test("test deleting element from beginning of list with one element"); */
  /* describe_test("test deleting element from end of list"); */
  /* describe_test("test deleting element from middle of list"); */


void run_entity_tests() {
  test_EntityList__new();
  test_EntityList__push();
  test_EntityList__delete_link();
  test_EntityList__delete_link_first_of_two();
  test_EntityList__delete_element();
}
