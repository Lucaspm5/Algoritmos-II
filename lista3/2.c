#include <stdio.h>
#include <math.h>
float coord(float x1,float y1,float x2,float y2)
{
    float d;
    d=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    return d;
}
int main() 
{
   float x1, y1, x2, y2, d;
   scanf("%f %f", &x1, &y1);
   scanf("%f %f", &x2, &y2);
   printf("%.4f\n",coord(x1,y1,x2,y2));
   return 0;
}
