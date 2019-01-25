
#ifndef DEF_RUBIKS_CUBE
#define DEF_RUBIKS_CUBE

#define FACE_NUMBER 6
#define FACE_SIZE 3

#include <stdio.h>

typedef int Line [FACE_SIZE];
typedef Line Face [FACE_SIZE];
typedef Face Cube [FACE_NUMBER];


void rotationX(Cube* cube, uint8_t columnNumber);
void rotationY(Cube* cube, uint8_t rowNumber);
void rotationZ(Cube* cube, uint8_t profNumber);

void setCubeToInitialPosition(Cube* cube);
void setCubeToColor(Cube* cube, uint8_t color);
void displayCube(Cube* cube);



#endif
