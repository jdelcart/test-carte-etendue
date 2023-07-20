#ifndef _PLAYER_H_
#define _PLAYER_H_

struct position
{
	int x;
	int y;
};

struct play
{
	int vie;
	struct position pos;
};

typedef struct play *player;


player createPlayer(int mX, int mY);
void moveLeft(player p);
void moveRight(player p);
void moveUp(player p);
void moveDown(player p);

#endif
