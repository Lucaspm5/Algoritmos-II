#include <stdio.h>
#include <math.h>

int bhaskara(float a, float b, float c,float *r1, float *r2) 
{
    float delta = b*b - 4*a*c;
    int raizes_reais = (delta >= 0 ? 1 : 0);

    if(raizes_reais)
    {
        (*r1) = (-b + sqrt(delta))/(2*a);
        (*r2) = (-b - sqrt(delta))/(2*a);
    }

    return raizes_reais;
}

int main(float a, float b, float c)
{
    float r1, r2;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    int raizes_reais;
    raizes_reais = bhaskara(a, b, c, &r1, &r2);
    if(raizes_reais)
        printf("%.1f %.1f\n", r1, r2);
    else
        printf("complexo.\n");
}