/*Написати мовою С три функції, щоб протабулювати, задану згідно варіанту, функцію 
на проміжку [a , b] з кроком h, використавши: а) для першої функції оператор циклу for; 
б) для другої – оператор циклу while; в) для третьої оператор циклу do…while. 
Вибір способу табулювання реалізувати через вказівник на відповідну функцію
f = (1+sin2x)^2, a=0, b=pi/4 */
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
double f(double x);
void tab_for(double a, double b, double h);
void tab_while(double a, double b, double h);
void tab_do_while(double a, double b, double h);

int main() {
    double a = 0, b = PI/4, h = 0.05;
    void (*tab_func)(double, double, double); // Вказівник на функцію
    int choice;
    printf("Viberit sposib tabulyatsiyi (1 - for, 2 - while, 3 - do...while): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: tab_func = tab_for; break;
        case 2: tab_func = tab_while; break;
        case 3: tab_func = tab_do_while; break;
        default:
            printf("Nepravyl`nyy vibir!\n");
            return 1;
    }

    tab_func(a, b, h);// Виклик обраної функції через вказівник
    return 0;
}

double f(double x) { // Функція для обчислення f(x)
    return (1 + sin(2 * x)) * (1 + sin(2 * x));
}

void tab_for(double a, double b, double h) {
    printf("Tabulyatsiya za for:\n");
    for(double x = a; x <= b; x += h) {
        printf("x = %.4f, f(x) = %.4f\n", x, f(x));
    }
}

void tab_while(double a, double b, double h) {
    printf("Tabulyatsiya za while:\n");
    double x = a;
    while(x <= b) {
        printf("x = %.4f, f(x) = %.4f\n", x, f(x));
        x += h;
    }
}

void tab_do_while(double a, double b, double h) {
    printf("Tabulyatsiya za do…while:\n");
    double x = a;
    if(h <= 0 || a > b) return;
    do {
        printf("x = %.4f, f(x) = %.4f\n", x, f(x));
        x += h;
    } while(x <= b);
}