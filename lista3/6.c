#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main()
{
    char *artigo[TAM] = {"o", "um", "algum", "todo", "qualquer"};
    char *substantivo[TAM] = {"menino", "homem", "cachorro", "carro", "gato"};
    char *verbo[TAM] = {"passou", "pulou", "correu", "saltou", "andou"};
    char *preposicao[TAM] = {"sobre", "sob", "ante", "ate", "com"};

    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        int a = rand() % TAM;
        int s = rand() % TAM;
        int v = rand() % TAM;
        int p = rand() % TAM;

        printf("%d - %s %s %s %s %s %s\n", i+1, artigo[a], substantivo[s], verbo[v], preposicao[p], artigo[a], substantivo[s]);
    }

    return 0;
}
