#include <stdio.h>

int main(void)
{
    float amount;
    float profit;
    scanf("%f",&amount);
    if(amount<12) profit = 1.3;
    else profit = 1.0;
    amount *= profit;
    printf("RS %.2f",amount);

    return 0;
}