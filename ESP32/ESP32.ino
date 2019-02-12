#include "colors.hpp"
#include "sys_conf.hpp"
#include "rubiks-cube.hpp"
#include "cube-animations.hpp"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN_LED_STRIP, NEO_GRB + NEO_KHZ800);

uint8_t potentiometerValue = 0;

uint8_t axe = 0;
uint8_t row = 0;

bool buttonAxeState = false;
bool buttonRowState = false;

Cube *colorCube = new Cube[6];
Cube *ledMapping = new Cube[6];

void setup() {
    Serial.begin(115200);
    Serial.print("Initialization !");

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

    // Serial.print("Valeur axe: ");
    // Serial.println(axe);

    // Serial.print("Valeur ligne: ");
    // Serial.println(row);

    buttonAxeState = newButtonAxeState;
    buttonRowState = newButtonRowState;

    uint8_t newPotentiometerValue = map(analogRead(PIN_POTENTIOMETER), minValuePot, maxValuePot, minEchelle, maxEchelle);

    // Serial.print("Valeur potentiometre: ");
    // Serial.println(newPotentiometerValue);
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

    chargeAnimation(&pixels, colorCube, ledMapping, ORANGE, 300);
    
    setCubeToInitialPosition(colorCube);
    delay(2000);

    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationX(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationX(colorCube, 1);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationZ(colorCube, 2);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationZ(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(8000);
    

    setCubeToInitialPosition(colorCube);
    delay(2000);

    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationY(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationY(colorCube, 1);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationX(colorCube, 2);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationX(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(8000);
    

    setCubeToInitialPosition(colorCube);
    delay(2000);

    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationZ(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationZ(colorCube, 1);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationY(colorCube, 2);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(2000);
    rotationY(colorCube, 0);
    refreshCube(colorCube,ledMapping,&pixels);
    delay(8000);
}
