//Написати функцію, яка знаходить у стрічці та заміняє всі символи '$' на '*'.Функція 
//повертає скільки разів була виконана заміна і в яких позиціях заміна не відбувалась.
#include<stdio.h>
int ChangeString(char *p){
    int count=0;
    int position=0;
    while(*p != '\0'){
        if(*p == '$'){
            *p = '*';
            count++;
        }
        else{
            printf("No replace at position: %d\n", position);
        }
        p++;
        position++;
    }
    return count;
}
int main(){
    char string[]= "It cost 10$, that 40$.";
    int result=ChangeString(string);
    printf("Changed string: %s\n", string);
    printf("Number of replacements: %d\n", result);

    return 0;
}