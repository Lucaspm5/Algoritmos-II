#include <stdio.h>
#include <math.h>

int main() {
    int r, l, q;
    double v;
    scanf("%d %d", &r, &l);
    v = (12.566 * pow(r, 3)) / 3;
    q = (int) (l / v);
    printf("%d\n", q);
    return 0;
}
