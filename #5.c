#include <stdio.h>

int main(void)
{
    int m,m2,w,w2;
    int lager=0,lager1=0,smaller = 0,smaller1 = 0;
    scanf("%d%d%i%i",&m,&m2,&w,&w2);
    if(m>m2)
    { 
        lager = m;
        smaller = m2;
    }else{ 
        lager = m2;
        smaller = m;
    }
    if(w>w2) 
    {
        lager1 = w;
        smaller1 = w2;
    }else{ 
        lager1 = w2;
        smaller1 = w;
    }
    ////////////////////
    printf("%d %d",lager+smaller1,lager1*smaller);
    return 0;
}