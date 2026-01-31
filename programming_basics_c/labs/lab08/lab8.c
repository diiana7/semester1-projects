/*З текстового файлу зчитати послідовність записів, які містять дані про результати сесії 
студентів групи у такому форматі: <Прізвище>, <Ім’я>, <Дата народження>,
<Список екзаменаційних оцінок>. Роздрукувати введені дані у вигляді таблиці, а
також подати інформацію згідно варіанту.
Роздрукувати список студентів у зростаючому порядку за рейтинговим балом.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char surname[50];
    char name[50];
    char birth[12];  
    int marks[4];
    double average;
} Student;

int main() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) {
        printf("I can't open the file.\n");
        return 1;
    }

    Student students[MAX];
    int count = 0;

    while (fscanf(fp, "%s %s %s %d %d %d %d",
                  students[count].surname,
                  students[count].name,
                  students[count].birth,
                  &students[count].marks[0],
                  &students[count].marks[1],
                  &students[count].marks[2],
                  &students[count].marks[3]) == 7)
    {
        students[count].average =
            (students[count].marks[0] +
             students[count].marks[1] +
             students[count].marks[2] +
             students[count].marks[3]) / 4.0;

        count++;
        if (count >= MAX) break;
    }

    fclose(fp);

    printf("=================================================================================================================\n");
    printf("| %-10s | %-10s | %-12s | %-5s | %-5s | %-5s | %-5s | %-8s |\n",
           "Lastname", "Name", "Birthdate", "Grade1", "Grade2", "Grade3", "Grade4", "Rating");
    printf("=================================================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("| %-10s | %-10s | %-12s | %-5d | %-5d | %-5d | %-5d | %-8.2f |\n",
               students[i].surname,
               students[i].name,
               students[i].birth,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].marks[3],
               students[i].average);
    }
    printf("=================================================================================================================\n");

    // Сортування за рейтингом
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average > students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    // Вивід після сортування
    printf("\nList of students in ascending order of rating score:\n\n");
    printf("===========================================================\n");
    printf("| %-10s | %-10s | %-12s | %-8s |\n",
           "Lastname", "Name", "Birthdate", "Rating");
    printf("===========================================================\n");

    for (int i = 0; i < count; i++) {
        printf("| %-10s | %-10s | %-12s | %-8.2f |\n",
               students[i].surname,
               students[i].name,
               students[i].birth,
               students[i].average);
    }
    printf("===========================================================\n");

    return 0;
}

