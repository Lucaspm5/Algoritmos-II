#include <stdio.h>

double sum(double (*matrix)[12]) 
{
    double s = 0.0;
    for (int i = 1; i <= 11; i++){
        for (int j = 0; j < i; j++)
            s += matrix[i][j];
    }
    return s;
}

int main(int argc, char **argv) 
{
    double M[12][12];
    char T[2];

    for (int i = 0; i <= 11; i++){
        for (int j = 0; j <= 11; j++)
            scanf("%lf", &M[i][j]);
    }
    scanf("%s", T);
    if (T[0] == 'S')
        printf("%.1lf\n", sum(M));
    else if (T[0] == 'M')
        printf("%.1lf\n", sum(M) / 66.0);

    return 0;
}
