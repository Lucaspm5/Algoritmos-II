#include <stdio.h>
#include <math.h>

int main() {
    int n, h, c, l;
    double a;
    while (scanf("%d", &n) == 1) {
        scanf("%d %d %d", &h, &c, &l);
        a = sqrt(pow(h, 2) + pow(c, 2)) * n * l;
        printf("%.4lf\n", a/10000);
    }
    return 0;
}
