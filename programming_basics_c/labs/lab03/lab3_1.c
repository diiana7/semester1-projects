/*Написати програму для обробки даних, організованих у масив, згідно
завдання наведеного варіанту. У програмі використати такі форми
звертання до елементів масиву: 1.на основі індексів; 2.через розадресоване ім’я масиву і зміщення елемента.
Ввести вектор дійсних чисел. Всі елементи вектора, що менші за його середнє
арифметичне значення, збільшити в 2 рази.*/
#include <stdio.h>
int main(){
    float vect[6]={0};
    for(int i = 0; i < 6; i++){
        printf("Enter number %d: ", i+1);
        scanf("%f", &vect[i]);
    }
    float average = 0;
    float sum=0;
    for(int i =0; i<6; i++){
        sum = sum + vect[i];
    }
    average = sum/6.0;
    for(int i =0; i<6; i++){
        if((*(vect+i))<average){
            *(vect+i)= *(vect+i)*2.0;
        }
    }
    printf("Average: %.2f\n", average);
    for (int i=0; i<6; i++){
        printf("%.2f\t", *(vect+i));
    }
    return 0;
}
