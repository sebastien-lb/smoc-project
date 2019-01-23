
// Colors definition (later with Color function of adafruit)
#ifndef DEF_SYS_CONF
#define DEF_SYS_CONF

#include "rubiks-cube.hpp"
#include <Adafruit_NeoPixel.h>
#include "colors.hpp"

#define PIN_LED_STRIP 5
#define PIN_POTENTIOMETER A0
#define PIN_BUTTON_AXE 6
#define PIN_BUTTON_ROW 7
#define PIN_LED_INDICATIONS 8

#define NUMPIXELS 3

#define minValuePot 0
#define maxValuePot 1024
#define minEchelle 0
#define maxEchelle 5

void refreshCube(Cube *colorCube, Cube *ledMapping, Adafruit_NeoPixel *pixels);

void setLedMapping(Cube *ledMapping);

#endif
