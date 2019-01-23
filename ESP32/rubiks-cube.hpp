
#ifndef DEF_RUBIKS_CUBE
#define DEF_RUBIKS_CUBE

#define FACE_NUMBER 6
#define FACE_SIZE 3

#include <stdio.h>

typedef int Line [FACE_SIZE];
typedef Line Face [FACE_SIZE];
typedef Face Cube [FACE_NUMBER];


void rotationX(Cube* cube, int columnNumber);
void rotationY(Cube* cube, int rowNumber);
void rotationZ(Cube* cube, int profNumber);

void setCubeToInitialPosition(Cube* cube);
void displayCube(Cube* cube);



#endif
