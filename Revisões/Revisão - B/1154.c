#include <stdio.h>
double leInteiros(int n);

    int main()
    {
        int nu;
        double t;
        t = leInteiros(nu);
        printf("%.2f\n",t);

    }
    double leInteiros(int n)
    {
        int c = 0;
        double m, s = 0;
        while(1)
        {
            scanf("%d",&n);
            if(n < 0)
            break;
            c++;
            s += n;
            m = s / c;
        }
        return m;
    }
