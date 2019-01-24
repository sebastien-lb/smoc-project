#include "colors.hpp"
#include "sys_conf.hpp"
#include "rubiks-cube.hpp"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN_LED_STRIP, NEO_GRB + NEO_KHZ800);

int potentiometerValue = 0;

char axe = 0;
char row = 0;

bool buttonAxeState = false;
bool buttonRowState = false;

Cube *colorCube = new Cube[FACE_NUMBER * FACE_SIZE * FACE_SIZE * sizeof(int)];
Cube *ledMapping = new Cube[FACE_NUMBER * FACE_SIZE * FACE_SIZE * sizeof(int)];
// Cube *ledMapping = malloc(sizeof(Cube));

void setup() {
    setCubeToInitialPosition(colorCube);
    setLedMapping(ledMapping);
    pixels.begin();

    pinMode(PIN_BUTTON_AXE, INPUT);
    pinMode(PIN_BUTTON_ROW, INPUT);
}

void loop() {

    bool newButtonAxeState = digitalRead(PIN_BUTTON_AXE);
    bool newButtonRowState = digitalRead(PIN_BUTTON_ROW);

    if (newButtonAxeState && !buttonAxeState) {
        axe = (axe + 1) % 3;
    }

    if (newButtonRowState && !buttonRowState) {
        row = (row + 1) % 3;
    }


    buttonAxeState = newButtonAxeState;
    buttonRowState = newButtonRowState;

    int newPotentiometerValue = map(analogRead(PIN_POTENTIOMETER), minValuePot, maxValuePot, minEchelle, maxEchelle);

    if (newPotentiometerValue > potentiometerValue) {
        // Tourner vers la droite

        switch(axe) {
            case 0:
                // rotation X
                rotationX(colorCube, row);
                break;
            case 1:
                // rotation Y
                rotationY(colorCube, row);
                break;
            case 2:
                // rotation Z
                rotationZ(colorCube, row);
                break;
        }
    }
    else if (newPotentiometerValue < potentiometerValue) {
        // Tourner vers la gauche

        switch (axe) {
            case 0:
                // rotation X
                rotationX(colorCube, row);
                rotationX(colorCube, row);
                rotationX(colorCube, row);
                break;
            case 1:
                // rotation Y
                rotationY(colorCube, row);
                rotationY(colorCube, row);
                rotationY(colorCube, row);
                break;
            case 2:
                // rotation Z
                rotationZ(colorCube, row);
                rotationZ(colorCube, row);
                rotationZ(colorCube, row);
                break;
        }
    }

    potentiometerValue = newPotentiometerValue;

    refreshCube(colorCube,ledMapping,&pixels);
}
