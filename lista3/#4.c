#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int rollDice(void)
{
    int aux1, aux2, sup;
    aux1 = 1 + (rand() % 6);
    aux2 = 1 + (rand() % 6);
    sup = aux1 + aux2;
    printf("Jogador obteve %d + %d = %d\n", aux1, aux2, sup);
    return sup;
}
///////////////////////////////////////////////////////////////
int main()
{
    int var, sup, win;
    srand(time(NULL));
    sup = rollDice();
    switch(sup)
    {
        case 7:
        case 11:
        var = 1;
        break;
        case 2:
        case 3:
        case 12:
        var = 2;
        break;
        default:
        var = 0;
        win = sup;
        printf("O ponto e %d\n", win);
        break;
    }
    while (var == 0)
    {
        sup = rollDice();
        if(sup == win)
        var = 1;
        else
        if(sup == 7)
        var = 2;
    }
    if(var == 1)
        printf("Jogador vence\n") ;
    else
        printf("Jogador perde\n");
    return 0;
}
 
