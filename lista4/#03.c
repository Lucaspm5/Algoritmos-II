#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int naipe, valor;
}carta;

carta deck[52];

char naipe[][10] = {"Paus", "Ouros", "Copas", "Espadas"};
char numero[][10] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};

void preenche()
{
    int i = 0, j = 0, conta = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++, conta++)
        {
            deck[conta].naipe = i;
            deck[conta].valor = j;
        }
    }
}

void embaralha()
{
    int aux1 = 0, aux2 = 0, val = 0, i = 0;

    for (i = 0; i < 52; i++)
    {
        val = rand() % 52;

        aux1 = deck[i].valor;
        aux2 = deck[i].naipe;

        deck[i].valor = deck[val].valor;
        deck[i].naipe = deck[val].naipe;
        deck[val].valor = aux1;
        deck[val].naipe = aux2;
    }
}

void imprime()
{
    int i = 0, pos = 0, posN = 0;

    for (i = 0; i < 52; i++)
    {
        pos = deck[i].valor;
        posN = deck[i].naipe;
        printf("%s de %s\n", numero[pos], naipe[posN]);
    }

    printf("\n");
}

int main(void)
{
    int opc;

    srand(time(NULL));
    preenche();

    scanf("%d", &opc);

    if (opc == 1)
    {
        imprime();
    }
    else if (opc == 0)
    {
        embaralha();
        imprime();
    }
}

