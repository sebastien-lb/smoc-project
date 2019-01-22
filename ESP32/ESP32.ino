#include "colors.h"
#include "sys_conf.h"
#include "rubiks-cube.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PINLED, NEO_GRB + NEO_KHZ800);

int potentiometerValue = 0;

char axe = 0;
char row = 0;

bool buttonAxeState = false;
bool buttonRowState = false;

Cube *colorCube = malloc(sizeof(Cube));
Cube *ledMapping = malloc(sizeof(Cube));

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
            case 1:
                // rotation Y
                rotationY(colorCube, row);
            case 2:
                // rotation Z
                rotationZ(colorCube, row);
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
            case 1:
                // rotation Y
                rotationY(colorCube, row);
                rotationY(colorCube, row);
                rotationY(colorCube, row);
            case 2:
                // rotation Z
                rotationZ(colorCube, row);
                rotationZ(colorCube, row);
                rotationZ(colorCube, row);
        }
    }

    potentiometerValue = newPotentiometerValue;

    refreshCube(colorCube,ledMapping,&pixels)
}
