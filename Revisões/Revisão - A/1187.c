#include <stdio.h>

void leitura(double (*M)[12])
{
    int x, y;
    for(x = 0; x <= 11; x++)
    {
        for(y = 0; y <= 11; y++)
            scanf("%lf", &M[x][y]);
    }
}

void calculo(double (*M)[12], char *T)
{
    int C, x, y, z, p = 10, q = 1;
    double a = 0.0;
    for(z = 0; z <= 4; z++)
    {
        for(C = q; C <= p; C++)
        {
            a += M[z][C];
        }
        p--;
        q++;
    }
    if(T[0] == 'S')
    {
        printf("%.1lf\n", a);
    }
    else if(T[0] == 'M')
    {
        a = a / 30.0;
        printf("%.1lf\n", a);
    }
}

int main()
{
    double M[12][12];
    char T[2];
    scanf("%s", &T);
    leitura(M);
    calculo(M, T);
    return 0;
}
