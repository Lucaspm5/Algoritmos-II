#include <stdio.h>
#include <math.h>

struct Esfera {
    int raio;
    int x;
    int y;
};

double dist(struct Esfera e1, struct Esfera e2)
{
    return sqrt((e1.x - e2.x) * (e1.x - e2.x) + (e1.y - e2.y) * (e1.y - e2.y));
}

int main()
{
    struct Esfera e1, e2;

    while (scanf("%d %d %d %d %d %d", &e1.raio, &e1.x, &e1.y, &e2.raio, &e2.x, &e2.y) != EOF)
    {
        if (dist(e1, e2) <= (e1.raio - e2.raio))
        {
            printf("RICO\n");
        }
        else
        {
            printf("MORTO\n");
        }
    }

    return 0;
}
