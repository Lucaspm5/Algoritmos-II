#include <stdio.h>

#define MATRIX_SIZE 2

typedef int matrix[MATRIX_SIZE][MATRIX_SIZE];

int main(void){
    matrix x = {{2, 2}, {2, 2}};
    matrix y = {{2, 2}, {2, 2}};
    matrix resultado = {{0}};

    int i, j, k;

    for (i = 0; i < MATRIX_SIZE; i++){
        for (j = 0; j < MATRIX_SIZE; j++){
            for (k = 0; k < MATRIX_SIZE; k++){
                resultado[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    for (i = 0; i < MATRIX_SIZE; i++){
        for (j = 0; j < MATRIX_SIZE; j++){
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
