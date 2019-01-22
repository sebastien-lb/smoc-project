
#define EXIT_SUCCESS 0

#include <stdio.h>
#include "rubiks-cube.h"

int main() {

    Cube* cube = malloc(sizeof(Cube));
    setCubeToInitialPosition(cube);
    displayCube(cube);


    printf("X rotation \n");
    rotationX(cube, 1);
    displayCube(cube);

    printf("Y rotation \n");
    setCubeToInitialPosition(cube);
    rotationY(cube, 0);
    displayCube(cube);

    printf("Z rotation \n");
    setCubeToInitialPosition(cube);
    rotationZ(cube, 2);
    displayCube(cube);
    return EXIT_SUCCESS;
}