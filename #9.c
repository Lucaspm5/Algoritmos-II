#include <stdio.h>

int main(void)
{
    int line,colunm;
    scanf("%d%d",&line,&colunm);
    for(int aux = 0; aux < colunm;++aux)
    printf("*");
    printf("\n");
    for(int aux = 0;aux<line-2;++aux)
    {
    printf("*");
    for(int sup = 0;sup<line-1;++sup)
            printf(" ");

    printf("*");
    printf("\n");

    }
    for(int aux = 0;aux<colunm;++aux)
    printf("*");
    printf("\n");
    return 0;
}