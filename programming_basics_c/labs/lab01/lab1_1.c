/*Написати програму для обчислення заданих арифметичних виразів.
Вважати, що X, Y – змінні, значення яких слід вводити з клавіатури, всі інші
величини виразу описати як константи.Де x=3.981, y=-1.625*/
#include <stdio.h>
#include <math.h>
int main()
{
    double x=0, y=0, a;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    a = pow(2, -x)*sqrt(pow(x, -4)+sqrt(fabs(y)));
    printf("x=%lf y=%lf a=%lf\n", x, y, a);
    return 0;   
}




