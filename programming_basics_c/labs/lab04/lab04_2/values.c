#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 100

int main(void) {
    char nameFileInput[SIZE];
    double x = 0, y = 0;

    printf("Enter name of binary file for writing parameters: ");
    scanf("%s", nameFileInput);

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);

    FILE* inputFile = fopen(nameFileInput, "wb");
    if (!inputFile) {
        perror("Error opening file");
        return 1;
    }

    fwrite(&x, sizeof(double), 1, inputFile);
    fwrite(&y, sizeof(double), 1, inputFile);
    fclose(inputFile);

    printf("\nThe file '%s' was successfully created.\n", nameFileInput);
    return 0;
}
