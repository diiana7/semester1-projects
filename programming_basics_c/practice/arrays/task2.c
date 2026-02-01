/*Знайти середнє значення елементів масиву та створити новий масив, що містить
елементи > середнього. Використати динамічне виділення.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int nElements;
    printf("Enter n: ");
    scanf("%d", &nElements);
    int *arr = malloc(nElements * sizeof(int));
    for(int i=0; i<nElements; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d", arr+i);
    }
    int sum=0;
    float avr=0;
    for(int i=0; i<nElements; i++){
        sum += *(arr+i);
    }
    avr = (float)sum/nElements;
    int count=0;
    for(int i=0; i<nElements; i++){
        if(*(arr+i)>avr){
            count++;
        }
    }
    printf("Avarage: %.2f\n", avr);
    int *arr2 = malloc(count*sizeof(int));
    int k = 0;
    for (int i = 0; i < nElements; i++) {
        if (*(arr + i) > avr) {
            *(arr2 + k) = *(arr + i);
            k++;
        }
    }
    printf("Changed massive: ");
    for(int i=0; i<count; i++){
        printf("%d ", *(arr2+i));
    }
    free(arr);
    free(arr2);
    return 0;
}