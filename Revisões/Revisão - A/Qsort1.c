#include <stdio.h>
#include <stdlib.h>

int comparacoes(const long long int *a, const long long int *b);

int main()
{
    long long int qntdcity, qntdpessoas, height;
    scanf("%lld", &qntdcity);
    while(qntdcity--) {
        long long int i;
        scanf("%lld", &qntdpessoas);
        long long int *heights = (long long int*)malloc(qntdpessoas*sizeof(long long int));
        for(i = 0; i < qntdpessoas; i++) {
            scanf("%lld", &height);
            heights[i] = height;
        }
        qsort(heights, qntdpessoas, sizeof(long long int), (int (*)(const void*, const void*))&comparacoes);
        for(size_t i = 0; i < qntdpessoas; i++) {
            printf("%lld", heights[i]);
            if(i < qntdpessoas - 1)
                printf(" ");
        }
        printf("\n");
        free(heights);
    }
    return 0;
}

int comparacoes(const long long int *a, const long long int *b)
{
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}
