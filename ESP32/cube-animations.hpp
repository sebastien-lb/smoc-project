
#ifndef DEF_CUBE_ANIMATIONS
#define DEF_CUBE_ANIMATIONS

#include <Adafruit_NeoPixel.h>
#include "rubiks-cube.hpp"
#include "sys_conf.hpp"

void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, uint8_t color, int delayval);
void easterAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping);

#endif
