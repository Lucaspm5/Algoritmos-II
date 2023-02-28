#include <stdio.h>

void cubo(int *nPrt)
{

    *nPrt = *nPrt * *nPrt * *nPrt;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    cubo(&x);
    printf("%i", x);
}
