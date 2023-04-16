#include <stdio.h>

#define size 10

int main() {
    int sequencia[size];
    int diferentes[size] = {0};
    int i, j, contDiferentes = 0;

    printf("Digite a sequencia de numeros (10 numeros separados por espaco):\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &sequencia[i]);
    }

    for(i = 0; i < size; i++) {
        int repetido = 0;
        for(j = i + 1; j < size; j++) {
            if(sequencia[i] == sequencia[j]) {
                repetido = 1;
                break;
            }
        }
        if(!repetido) {
            diferentes[contDiferentes++] = sequencia[i];
        }
    }

    printf("Numeros diferentes: ");
    for(i = 0; i < contDiferentes; i++) {
        printf("%d ", diferentes[i]);
    }
    printf("\n");

    return 0;
}
