#include <stdio.h>

int main(void)
{
    float x,increment;
    scanf("%f",&x);
    if(x<=600)
    {
        increment = 0;
        printf("%.2f\n%.2f",increment,x);
    }
    else if(x > 600 && x <= 1200)
    {
        increment = (x*0.2);
        printf("%.2f\n%.2f",x*0.2,x-increment);
    }
    else if(x > 1200 && x <= 2000)
    {
        increment = x*0.25;
        printf("%.2f\n%.2f",x*0.25,x-increment);
    }
    else{
        increment = x*0.3;
        printf("%.2f\n%.2f",x*0.3,x-increment);
    }
    return 0;
}