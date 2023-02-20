#include <stdio.h> 
int main(void) 
{ 
    int l,c; 
    scanf("%d%d",&l,&c); 
    int array[l],array2[c]; 
    for(int aux = 0;aux < l;aux++) 
    { 
        for(int sup = 0;sup < c;sup++) 
        { 
            printf("*"); 
        }
        printf("\n"); 
        } 
    printf("\n"); 
    return 0; 
}