#include "colors.hpp"
#include <Adafruit_NeoPixel.h>

uint32_t getColorConfig(Adafruit_NeoPixel *pixels, int colorCode){
    switch (colorCode) {
        case DARK:
            return pixels->Color(0, 0, 0);
        case RED:
            return pixels->Color(10, 0, 0);
        case BLUE:
            return pixels->Color(0, 0, 10);
        case GREEN:
            return pixels->Color(0, 10, 0);
        case YELLOW:
            return pixels->Color(5, 5, 0);
        case MAGENTA:
            return pixels->Color(5, 0, 5);
        case CYAN:
            return pixels->Color(0, 5, 5);
        case PURPLE:
            return pixels->Color(8,4,8);
        case CYAN2 :
            return pixels->Color(4,8,8);
        case PALEGREEN :
            return pixels->Color(5,8,5);
        case ORANGE :
            return pixels->Color(8,4,0);
    }
}
