#ifndef _LOADMAP_H_
#define _LOADMAP_H_

#include <stdbool.h>

#define MaxX 39
#define MaxY 80
#define Square_size 30.0

char **map;

bool loadMap(int mX, int mY);

#endif
