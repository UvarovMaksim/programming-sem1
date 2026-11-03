#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    int A[SIZE];
    int i, j;
    int inversions_count = 0;

    // Ініціалізація генератора псевдовипадкових чисел
    srand(time(NULL));

    // Заповнення масиву числами з діапазону [-50; 50]
    for (i = 0; i < SIZE; i++) {
        A[i] = (rand() % 101) - 50; // rand() % 101 дає від 0 до 100, мінус 50 дає [-50; 50]
    }

    // Виведення вихідного масиву в один рядок
    printf("Вихідний масив A:\n[ ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("]\n\n");

    // Обчислення кількості інверсій (пар, де i < j, але A[i] > A[j])
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (A[i] > A[j]) {
                inversions_count++;
            }
        }
    }

    // Виведення результату
    printf("Результат індивідуального завдання (Варіант 14):\n");
    printf("Кількість інверсій у масиві = %d\n", inversions_count);

    return 0;
}