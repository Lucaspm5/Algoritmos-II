#include <stdio.h>

struct Tempo{
    int horas;
    int minutos;
    int segundos;
};

int main() {
    int segundos;

    scanf("%d", &segundos);

    struct Tempo tempo;
    tempo.horas = segundos / 3600;
    tempo.minutos = (segundos % 3600) / 60;
    tempo.segundos = segundos % 60;

    char saida[9];
    sprintf(saida, "%d:%d:%d", tempo.horas, tempo.minutos, tempo.segundos);
    printf("%s\n", saida);

    return 0;
}
