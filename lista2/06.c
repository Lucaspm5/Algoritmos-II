#include <stdio.h>

#define size 2

typedef int matrix[size][size];

int main(void){
    matrix x = {{2, 2}, {2, 2}};
    matrix y = {{2, 2}, {2, 2}};
    matrix resultado = {{0}};

    int i, j, k;

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            for (k = 0; k < size; k++){
                resultado[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
