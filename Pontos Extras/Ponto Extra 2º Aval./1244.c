#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insercao(char** v, int n)
{
    for (int i = 1; i < n; i++) {
        char* key = v[i];
        int j = i - 1;
        while (j >= 0 && strlen(v[j]) < strlen(key))
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main(int argc, char **argv)
{
    int qtd;
    char s[1001];
    char* v[1001];
    char* aux;
    scanf("%d", &qtd);

    getchar();

    while (qtd--)
    {
        int count = 0;
        fgets(s, 1001, stdin);
        aux = strtok(s, " \n");
        while (aux != NULL)
        {
            v[count++] = strdup(aux);
            aux = strtok(NULL, " \n");
        }

        insercao(v, count);

        for (int i = 0; i < count; i++)
        {
            if (i != 0)
                printf(" ");
            printf("%s", v[i]);
            free(v[i]);
        }
        printf("\n");
    }
    return 0;
}
