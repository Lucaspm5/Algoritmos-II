#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, digito, t;
    char str[101], resposta[101];
    while (scanf("%i %s", &n, str) != EOF)
    {
        t = strlen(str);
        for (i = 0, j = 0; i < t; i++)
        {
            digito = str[i] - '0';
            if (n != digito)
            resposta[j++] = str[i];
        }
        for (i = 0; i < j; i++)
        if (resposta[i] != '0')
        break;
        if (j == i)
        printf("0\n");
        else
        {
            for (k = i; k < j; k++)
            printf("%c", resposta[k]);
            printf("\n");
        }
    }
    return 0;
}
