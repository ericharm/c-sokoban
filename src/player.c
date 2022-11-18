#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "entity.h"
#include "colors.c"

struct Entity * Player__new(int x, int y) {
  return Entity__new('@', MAGENTA, x, y);
}

void Player__handle_input(struct Entity * player, int ch) {
  if (ch == KEY_LEFT) player->x--;
  if (ch == KEY_RIGHT) player->x++;
  if (ch == KEY_UP) player->y--;
  if (ch == KEY_DOWN) player->y++;
}
