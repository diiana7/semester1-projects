/*Використовуючи умовну компіляцію, обчислити значення змінної. Функції max, min і 
піднесення до степені виконати у вигляді макросів. 
w={max(x^2+y+z, xyz), 0<a<5, min(x^2+(y+z)^2, xy), a<=0, a>=5.}*/
#include <stdio.h>
#define POW(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int main() {
    double x, y, z, a, w;
    printf("Enter x, y, z, a: ");
    scanf("%lf %lf %lf %lf", &x, &y, &z, &a);
#if 1
    if (a > 0 && a < 5){
        w = MAX(POW(x) + y + z, x * y * z);
    }
    else{
        w = MIN(POW(x) + POW(y + z), x * y);
    }
#endif
    printf("w = %.3lf\n", w);
    return 0;
}
