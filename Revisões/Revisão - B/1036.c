#include <stdio.h>
#include <math.h>

typedef struct {
    double r1;
    double r2;
    int exists;
} auxiliary;

auxiliary support(double A, double B, double C)
{
    auxiliary result;
    double delta = (B * B) - 4 * A * C;

    if (delta >= 0 && A != 0) {
        result.r1 = ((B * -1) + sqrt(delta)) / (2 * A);
        result.r2 = ((B * -1) - sqrt(delta)) / (2 * A);
        result.exists = 1;
    } else {
        result.exists = 0;
    }

    return result;
}

void print(auxiliary result)
{
    if (result.exists) {
        printf("R1 = %.5lf\n", result.r1);
        printf("R2 = %.5lf\n", result.r2);
    } else {
        printf("Impossivel calcular\n");
    }
}

int main()
{
    double A, B, C;
    auxiliary result;

    scanf("%lf %lf %lf", &A, &B, &C);

    result = support(A, B, C);
    print(result);

    return 0;
}

