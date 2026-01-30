/*Вважаючи, що введене речення з клавіатури складається з довільної кількості слів, між якими є довільна 
кількість пробілів, і закінчується речення крапкою, написати програму для розв’язання завдання:
Ввести речення і ключове слово. Надрукувати всі слова з введеного речення, які не містять літер із заданого 
ключового слова, або вивести повідомлення про їх відсутність.*/
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char word[100];
    const char *lim = " "; // символ-обмежувач лексем

    printf("Vvedit' rechennya (v kintsi krapka): \n");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Vvedit' klyuchove slovo: \n");
    fgets(word, sizeof(word), stdin);
    // забрати знак \n
    sentence[strcspn(sentence, "\n")] = '\0';
    word[strcspn(word, "\n")] = '\0';

    // забрати крапку
    int len = strlen(sentence);
    if (sentence[len - 1] == '.')
    {
        sentence[len - 1] = '\0';
    }

    char *pw = strtok(sentence, lim); // вказівник на лексему
    int found = 0;                    // слова без спільних літер
    int len2 = strlen(word);          // довжина ключового слова

    while (pw != NULL)
    {
        int hasCommon = 0;     // чи має спільну літеру з ключовим словом
        int len1 = strlen(pw); // довжина поточного слова

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (pw[i] == word[j])
                {
                    hasCommon = 1;
                    break;
                }
            }
            if (hasCommon)
                break; // перейти тоді до наступного слова
        }

        if (!hasCommon)
        {
            printf("%s ", pw);
            found = 1;
        }

        pw = strtok(NULL, lim);
    }

    if (!found)
    {
        printf("Nemaye sliv, shcho ne vidpovidayut` literu iz klyuchovoho slova.");
    }

    printf("\n");
    return 0;
}
