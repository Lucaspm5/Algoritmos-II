#include <stdio.h>
#include <math.h>

void raizes(float a, float b, float c, float *x1, float *x2) {
    float delta = b * b - 4 * a * c;
    
    if(delta >= 0) {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
    } else {
        *x1 = *x2 = NAN;
    }
}

int main() {
    float a, b, c, x1, x2;
    
    scanf("%f", &a);
    
    while(a != 0) {
        scanf("%f %f", &b, &c);
        raizes(a, b, c, &x1, &x2);
        
        if(isnan(x1) || isnan(x2)) {
            printf("complexo\n");
        } else {
            printf("%.1f %.1f\n", x1, x2);
        }
        
        scanf("%f", &a);
    }
    
    return 0;
}
