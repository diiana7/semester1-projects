//1.максимальний елемент матриці за модулем.
//2.мінімальний елемент головної діагоналі матриці
//3.підраховує кількість від’ємних елементів у кожному рядку матриці.
#include<stdio.h>
#include<stdlib.h>
int MaxAbs(int *a, int n){
    int max = a[0];
    for(int i=0; i<n*n; i++){
        if(abs(a[i])>abs(max)){
            max = a[i];
        }
    }
    return max;
}
int MinInDiagonal(int a[][4], int n){
    int min = a[0][0];
    for(int i=1; i<n; i++){
        if(a[i][i]<min){
            min=a[i][i];
        }
    }
    return min;
}
void MinusElem(int a[][4], int n){
    for(int i=0; i<n; i++){
        int count =0;
        for(int j=0; j<n; j++){
            if(a[i][j]<0){
                count++;
            }
        }
        printf("Negative elements in row #%d: %d\n", i+1, count);
    }
}
void SwapFirstAndLastColumn(int a[][4], int n){
    for(int i=0; i<n; i++){
        int temp = a[i][0];
        a[i][0]=a[i][n-1];
        a[i][n-1]=temp;
    }
}
int main(){
    int N = 4;
    int a[N][N];
    printf("Enter elements of array:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("Enter element:\n");
            scanf("%d", &a[i][j]);
        }
    }
    int maxabs = MaxAbs(*a,N);
    printf("Max with module : %d\n", maxabs);

    int minindiag = MinInDiagonal(a, N);
    printf("Min in diagonale: %d\n", minindiag);

    MinusElem(a, N);
    return 0;
}