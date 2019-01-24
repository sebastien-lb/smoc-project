
#ifndef DEF_CUBE_ANIMATIONS
#define DEF_CUBE_ANIMATIONS

#include <Adafruit_NeoPixel.h>
#include "rubiks-cube.hpp"

void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, int color, int delay);
void easterAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping);

#endif
