/*Написати програму для обробки даних, організованих у масив, згідно завдання наведеного 
варіанту. Написати функцію визначення скалярного добутку двох векторів. З її допомогою
визначити чи є введена матриця ортонормована, тобто така, що скалярний добуток кожної 
пари різних рядків дорівнює 0, а скалярний добуток рядка самої на себе дорівнює 1.*/
#include <stdio.h>
#define M 100
double scalar_product (double v1[], double v2[], int);
int is_orthonormal (double A[M][M], int);

int main() {
    int n;
    double A[M][M];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements of matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    if (is_orthonormal(A, n)){
        printf("The matrix is orthonormal.");
    }    
    else{
        printf("The matrix is not orthonormal.");
    }
    return 0;
}


double scalar_product(double v1[], double v2[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += v1[i] * v2[i];
    }    
    return sum;
}

int is_orthonormal(double A[M][M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double sp = scalar_product(A[i], A[j], n);
            if (i == j) {
                if (sp != 1.0){
                    return 0; 
                }
            } 
            else {
                if (sp != 0.0)
                    return 0;
            }
        }
    }
    return 1;
}