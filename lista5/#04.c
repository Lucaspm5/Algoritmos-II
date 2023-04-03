#include <stdio.h>

void somaComplexo(float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3);

int main() {
    float rz1, iz1, rz2, iz2, rz3, iz3;
    scanf("%f", &rz1);
    while (rz1 != 0) {
        scanf("%f %f %f", &iz1, &rz2, &iz2);
        somaComplexo(rz1, iz1, rz2, iz2, &rz3, &iz3);
        if (iz3 < 0) {
            printf("%.1f - %.1fi\n", rz3, -iz3);
        } else {
            printf("%.1f + %.1fi\n", rz3, iz3);
        }
        scanf("%f", &rz1);
    }
    return 0;
}

void somaComplexo(float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3) {
    *rz3 = rz1 + rz2;
    *iz3 = iz1 + iz2;
}
