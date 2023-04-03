#include <stdio.h>
#include <stdlib.h>

#define MAX 1010

typedef struct {
    int x, y;
} ponto;

long long sqr(long long v) { return v * v; }


int compare(const void* a, const void* b) {
    const long long* p1 = (const long long*) a;
    const long long* p2 = (const long long*) b;
    return (*p1 > *p2) - (*p1 < *p2);
}

int main(void) {
    ponto pontos[MAX];
    long long T[MAX][MAX];

    int n;
    while (1) {
        scanf("%d", &n);
        if (!n) return 0;

        for (int i = 0; i < n; ++i)
            scanf("%d %d", &pontos[i].x, &pontos[i].y);

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int aux = 0;
            for (int j = 0; j < n; ++j)
                T[i][aux++] = sqr(pontos[i].x - pontos[j].x) + sqr(pontos[i].y - pontos[j].y);

            qsort(T[i], aux, sizeof(long long), compare);
            long long last = -1LL;
            int cnt = 0;

            for (int j = 0; j < aux; ++j) {
                if (T[i][j] != last) {
                    sum += (cnt * (cnt - 1)) / 2;
                    cnt = 0;
                }
                last = T[i][j];
                cnt++;
            }
            sum += (cnt * (cnt - 1)) / 2;
        }

        printf("%lld\n", sum);
    }
    return 0;
}


