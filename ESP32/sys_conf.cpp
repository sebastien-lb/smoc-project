
#include "sys_conf.hpp"
#include <Adafruit_NeoPixel.h>

void refreshCube(Cube *colorCube, Cube *ledMapping, Adafruit_NeoPixel *pixels){

    Serial.println("Refresh !");
    for (uint8_t face = 0; face < FACE_NUMBER; ++face) {
        for (uint8_t i = 0; i < FACE_SIZE; ++i) {
            for (uint8_t j = 0; j < FACE_SIZE; ++j) {
                if (*ledMapping[face][i][j] >= 0) {
                    pixels->setPixelColor(*ledMapping[face][i][j], getColorConfig(pixels, *colorCube[face][i][j]));
                }
            }
        }
    }

    pixels->show();
}

void setLedMapping(Cube *ledMapping) {
    // init -1 everywhere
    
    for (uint8_t face = 0; face < FACE_NUMBER; ++face) {
        for (uint8_t i = 0; i < FACE_SIZE; ++i) {
            for (uint8_t j = 0; j < FACE_SIZE; ++j) {
                *ledMapping[face][i][j] = -1;
                // *ledMapping[face][i][j] = 9*face + 3*i + j;
            }
        }
    }
    

    // FACE 0
    *ledMapping[0][0][0] = 44;
    *ledMapping[0][0][1] = 39;
    *ledMapping[0][0][2] = 38;

    *ledMapping[0][1][0] = 43;
    *ledMapping[0][1][1] = 40;
    *ledMapping[0][1][2] = 37;

    *ledMapping[0][2][0] = 42;
    *ledMapping[0][2][1] = 41;
    *ledMapping[0][2][2] = 36;

    // FACE 1
    *ledMapping[1][0][0] = 2;
    *ledMapping[1][0][1] = 1;
    *ledMapping[1][0][2] = 0;

    *ledMapping[1][1][0] = 3;
    *ledMapping[1][1][1] = 4;
    *ledMapping[1][1][2] = 5;

    *ledMapping[1][2][0] = 8;
    *ledMapping[1][2][1] = 7;
    *ledMapping[1][2][2] = 6;

    // FACE 2
    *ledMapping[2][0][0] = 11;
    *ledMapping[2][0][1] = 10;
    *ledMapping[2][0][2] = 9;

    *ledMapping[2][1][0] = 12;
    *ledMapping[2][1][1] = 13;
    *ledMapping[2][1][2] = 14;

    *ledMapping[2][2][0] = 17;
    *ledMapping[2][2][1] = 16;
    *ledMapping[2][2][2] = 15;


    // FACE 3
    *ledMapping[3][0][0] = 33;
    *ledMapping[3][0][1] = 34;
    *ledMapping[3][0][2] = 35;

    *ledMapping[3][1][0] = 32;
    *ledMapping[3][1][1] = 31;
    *ledMapping[3][1][2] = 30;

    *ledMapping[3][2][0] = 27;
    *ledMapping[3][2][1] = 28;
    *ledMapping[3][2][2] = 29;

    // FACE 4
    *ledMapping[4][0][0] = 18;
    *ledMapping[4][0][1] = 19;
    *ledMapping[4][0][2] = 20;

    *ledMapping[4][1][0] = 23;
    *ledMapping[4][1][1] = 22;
    *ledMapping[4][1][2] = 21;

    *ledMapping[4][2][0] = 24;
    *ledMapping[4][2][1] = 25;
    *ledMapping[4][2][2] = 26;


}
