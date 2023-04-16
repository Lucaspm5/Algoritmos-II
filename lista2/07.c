#include <stdio.h>

int main()
{
    int valores[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int elementos[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    int *p_valores = valores;
    int *p_elementos = elementos;

    printf("Elemento\tValor\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", *(p_elementos + i), *(p_valores + i));
    }

    return 0;
}
