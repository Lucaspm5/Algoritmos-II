#include <stdio.h>

#define SIZE 10

int valor[SIZE] = {0};
int elemento[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};


int main() {
    for (int i = 0; i < SIZE; i++){
        if (scanf("%d", &valor[i]) != 1){
            printf("Valor invalido!\n");
            return 1;
        }
    }

    printf("Elemento\t\tValor\t\tHistograma\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%-15d\t%-15d\t", elemento[i], valor[i]);
        for (int j = 0; j < valor[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
