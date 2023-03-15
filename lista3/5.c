#include <stdio.h>
#include <stdlib.h>

int x=0;
int y = 0;
int tentativas = 0;

int repeticao(){
    int lower = 1, upper = 1000;
    x = rand() % (upper - lower + 1) + lower;
    while (y != x)
    {
        scanf("%d", &y);
        if (y < x)
        {
            printf("Muito baixo. Tente Novamente.\n");
            tentativas++;
        }else if (y > x)
        {
            printf("Muito alto. Tente Novamente.\n");
            tentativas++;
        } 
    }
    printf("Excelente! Voce adivinhou o numero!\n");
    printf("Numero de tentativas %d", tentativas);
}


int main()
{
    srand(time(NULL));
    printf("-Advinhe o numero-\n");
    repeticao();
}
