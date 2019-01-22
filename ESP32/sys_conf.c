
#include "sys_conf.h"
#include <Adafruit_NeoPixel.h>

void refreshCube(Cube *colorCube, Cube *ledMapping, Adafruit_NeoPixel *pixels){

    for (int face = 0; face < FACE_NUMBER; ++face) {
        for (int i = 0; i < FACE_SIZE; ++i) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                if (ledMapping[face][i][j] >= 0) {
                    pixels->setPixelColor(ledMapping[face][i][j], getColorConfig(pixels, colorCube[face][i][j]));
                }
            }
        }
    }

    pixels->show();
}

void setLedMapping(Cube *ledMapping) {
    // init -1 everywhere

    for (int face = 0; face < FACE_NUMBER; ++face) {
        for (int i = 0; i < FACE_SIZE; ++i) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                *ledMapping[face][i][j] = -1;
            }
        }
    }

    *ledMapping[0][0][0] = 0;
    *ledMapping[0][0][1] = 1;
    *ledMapping[0][0][2] = 2;
}
