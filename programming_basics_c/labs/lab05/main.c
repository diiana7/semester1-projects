#include <stdio.h>
#include <math.h>
#include "function.h"

int main(void) {
    double a, b, h;

    printf("Vvedit` pochatkovu promizhku a: ");
    scanf("%lf", &a);
    printf("Vvedit` kinets` promizhku b: ");
    scanf("%lf", &b);
    printf("Vvedit` krok h: ");
    scanf("%lf", &h);

    if (h <= 0 || a > b) {
        printf("Pomylka: nekorektni znachennya a, b abo h.\n");
        return 1;
    }

    tabulate1(a, b, h);
    tabulate2(a, b, h);

    return 0;
}