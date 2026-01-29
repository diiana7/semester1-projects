/*Не використовуючи оператор циклу скласти програму, яка:
Визначає півсуму максимального та мінімального чисел, які
знаходяться серед 10 введених з клавіатури додатних чисел.*/
#include <stdio.h>
#include <math.h>
int main()
{
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, max=0, min=0;
    float halfsum=0;
    printf("Enter 10 numbers: ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    if (a<0 || b<0 || c<0 || d<0 || e<0 || f<0 || g<0 || h<0 || i<0 || j<0)
    {
        printf("Numbers must be positife\n");
    }
    else
    {
        max= a;
        if (b>max) max=b;
        if (c>max) max=c;
        if (d>max) max=d;
        if (e>max) max=e;
        if (f>max) max=f;
        if (g>max) max=g;
        if (h>max) max=h;
        if (i>max) max=i;
        if (j>max) max=j;
        min= a;
        if (b<min) min=b;
        if (c<min) min=c;
        if (d<min) min=d;
        if (e<min) min=e;
        if (f<min) min=f;
        if (g<min) min=g;
        if (h<min) min=h;
        if (i<min) min=i;
        if (j<min) min=j;

        halfsum = (max + min) / 2.0;
        printf("Halfsum=%.2lf\n", halfsum);
    }
    return 0;
}
