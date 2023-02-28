#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
int face;
int suit;
};

typedef struct card Card;

void preenche(Card *wDeck, char *wFace, char *wSuit);
void embaralha(Card *wDeck);
void imprime(Card *wDeck);

char face[][20]={"As","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez","Valete","Dama","Rei"};
char suit[][20]={"Copas","Ouros","Paus","Espadas"};


int main()
{
    Card deck[52];

    preenche(deck, face, suit);
    embaralha(deck);
    imprime(deck);

    return 0;
}

void preenche( Card *wDeck, char *wFace, char *wSuit)
{
    int i;
    for(i=0; i<52; i++)
    {
        wDeck[i].face = i % 13;
        wDeck[i].suit = i % 4;
    }
}

void embaralha(Card *wDeck)
{
    int i, j;
    Card temp;
    srand(time(NULL));

    for(i=0; i<52; i++)
    {
        j=rand()%12;
        temp=wDeck[i];
        wDeck[i]=wDeck[j];
        wDeck[j]=temp;
    }
}

void imprime(Card *wDeck)
{
    int i, n, m;

    for(i=0; i<52; i++)
    {
        n=wDeck[i].face;
        m=wDeck[i].suit;
        printf("%s de %s\n",face[n],suit[m]);
    }
}