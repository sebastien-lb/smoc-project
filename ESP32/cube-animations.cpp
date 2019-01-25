
#include "cube-animations.hpp"
#include "colors.hpp"

void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, uint8_t color, uint8_t delayVal) {

    setCubeToColor(cube, DARK);
    // only lateral faces
    uint8_t faces[4] = {1,2,4,3};
    for (uint8_t row = 0; row < 3; ++row) {
        for (uint8_t face = 0; face < 4; ++face) {
            for (uint8_t j = 0; j < FACE_SIZE; ++j) {
                if (*ledMapping[faces[face]][row][j] >= 0) {
                    pixels->setPixelColor(*ledMapping[faces[face]][row][j], getColorConfig(pixels, color));
                }
            }
        }
        pixels->show();
        delay(delayVal);
    }

    // top
    setCubeToColor(cube, color);
    pixels->show();
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
