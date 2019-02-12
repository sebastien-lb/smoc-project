
#include "cube-animations.hpp"
#include "colors.hpp"

void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, uint8_t color, int delayVal) {

    setCubeToColor(cube, DARK);
    pixels->show();
    delay(delayVal);
    // only lateral faces
    uint8_t faces[4] = {1,2,4,3};
    for (uint8_t row = 0; row < 3; ++row) {
        for (uint8_t face = 0; face < 4; ++face) {
            for (uint8_t j = 0; j < FACE_SIZE; ++j) {
                if (*ledMapping[faces[face]][2-row][j] >= 0) {
                    pixels->setPixelColor(*ledMapping[faces[face]][2-row][j], getColorConfig(pixels, color));
                }
            }
        }
        pixels->show();
        delay(delayVal);
    }

    // top
    for (uint8_t i = 0; i < 3; ++i) {
      for (uint8_t j = 0; j < 3; j++) {
        if (*ledMapping[0][i][j] >= 0) {
            pixels->setPixelColor(*ledMapping[0][i][j], getColorConfig(pixels, color));
        }
      }
    }
    
    pixels->show();
    delay(delayVal);
    setCubeToColor(cube, DARK);
    refreshCube(cube, ledMapping, pixels);
    delay(delayVal);
    setCubeToColor(cube, BLUE);
    refreshCube(cube, ledMapping, pixels);
    delay(delayVal);
    setCubeToColor(cube, DARK);
    refreshCube(cube, ledMapping, pixels);
    delay(delayVal);
    setCubeToColor(cube, BLUE);
    refreshCube(cube, ledMapping, pixels);
    delay(delayVal);
}


void easterAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping) {

    setCubeToColor(cube, DARK);
    // only lateral faces
    for (uint8_t i = 0; i < 100; ++i) {
        for (uint8_t j = 0; j < random(1,3); j++) {
            pixels->setPixelColor(*ledMapping[random(FACE_NUMBER)][random(FACE_SIZE)][random(FACE_SIZE)], getColorConfig(pixels, random(NB_COLOR)));
        }
        pixels->show();
        delay(100);
    }

}
