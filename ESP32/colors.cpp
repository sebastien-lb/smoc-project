#include "colors.hpp"
#include <Adafruit_NeoPixel.h>

uint32_t getColorConfig(Adafruit_NeoPixel *pixels, int colorCode){
    switch (colorCode) {
        case PURPLE:
          return pixels->Color(8,4,8);
        case RED:
            return pixels.Color(10, 0, 0);
        case BLUE:
            return pixels.Color(0, 0, 10);
        case GREEN:
            return pixels.Color(0, 10, 0);
        case YELLOW:
            return pixels->Color(5, 5, 0);
        case MAGENTA:
            return pixels->Color(5, 0, 5);
        case CYAN:
            return pixels->Color(0, 5, 5);
    }
}