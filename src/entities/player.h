#ifndef PLAYER_H
#define PLAYER_H

struct Entity * Player__new(int x, int y);
void Player__handle_input(struct Entity * player, int ch);

#endif
