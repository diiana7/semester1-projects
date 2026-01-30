/*У функцію зі змінним числом параметрів надходять слова, кінець списку -
вказівник NULL. Знайти і вивести найдовше слово.*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h> 
void findLongest(char *first, ...);
int main() {
    findLongest("one", "three", "five", "seven", "nine", "thousand", NULL);
    return 0;
}
void findLongest(char *first, ...) {
    va_list args;     
    va_start(args, first);
    char *word = first;
    char *longest = first;
    while (word != NULL) {
        if (strlen(word)>strlen(longest)){
            longest = word;
        }    
        word = va_arg(args, char *); // беремо наступне слово
    }
    va_end(args); // завершення роботи зі списком
    printf("The longest word: %s\n", longest);
}