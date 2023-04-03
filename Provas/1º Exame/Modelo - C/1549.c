#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int x;
    scanf("%d", &x);
    while (x--) {
        double n, l, r, R, H;
        scanf("%lf %lf %lf %lf %lf", &n, &l, &r, &R, &H);
        double media = l/n;
        double temp = cbrt((media * 3 * (R - r))/(PI * H) + pow(r, 3));
        printf("%.2f\n", media * 3 / (PI * (pow(temp, 2) + temp * r + pow(r, 2))));
    }
    return 0;
}
