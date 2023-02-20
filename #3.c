#include <stdio.h>

int main(void)
{
    /*
    a=norte
    b=nordeste
    c=centro-oeste
    d=sul
    0=ida ou volta
    1=ida e volta
    */
   char destiny;
   int x;
   scanf("%c%i",&destiny,&x);
    if(destiny == 'a' && x == 0) printf("RS 500.00\n");
    if(destiny == 'a' && x == 1) printf("RS 900.00\n");
    if(destiny == 'b' && x == 0) printf("RS 350.00\n");
    if(destiny == 'b' && x == 1) printf("RS 650.00\n");
    if(destiny == 'c' && x == 0) printf("RS 350.00\n");
    if(destiny == 'c' && x == 1) printf("RS 600.00\n");
    if(destiny == 'd' && x == 0) printf("RS 300.00\n");
    if(destiny == 'd' && x == 1) printf("RS 550.00\n");
    return 0;
}