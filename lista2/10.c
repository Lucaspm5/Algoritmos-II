#include <stdio.h>

char jogo[] = "ABCDEFGHIJKLMNOP",quartas[8], semi[4], final[2], campeao[1];

void partidas(int jogos, char *equipes,char *vencedores)
{
    int time1,time2, aux;
    for(int aux = 0;aux<jogos;aux++)
    {
        scanf("%d%d",&time1,&time2);
        if(time1>time2)
        {
            vencedores[aux] = equipes[aux*2];
        }else{
            vencedores[aux] = equipes[aux*2+1];
        }
    }
}
int main(void)
{
    partidas(8,jogo,quartas);
    partidas(4,quartas,semi);
    partidas(2,semi,final);
    partidas(1,final,campeao);

    printf("%c\n",campeao[0]);
    return 0;
}
