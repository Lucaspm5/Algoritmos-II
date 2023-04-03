#include <stdio.h>
#include <math.h>

int is_prime(int numero) {
    if(numero < 2)
        return 0;
    if(numero == 2)
        return 1;
    if(numero % 2 == 0)
        return 0;
    int limite = sqrt(numero);
    for(int i = 3; i <= limite; i += 2) {
        if(numero % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int numero;
        scanf("%d", &numero);
        if(is_prime(numero))
            printf("%d eh primo\n", numero);
        else
            printf("%d nao eh primo\n", numero);
    }
    return 0;
}
