#include <stdio.h>

void ordena_selecao(int vetor[], int tamanho) {
    int i, j, indice_menor, aux;
    for (i = 0; i < tamanho - 1; i++) {
        indice_menor = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }
        if (indice_menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = aux;
        }
    }
}

int main() {
    int vetor[] = { 5, 1, 3, 6, 2, 10 };
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor antes da ordenação por seleção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    ordena_selecao(vetor, tamanho);

    printf("Vetor após a ordenação por seleção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
