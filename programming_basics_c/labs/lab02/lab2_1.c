/*Використовуючи цикли: надрукувати всі чотиризначні цілі додатні числа,
у запису яких є дві цифри 5.*/
#include <stdio.h>
int main() {
    int num=0;
    for (num = 1000; num <= 9999; num++) {
        int temp = num;
        int count = 0;

        while (temp > 0) {
            if (temp % 10 == 5) {
                count++;
            }
            temp /= 10;
        }

        if (count == 2) {
            printf("%d\n", num);
        }
    }
    return 0;
}
