#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define SIZE 100

int main(void) {
    double x = 0, y = 0, a = 0;
    char inputFilePath[SIZE];
    char outFilePath[SIZE];
    char typeFile;
    time_t t;
    char* timeStr;

    FILE* logFile = fopen("lab03.log", "at");
    if (!logFile) {
        perror("Error opening log file");
        return 1;
    }

    t = time(0);
    timeStr = ctime(&t);
    if (timeStr[strlen(timeStr) - 1] == '\n') timeStr[strlen(timeStr) - 1] = '\0';
    fprintf(logFile, "[%s] >> Program started.\n", timeStr);

    printf("Enter name of binary file for reading parameters: ");
    scanf("%s", inputFilePath);

    FILE* inputFile = fopen(inputFilePath, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        fprintf(logFile, "[%s] >> Error opening input file '%s': %s\n", timeStr, inputFilePath, strerror(errno));
        fclose(logFile);
        return 1;
    }

    if (fread(&x, sizeof(double), 1, inputFile) != 1 ||
        fread(&y, sizeof(double), 1, inputFile) != 1) {
        fprintf(logFile, "[%s] >> Error reading parameters from file '%s'\n", timeStr, inputFilePath);
        fclose(inputFile);
        fclose(logFile);
        return 1;
    }
    fclose(inputFile);

    fprintf(logFile, "[%s] >> Parameters file '%s' opened. X=%.3lf, Y=%.3lf.\n", timeStr, inputFilePath, x, y);

    if (x == 0) {
        fprintf(logFile, "[%s] >> Error: division by zero (x=0). Program ended.\n", timeStr);
        fclose(logFile);
        return 1;
    }

    a = pow(2, -x) * sqrt(pow(x, -4) + sqrt(fabs(y)));
    fprintf(logFile, "[%s] >> Expression calculated. Result = %.6lf.\n", timeStr, a);

    printf("Enter name of output file: ");
    scanf("%s", outFilePath);
    printf("Enter type of file ('t' for text, 'b' for binary): ");
    scanf(" %c", &typeFile);

    FILE* outputFile;
    if (typeFile == 't') {
        outputFile = fopen(outFilePath, "wt");
        if (!outputFile) {
            perror("Error opening output file");
            fprintf(logFile, "[%s] >> Error opening output file '%s': %s\n", timeStr, outFilePath, strerror(errno));
            fclose(logFile);
            return 1;
        }
        fprintf(outputFile, "%.6lf", a);
        fclose(outputFile);
    } else if (typeFile == 'b') {
        outputFile = fopen(outFilePath, "wb");
        if (!outputFile) {
            perror("Error opening output file");
            fprintf(logFile, "[%s] >> Error opening output file '%s': %s\n", timeStr, outFilePath, strerror(errno));
            fclose(logFile);
            return 1;
        }
        fwrite(&a, sizeof(double), 1, outputFile);
        fclose(outputFile);
    } else {
        printf("Invalid file type selected.\n");
        fprintf(logFile, "[%s] >> Invalid file type selected.\n", timeStr);
        fclose(logFile);
        return 1;
    }

    fprintf(logFile, "[%s] >> Output file '%s' saved.\n", timeStr, outFilePath);
    fprintf(logFile, "[%s] >> Program ended.\n\n", timeStr);
    fclose(logFile);

    printf("\nThe program was successfully completed :)\n");
    return 0;
}
