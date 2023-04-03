#include <stdio.h>
#include <string.h>

#define MAX_PALAVRAS 10000

int main() {
    int n, qp, i, j;
    char palavras[MAX_PALAVRAS][21];
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &qp);
        for (i = 0; i < qp; i++) {
            scanf("%s", palavras[i]);
        }
        int eh_ingles = 0;
        for (i = 1; i < qp; i++) {
            if (strcmp(palavras[i], palavras[i - 1]) != 0) {
                eh_ingles = 1;
                break;
            }
        }
        if (eh_ingles) {
            printf("ingles\n");
        } else {
            printf("%s\n", palavras[0]);
        }
    }
    return 0;
}
