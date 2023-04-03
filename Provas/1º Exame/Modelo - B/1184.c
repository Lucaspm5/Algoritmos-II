#include <stdio.h>

double calculaArea(char operacao, double (*M)[12]);

int main() {

    int i, j;
    double matriz[12][12], ret;
    char op;
    scanf("%c",&op);
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
        scanf("%lf",&matriz[i][j]);
        }
    }

ret = calculaArea(op,matriz);
printf("%.1lf\n",ret);

    return 0;
}

double calculaArea(char operacao, double (*M)[12]){
    int i, j;
    double soma = 0.0, cont = 0.0;
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
        if(j<i){
            soma+=M[i][j];
            cont++;
        }
        }
    }

    if(operacao=='S'){
        return soma;
    }
    if(operacao=='M'){
        return soma / cont;
    }

}
