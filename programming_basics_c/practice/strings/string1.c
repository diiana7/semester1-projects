//1.підраховує кількість голосних літер у рядку.
//2.яка видаляє всі цифри з рядка.
//3.перевіряє, чи є слово паліндромом.
//4.яка замінює всі пробіли символом _

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int CountVowels(char *p){
    char vowels[] = "euioaEUIOA";
    int count = 0;
    while(*p != '\0'){
        if(strchr(vowels,*p)){
            count++;
        }
        p++;
    }
    return count;
}

void DeleteNumbers(char *p){
    int i=0;
    int j=0;
    while(p[i]){
        if(!isdigit(p[i])){
            p[j]=p[i];
            j++;
        }
        i++;
    }
    p[j]='\0';
}
void Palidrom(char *p){
    int i=0;
    int j = strlen(p)-1;
    int IsPalidrom = 1;

    while(i<j){
        if(p[i]!=p[j]){
            IsPalidrom = 0;
            break;
        }
        i++;
        j--;
    }
    if(IsPalidrom){
        printf("String is a palidrom\n");
    }
    else{
        printf("String is NOT a palidrom\n");
    }
}
void ChangeSpace(char *p){
    while(*p){
        if(*p==' '){
            *p='_';
        }
        p++;
    }
}
int main(){
    char str1[50] = "String for testing 4 functions.";
    printf("Original string: %s\n", str1);
    int vowels = CountVowels(str1);
    printf("Number of vowels: %d\n", vowels);
    DeleteNumbers(str1);
    printf("%s\n", str1);
    Palidrom(str1);
    ChangeSpace(str1);
    printf("%s\n", str1);
    return 0;
}