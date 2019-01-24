
#include "cube-animations.hpp"


void chargeAnimation(Adafruit_NeoPixel* pixels, Cube* cube, Cube* ledMapping, int color, int delay) {

    setCubeToColor(cube, DARK);
    // only lateral faces
    int faces[4] = {1,2,4,3};
    for (int row = 0; row < 3; ++row) {
        for (int face = 0; face < 4; ++face) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                if (*ledMapping[face][row][j] >= 0 && cp == face*4 + j) {
                    pixels->setPixelColor(*ledMapping[face][row][j], getColorConfig(pixels, color));
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
