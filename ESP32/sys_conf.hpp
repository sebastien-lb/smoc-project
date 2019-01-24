
// Colors definition (later with Color function of adafruit)
#ifndef DEF_SYS_CONF
#define DEF_SYS_CONF

#include "rubiks-cube.hpp"
#include <Adafruit_NeoPixel.h>
#include "colors.hpp"

#define PIN_LED_STRIP D5
#define PIN_POTENTIOMETER A0
#define PIN_BUTTON_AXE D6
#define PIN_BUTTON_ROW D7
#define PIN_LED_INDICATIONS D8

#define NUMPIXELS 9

#define minValuePot 0
#define maxValuePot 1024
#define minEchelle 0
#define maxEchelle 5

void refreshCube(Cube *colorCube, Cube *ledMapping, Adafruit_NeoPixel *pixels);

void setLedMapping(Cube *ledMapping);

#endif
