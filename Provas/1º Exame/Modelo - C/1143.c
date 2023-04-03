#include <stdio.h>
int main(void) 
{
 int n, aux,m=0,p;
     scanf("%d", &n);
     for ( aux = 1; aux <= n; aux++)
     {
		printf("%i %i %i\n",aux,aux*aux,aux*aux*aux);
     }
    return 0;
}
