#include <stdio.h>
void par(int x,int y)
{
    int soma = 0,somaimpar = 1,aux;
    if(aux%2 == 0)
    {
        for(int aux = x;aux <= y;aux ++)
        {     
            if(aux%2 == 0)
            {
                soma += aux;
            }else{
                somaimpar *=aux;
            }
        }
    }
            printf("%d\n%d",soma,somaimpar);
}
int main(void)
{
    int z,w;
    scanf("%d%d",&z,&w);
    par(z,w);
    return 0;
}