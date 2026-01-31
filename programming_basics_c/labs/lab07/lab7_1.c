/*Використовуючи вищенаведені функції swap та qs_sort, які реалізують алгоритм 
швидкого сортування масиву, написати програму мовою С для порівняння ефективності 
алгоритмів сортування масивів великих обсягів (наприклад, 100000 елементів). 
Програма повинна також реалізувати один з класичних алгоритмів сортування масиву
згідно з варіантом індивідуального завдання. У програмі використати два одинакових
масиви, які заповнити випадковими числами, здійснити перевірку впорядкованості елементів
масиву, перевірку ідентичності масивів до і після сортування, а також за допомогою 
стандартної  функції time, оцінити час виконання реалізованих алгоритмів сортування.

Сортування в порядку спадання “бульбашковим” методом з додатковою
перевіркою чи масив вже відсортований*/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void swap(int array[], long pos1, long pos2);
void qs_sort(int array[], long start, long end);
void bubble_sort(int array[], long n);
int arrays_equal(int a[], int b[], long n);
int is_sorted_desc(int array[], long n);

int main() {
    int arr1[N], arr2[N];
    srand(time(NULL));// випадкові числа

    for (long i = 0; i < N; i++) { //заповнення випадковими числами
        int val = rand() % 1000000;
        arr1[i] = val;
        arr2[i] = val;
    }
    printf("Perevirka identychnosti DO sortuvannya: %s\n",
       arrays_equal(arr1, arr2, N) ? "identychni" : "rizni");

    clock_t start, end;
    double time_qs, time_bubble;

    start = clock(); // час qs_sort
    qs_sort(arr1, 0, N - 1);
    end = clock();
    time_qs = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock(); // час bubble_sort
    bubble_sort(arr2, N);
    end = clock();
    time_bubble = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Quick sort (zrostannya): %.3f sec\n", time_qs);
    printf("Bubble sort (spadannya): %.3f sec\n", time_bubble);
    printf("Perevirka vporyadkovanosti (qs_sort): %s\n",
           is_sorted_desc(arr1, N) ? "vidsortovano za spadannyam" : "ne za spadannyam");
    printf("Perevirka vporyadkovanosti (bubble_sort): %s\n",
           is_sorted_desc(arr2, N) ? "vidsortovano za spadannyam" : "ne za spadannyam");
    printf("Perevirka identychnosti masyviv: %s\n",
           arrays_equal(arr1, arr2, N) ? "identychni" : "rizni");

    return 0;
}
void swap(int array[], long pos1, long pos2){
    long tmp;
    tmp=array[pos1];
    array[pos1]=array[pos2];
    array[pos2]=tmp;
}
void qs_sort(int array[], long start, long end){
    long head=start, tail=end-1, tmp;
    long diff=end-start;
    long pe_index;
    // якщо залишилося менше двох елементів – кінець рекурсії
    if (diff<1) return;
    if (diff==1)
        if (array[start]>array[end]) {
            swap(array, start, end);
            return;
        }
    // пошук індексу розділяючого елементу pe_index
    long m=(start+end)/2;
    if (array[start]<=array[m]) {
        if (array[m]<=array[end]) pe_index=m;
        else if (array[end]<=array[start]) pe_index=start;
        else pe_index=end;
    }
    else {
        if (array[start]<=array[end]) pe_index=start;
        else if(array[end]<=array[m]) pe_index=m;
        else pe_index=end;
    }
    long pe=array[pe_index]; // сам розділяючий елемент
    swap(array,pe_index,end);
    while (1) {
        while(array[head]<pe)
            ++head;
        while(array[tail]>pe && tail>start)
            --tail;
        if (head>=tail) break;
        swap(array,head++, tail--);
    }
    swap(array,head,end);
    long mid=head;
    qs_sort(array, start, mid-1); // рекурсивний виклик для 1-ої підмножини
    qs_sort(array, mid+1, end); // рекурсивний виклик для 2-ої підмножини
}
// бульбашкове сортування (спадання з перевіркою)
void bubble_sort(int array[], long n) {
    int swapped;
    for (long i = 0; i < n - 1; i++) {
        swapped = 0;
        for (long j = 0; j < n - i - 1; j++) {
            if (array[j] < array[j + 1]) { // сортування за спаданням
                swap(array, j, j + 1);
                swapped = 1;
            }
        }
        if (!swapped) break; //якщо не було обмінів — масив відсортований
    }
}
// перевірка ідентичності масивів
int arrays_equal(int a[], int b[], long n) { // чи масиви рівні
    for (long i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int is_sorted_desc(int array[], long n) {
    for (long i = 1; i < n; i++)
        if (array[i - 1] < array[i]) return 0;
    return 1;
}

