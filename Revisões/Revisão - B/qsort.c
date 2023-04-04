#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparador(const void *a, const void *b)
{
    int *valor1 = (int*)a;
    int *valor2 = (int*)b;
    return *valor1 - *valor2;
}

int main()
{
    int tamanho;

    srand((unsigned)time(NULL));

    tamanho = rand() % 50;

    int vetor[tamanho];

    printf("Informe os valores do vetor:\n");

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 1000;
    }

    for(int i = 0;i < tamanho;i++){
        printf("%d ",vetor[i]);
    }

    qsort(vetor, tamanho, sizeof(int), comparador);

    printf("Vetor ordenado:\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
