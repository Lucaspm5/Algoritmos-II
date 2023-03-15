#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char entrada[100];
    char espacos[199];
    int i, j, cont;

    for (i = 0; i < 100 && (entrada[i] = getchar()) != '\n'; i++) {}
    entrada[i] = '\0';
    cont = i;

    for (i = 0, j = 0; i < cont; i++) {
        espacos[j++] = entrada[i];
        if (i < cont - 1) {
            espacos[j++] = ' ';
        }
    }
    espacos[j] = '\0';

    for (i = 0; espacos[i]; i++) {
        espacos[i] = toupper(espacos[i]);
    }

    printf("%s", espacos);

    return 0;
}