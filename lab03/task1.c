#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    // Встановлюємо кодування UTF-8 для консолі Windows (зміна мовної сторінки)
    system("chcp 65001 > nul");

    int A[SIZE];
    int i, j;
    int inversions_count = 0;

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Заповнення масиву числами з діапазону [-50; 50]
    for (i = 0; i < SIZE; i++) {
        A[i] = (rand() % 101) - 50;
    }

    // Виведення вихідного масиву
    printf("Вихідний масив A:\n[ ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("]\n\n");

    // Обчислення кількості інверсій (Варіант 14)
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (A[i] > A[j]) {
                inversions_count++;
            }
        }
    }

    // Виведення результату українською мовою
    printf("Результат індивідуального завдання (Варіант 14):\n");
    printf("Кількість інверсій у масиві = %d\n", inversions_count);

    return 0;
}