#include <stdio.h>

int main(void)
{
    float x,value;
    scanf("%f",&x);
    if(x>20)
    {
        value = (x*0.3)+x;
    }else{
        value = (x*0.45)+x;
    }
    printf("%.2f",value);

    return 0;
}