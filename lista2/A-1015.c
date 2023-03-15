#include <stdio.h>
#include <math.h>

typedef struct
{
    double x,y;
}Ponto;
//////////////////////////////////////////////////////
double distancia(Ponto p1,Ponto p2);
//////////////////////////////////////////////////////
int main(void)
{
    Ponto a,b;

    scanf("%lf %lf %lf %lf",&a.x,&b.x,&a.y,&b.y);

    printf("%.4lf\n",distancia(a,b));

    return 0;
}
//////////////////////////////////////////////////////
double distancia(Ponto p1,Ponto p2)
{
    return sqrt(pow(p1.y-p1.x,2) + pow(p2.y-p2.x,2));
}