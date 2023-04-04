#include <stdio.h>

void read(double (*M)[12])
{
    int x, y;

    for (x = 0; x < 12; x++) {
        for (y = 0; y < 12; y++) {
            scanf("%lf", &M[x][y]);
        }
    }
}

double auxiliary(double (*M)[12])
{
    int z, C, p = 11;
    double sum = 0.0;

    for (z = 1; z <= 11; z++) {
        for (C = 11; C >= p; C--) {
            sum += M[z][C];
        }
        p--;
    }

    return sum;
}

int main()
{
    double M[12][12];
    char T[2];
    double sum;

    scanf("%s", T);
    read(M);
    sum = auxiliary(M);

    if (T[0] == 'S') {
        printf("%.1lf\n", sum);
    } else if (T[0] == 'M') {
        double average = sum / 66.0;
        printf("%.1lf\n", average);
    }

    return 0;
}
