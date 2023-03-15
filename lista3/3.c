#include <stdio.h>
#include <stdlib.h>
#include <time.h>

z = 0;
y = 0;
x = 0;

int gerador()
{

    for (int aux = 0; aux < 100; aux++)
    {
        x = rand() % 2;
        if (x == 1)
        {
            printf("cara \n");
            z++;
        }else if (x == 0)
        {
            printf("coroa \n");
            y++;
        }
    }
}
int main ()
{
    srand(time(NULL));
    gerador();

    printf("Cara apareceu: %d vezes\n", z);
    printf("Coroa apareceu: %d vezes\n", y);
}
