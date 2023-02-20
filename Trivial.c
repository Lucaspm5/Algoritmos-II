#include <stdio.h>

int main(void)
{
    int x,y,cont = 0,aux;
    scanf("%d%d",&x,&y);
    int sup,d = y;
    do
    {
        d--;
        cont++;
    }while( x % d != 0 || y % d !=0 );
    if(d == 1)
    {
        printf("Numero primo\n");
    }
    printf("MDC(%d,%d) = %d\n",x,y,d);
    printf("%d - loops",cont);
    return 0;
}