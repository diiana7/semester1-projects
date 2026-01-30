#include <stdio.h>
#include <math.h>
#include "function.h"

// ф-я обчислення виразу 
double f(double x) {
    return pow(1 + sin(2 * x), 2);
}

// Табуляція f(x) 
void tabulate1(double a, double b, double h) {
    printf("\nTabulate f(x) = (1 + sin(2x))^2\n");
    printf("-----------------------------------------\n");
    printf("     x\t\t\tf(x)\n");
    printf("-----------------------------------------\n");

    for (double x = a; x <= b + 1e-12; x += h) {
        printf("%10.6f\t%12.8f\n", x, f(x));
        if (x >= b) break;
    }
}

// Обчислення f(x) + повернення знаку
int compute(double x, double *result) {
    double y = f(x);
    *result = y;
    if (y < 0) return -1;
    else if (y == 0) return 0;
    else return 1;
}

// Табуляція compute(x, &y)
void tabulate2(double a, double b, double h) {
    printf("\nTabulate with a sign:\n");
    printf("-----------------------------------------------\n");
    printf("     x\t\t\tf(x)\t\t sign\n");
    printf("-----------------------------------------------\n");

    for (double x = a; x <= b + 1e-12; x += h) {
        double y;
        int sign = compute(x, &y);
        printf("%10.6f\t%12.8f\t%3d\n", x, y, sign);
        if (x >= b) break;
    }
}
