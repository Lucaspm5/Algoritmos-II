#include <stdio.h>

int main() {
    long long fp, fh, mol = 1;

    while (scanf("%lld %lld", &fp, &fh) == 2) {
        long long a = 0, l = 0;

        l = ((fp * 5) + (fh * 6)) / 2;
        a = l + 2 - (fp + fh);

        printf("Molecula #%lld.:.\n", mol);
        printf("Possui %lld atomos e %lld ligacoes\n\n", a, l);

        mol++;
    }

    return 0;
}
