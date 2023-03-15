#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define TAM 6

int a=0, s=0, v=0, p=0, a2=0, s2=0;

char *artigo[TAM] = {"o", "um", "algum", "todo", "qualquer"};
char *substantivo[TAM] = {"menino", "homem", "cachorro", "carro", "gato"};
char *verbo[TAM] = {"passou", "pulou", "correu", "saltos", "andou"};
char *preposicao[TAM] = {"sobre", "sob", "ante", "ate", "com"};
///////////////////////////////////////////////////////////////////////////
char gerador()
{
    srand(time(NULL));
    for (int aux = 0; aux < 20; aux++)
    {
       a = rand() % 5;
       s = rand() % 5;
       v = rand() % 5;
       p = rand() % 5;
       a2 = rand() % 5;
       s2 = rand() % 5;
       printf("%d - %s %s %s %s %s %s\n",aux+1,artigo[a],substantivo[s],verbo[v],preposicao[p],artigo[a2],substantivo[s2]);
       a=0, s=0, v=0, p=0, a2=0, s2=0;
    }
}
int main()
{
    gerador();
}
