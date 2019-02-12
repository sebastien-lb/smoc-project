
#include "rubiks-cube.hpp"


// ----- Face representation
// always from top to bottom (or back to front for 1 and 6)

// ------ Cube representation
//
//   ______
//   |\   0 \   4 is behind
//   | \_____\
//    \ |  1  |  3 is right
//  2  \|_____|
//
//        5 is above

// ----- Rotations
//
//      y ^
//        |
//        |____ x
//     z /
//

void rotationX(Cube* cube, uint8_t columnNumber) {
    if ( columnNumber > FACE_SIZE || columnNumber < 0) {
        return;
    }
    uint8_t temp;
    for (uint8_t i = 0; i < FACE_SIZE; ++i) {
        temp = *cube[0][i][columnNumber];
        *cube[0][i][columnNumber] = *cube[1][i][columnNumber];
        *cube[1][i][columnNumber] = *cube[5][FACE_SIZE-1-i][columnNumber];
        *cube[5][FACE_SIZE-1-i][columnNumber] = *cube[4][FACE_SIZE-1-i][columnNumber];
        *cube[4][FACE_SIZE-1-i][columnNumber] = temp;
    }

    if(columnNumber == 2) { 
        rotateFace(cube, 3);
    } else if (columnNumber == 0) {
        rotateFace(cube, 2);
    }
}

void rotationY(Cube* cube, uint8_t rowNumber) {
    if ( rowNumber > FACE_SIZE || rowNumber < 0) {
        return;
    }
    uint8_t temp;
    for (uint8_t i = 0; i < FACE_SIZE; ++i) {
        temp = *cube[1][rowNumber][i];
        *cube[1][rowNumber][i] = *cube[2][rowNumber][i];
        *cube[2][rowNumber][i] = *cube[4][rowNumber][i];
        *cube[4][rowNumber][i] = *cube[3][rowNumber][i];
        *cube[3][rowNumber][i] = temp;
    }

    if(rowNumber == 2) { 
        rotateFace(cube, 5);
    } else if (rowNumber == 0) {
        rotateFace(cube, 0);
    }
}

void rotationZ(Cube* cube, uint8_t profNumber) {
    if ( profNumber > FACE_SIZE || profNumber < 0) {
        return;
    }
    uint8_t temp;
    for(uint8_t i = 0; i < FACE_SIZE; ++i){
        temp = *cube[0][profNumber][i];
        *cube[0][profNumber][i] = *cube[3][FACE_SIZE-1-i][profNumber];
        *cube[3][FACE_SIZE-1-i][profNumber] = *cube[5][profNumber][i];
        *cube[5][profNumber][i] = *cube[2][FACE_SIZE-1-i][profNumber];
        *cube[2][FACE_SIZE-1-i][profNumber] = temp;
    }

    if(profNumber == 2) { 
        rotateFace(cube, 1);
    } else if (profNumber == 0) {
        rotateFace(cube, 4);
    }
}

void rotateFace(Cube* cube, uint8_t faceNumber) {
    uint8_t temp = *cube[faceNumber][0][0];
    *cube[faceNumber][0][0] = *cube[faceNumber][0][2];
    *cube[faceNumber][0][2] = *cube[faceNumber][2][2];
    *cube[faceNumber][2][2] = *cube[faceNumber][2][0];
    *cube[faceNumber][2][0] = temp;
    
    temp = *cube[faceNumber][0][1];
    *cube[faceNumber][0][1] = *cube[faceNumber][1][2];
    *cube[faceNumber][1][2] = *cube[faceNumber][2][1];
    *cube[faceNumber][2][1] = *cube[faceNumber][1][0];
    *cube[faceNumber][1][0] = temp;
}

void setCubeToInitialPosition(Cube* cube) {
    for (uint8_t i = 0; i < FACE_NUMBER; ++i) {
        for (uint8_t j = 0; j < FACE_SIZE ; ++j) {
            for (uint8_t k = 0; k < FACE_SIZE ; ++k) {
                if (i == 0) {
                  *cube[i][j][k] = BLUE;
                } else if (i == 1) {
                  *cube[i][j][k] = RED;
                } else if (i == 2) {
                  *cube[i][j][k] = GREEN;
                } else if (i == 3) {
                  *cube[i][j][k] = YELLOW;
                } else if (i == 4) {
                  *cube[i][j][k] = MAGENTA;
                } else if (i == 5) {
                  *cube[i][j][k] = PALEGREEN;
                } else {
                  *cube[i][j][k] = DARK;
                }
                
            }
        }
    }
}

void setCubeToColor(Cube* cube, uint8_t color) {
    for (uint8_t i = 0; i < FACE_NUMBER; ++i) {
        for (uint8_t j = 0; j < FACE_SIZE ; ++j) {
            for (uint8_t k = 0; k < FACE_SIZE ; ++k) {
                *cube[i][j][k] = color;
            }
        }
    }
}


void displayCube(Cube* cube) {
    for (uint8_t i = 0; i < FACE_NUMBER; ++i) {
        printf("\n face : %d \n", i);
        for (uint8_t j = 0; j < FACE_SIZE ; ++j) {
            printf("\n");
            for (uint8_t k = 0; k < FACE_SIZE ; ++k) {
                printf(" %d ", *cube[i][j][k]);
            }
        }
        printf("\n ");
    }
}
