
// Colors definition (later with Color function of adafruit)
#ifndef DEF_SYS_CONF
#define DEF_SYS_CONF

#include "rubiks-cube.h"

// 0 -> led number, 1 -> color number
typedef int pixelColor [2];


pixelColor* getLedColorMap(Cube* cube);


#endif