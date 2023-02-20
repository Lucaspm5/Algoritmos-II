#include <stdio.h>

int main(void)
{
    int number,soma = 0;
    while(number>0)
    {
        scanf("%d",&number);
        soma+=number;
    }
    printf("%d",soma+1);
}