#include <stdio.h>

void calculate_bills(int N, int M, int *bill, int n, int *cndtn)
{
    int net = M - N;
    int i, j;
    *cndtn = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((bill[i] + bill[j]) == net)
            {
                (*cndtn)++;
            }
        }
    }
}

void print_result(int cndtn)
{
    if(cndtn != 2)
    {
        printf("impossible\n");
    }
    else
    {
        printf("possible\n");
    }
}

int main()
{
    int N, M, cndtn;
    int bill[] = {2, 5, 10, 20, 50, 100};
    while(1)
    {
        scanf("%d%d", &N, &M);
        if(N == 0 && M == 0)
        {
            break;
        }
        calculate_bills(N, M, bill, 6, &cndtn);
        print_result(cndtn);
    }
    return 0;
}
