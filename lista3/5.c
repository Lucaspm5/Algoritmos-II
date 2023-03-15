#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void repeticao(int *x, int *y, int *tentativas){
    int lower = 1, upper = 1000;
    *x = rand() % (upper - lower + 1) + lower;
    while (*y != *x)
    {
        scanf("%d", y);
        if (*y < *x)
        {
            printf("Muito baixo. Tente Novamente.\n");
            (*tentativas)++;
        }
        else if (*y > *x)
        {
            printf("Muito alto. Tente Novamente.\n");
            (*tentativas)++;
        } 
    }
    printf("Excelente! Você adivinhou o número!\n");
    printf("Número de tentativas: %d\n", *tentativas);
}

int main()
{
    srand(time(NULL));
    printf("-Adivinhe o número-\n");
    int x = 0;
    int y = 0;
    int tentativas = 0;
    repeticao(&x, &y, &tentativas);
    return 0;
}
