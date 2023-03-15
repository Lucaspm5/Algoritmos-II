include <stdio.h>
#include <math.h>

typedef struct {
    float x1, x2, y1, y2;
} distancia;

int main() {
    float distancia_x, distancia_y, soma, res;
    distancia dois_pontos;

    printf("Digite as coordenadas do primeiro ponto (x1 y1): ");
    scanf("%f %f", &dois_pontos.x1, &dois_pontos.y1);

    printf("Digite as coordenadas do segundo ponto (x2 y2): ");
    scanf("%f %f", &dois_pontos.x2, &dois_pontos.y2);

    distancia_x = dois_pontos.x2 - dois_pontos.x1;
    distancia_y = dois_pontos.y2 - dois_pontos.y1;

    soma = pow(distancia_x, 2) + pow(distancia_y, 2);
    res = sqrt(soma);

    printf("A distancia entre os pontos eh: %.4f\n", res);

    return 0;
}
