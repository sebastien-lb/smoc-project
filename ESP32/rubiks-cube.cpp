
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

void rotationX(Cube* cube, int columnNumber) {
    if ( columnNumber > FACE_SIZE || columnNumber < 0) {
        return;
    }
    int temp;
    for (int i = 0; i < FACE_SIZE; ++i) {
        temp = *cube[0][i][columnNumber];
        *cube[0][i][columnNumber] = *cube[1][i][columnNumber];
        *cube[1][i][columnNumber] = *cube[5][FACE_SIZE-1-i][columnNumber];
        *cube[5][FACE_SIZE-1-i][columnNumber] = *cube[4][FACE_SIZE-1-i][columnNumber];
        *cube[4][FACE_SIZE-1-i][columnNumber] = temp;
    }
}

void rotationY(Cube* cube, int rowNumber) {
    if ( rowNumber > FACE_SIZE || rowNumber < 0) {
        return;
    }
    int temp;
    for (int i = 0; i < FACE_SIZE; ++i) {
        temp = *cube[1][rowNumber][i];
        *cube[1][rowNumber][i] = *cube[2][rowNumber][i];
        *cube[2][rowNumber][i] = *cube[4][rowNumber][i];
        *cube[4][rowNumber][i] = *cube[3][rowNumber][i];
        *cube[3][rowNumber][i] = temp;
    }
}

void rotationZ(Cube* cube, int profNumber) {
    if ( profNumber > FACE_SIZE || profNumber < 0) {
        return;
    }
    int temp;
    for(int i = 0; i < FACE_SIZE; ++i){
        temp = *cube[0][profNumber][i];
        *cube[0][profNumber][i] = *cube[3][FACE_SIZE-1-i][profNumber];
        *cube[3][FACE_SIZE-1-i][profNumber] = *cube[5][profNumber][i];
        *cube[5][profNumber][i] = *cube[2][FACE_SIZE-1-i][profNumber];
        *cube[2][FACE_SIZE-1-i][profNumber] = temp;
    }
}

void setCubeToInitialPosition(Cube* cube) {
    for (int i = 0; i < FACE_NUMBER; ++i) {
        for (int j = 0; j < FACE_SIZE ; ++j) {
            for (int k = 0; k < FACE_SIZE ; ++k) {
                *cube[i][j][k] = i;
            }
        }
    }
}

void setCubeToColor(Cube* cube, int color) {
    for (int i = 0; i < FACE_NUMBER; ++i) {
        for (int j = 0; j < FACE_SIZE ; ++j) {
            for (int k = 0; k < FACE_SIZE ; ++k) {
                *cube[i][j][k] = color;
            }
        }
    }
}


void displayCube(Cube* cube) {
    for (int i = 0; i < FACE_NUMBER; ++i) {
        printf("\n face : %d \n", i);
        for (int j = 0; j < FACE_SIZE ; ++j) {
            printf("\n");
            for (int k = 0; k < FACE_SIZE ; ++k) {
                printf(" %d ", *cube[i][j][k]);
            }
        }
        printf("\n ");
    }
}
