
#ifndef DEF_COLORS
#define DEF_COLORS

#include <Adafruit_NeoPixel.h>

#define DARK 0
#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4
#define MAGENTA 5
#define CYAN 6
#define PURPLE 7
#define CYAN2 8
#define PALEGREEN 9
#define ORANGE 10

#define NB_COLOR 11

// transform int color number to real color of adafruit

uint32_t getColorConfig(Adafruit_NeoPixel* pixels, uint8_t colorCode);

#endif
