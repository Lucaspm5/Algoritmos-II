#include<stdio.h>
#include<math.h>

struct distancia
{
    float x1,x2,y1,y2;
};

int main()
{
    float subx1,suby2;
    float mutx1,muty2;
    float soma,res;
    float total;


    struct distancia dois_pontos;
    fflush(stdin);
    scanf("%f %f",&dois_pontos.x1,&dois_pontos.x2);
    fflush(stdin);
    scanf("%f %f",&dois_pontos.y1,&dois_pontos.y2);

    subx1=dois_pontos.x1 - dois_pontos.y1;
    suby2=dois_pontos.x2 - dois_pontos.y2;
    mutx1=subx1*subx1;
    muty2=suby2*suby2;
    soma=mutx1+muty2;
    res=sqrt(soma);
    total=res;
    printf("%.4f",total);
    return 0;
}