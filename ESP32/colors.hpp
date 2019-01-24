
#ifndef DEF_COLORS
#define DEF_COLORS

#include <Adafruit_NeoPixel.h>

#define PURPLE 0
#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4
#define MAGENTA 5
#define CYAN 6

// transform int color number to real color of adafruit

uint32_t getColorConfig(Adafruit_NeoPixel* pixels, int colorCode);

#endif
