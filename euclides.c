#include <stdio.h>

int main(void)
{
    int x,y,cont = 1,aux,w;
    scanf("%d%d",&x,&y);
    int sup;
    if(x>y)
    {
        sup = x;
        x = y;
        y = sup;
    }
    do
    {
        w = x % y;
        x = y;
        y = w;
        cont++;
    }while(w!=0);
    if(x == 1)
    {
        printf("Numeros primos entre si\n");
    }
    printf("Maximo divisor comum: %d\n",x);
    printf("%d - loops",cont);
    return 0;
}