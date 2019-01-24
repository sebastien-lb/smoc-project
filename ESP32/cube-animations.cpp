
#include "cube-animations.hpp"


void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, int color, int delay) {

    setCubeToColor(cube, DARK);
    // only lateral faces
    int faces[4] = {1,2,4,3};
    for (int row = 0; row < 3; ++row) {
        for (int face = 0; face < 4; ++face) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                if (*ledMapping[faces[face]][row][j] >= 0 && cp == face*4 + j) {
                    pixels->setPixelColor(*ledMapping[faces[face]][row][j], getColorConfig(pixels, color));
                } 
            }
        }
        pixels->show();
        delay(delay);
    }

    // top 
    setCubeToColor(color);
    pixels.show();
    delay(delay);    
}


void easterAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping) {

    setCubeToColor(cube, DARK);
    // only lateral faces
    for (int i = 0; i < 100; ++i) {
        pixels->setPixelColor(*ledMapping[random(FACE_NUMBER)][random(FACE_SIZE)][random(FACE_SIZE)], getColorConfig(pixels, random(NB_COLOR)));
        pixels->show();
        delay(100);
    }

}