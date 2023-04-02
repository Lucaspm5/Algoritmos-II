#include <stdio.h>

double calculaArea(char operacao, double (*M)[12]);

int main() {
    double M[12][12], ret;
    char T;
    int C, z, p = 6, q = 5;
    scanf("%s", &T);
    for (int i = 0; i <= 11; i++) {
        for (int j = 0; j <= 11; j++)
            scanf("%lf", &M[i][j]);
    }

    ret = calculaArea(T, M);
    printf("%.1lf\n", ret);
    return 0;
}

double calculaArea(char operacao, double (*M)[12]) {
    int C, x, y, z, p = 6, q = 5;
    double a = 0.0;
    for (z = 7; z <= 11; z++) {
        for (C = q; C <= p; C++) {
            a += M[z][C];
        }
        p++;
        q--;
    }
    if (operacao == 'S') {
        return a;
    } else if (operacao == 'M') {
        return a / 30.0;
    }
}
