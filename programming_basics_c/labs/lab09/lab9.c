/*Ввести не більше 5 масивів цілих чисел. Кількість чисел у масиві задається під час
виконання програми, це число записати першим елементом масиву. Масиви розмістити в 
динамічній пам'яті. Створити масив вказівників на дані масиви. У функції вивести на екран 
всі елементи кожного масиву.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAYS 5

void printArrays(int *arrays[], int count) {
    for (int i = 0; i < count; i++) {
        int size = arrays[i][0]; // first element = number of integers
        printf("Array %d (size %d): ", i + 1, size);
        for (int j = 0; j <= size; j++)
            printf("%d ", arrays[i][j]);
        printf("\n");
    }
}

int main() {
    int *arrays[MAX_ARRAYS]; // array of pointers to integer arrays
    int nArrays;

    printf("Enter number of arrays (up to %d): ", MAX_ARRAYS);
    scanf("%d", &nArrays);

    if (nArrays > MAX_ARRAYS) {
        printf("Error: Number is bigger than 5\n", MAX_ARRAYS);
        return 1;
    }

    for (int i = 0; i < nArrays; i++) {
        int size;
        printf("Enter number of elements for array %d: ", i + 1);
        scanf("%d", &size);

        arrays[i] = (int *)malloc((size + 1) * sizeof(int));
        if (arrays[i] == NULL) {
            printf("Error\n");
            return 1;
        }

        arrays[i][0] = size; // first element = number of integers

        printf("Enter %d elements: ", size);
        for (int j = 1; j <= size; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }
    printArrays(arrays, nArrays);

    for (int i = 0; i < nArrays; i++) {
        free(arrays[i]);
    }
    return 0;
}


