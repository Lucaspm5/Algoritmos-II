#include <stdio.h>

double calculaArea(char operacao, double (*M)[12]);

int main() {
    char op;
    double mat[12][12], t;
    scanf("%s", &op);
    for (int i = 0; i <= 11; i++){
        for (int j = 0; j <= 11; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
    t = calculaArea(op, mat);
    printf("%.1f\n", t);
}

double calculaArea(char operacao, double (*M)[12]){
    int x, y, p = 10;
    double s = 0.0;
    for (x = 0; x <= 10; x++){
        for (y = 0; y <= p; y++){
            s += M[x][y];
        }
        p--;
    }
    if (operacao == 'S') 
        return s;

    if (operacao == 'M') 
    {
        s /= 66.0;
        return s;
    }
}
