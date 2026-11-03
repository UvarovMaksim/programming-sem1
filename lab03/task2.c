#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int matrix[ROWS][COLS];
    int i, j;

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Заповнення матриці випадковими числами з діапазону [-10; 10]
    // Використовуємо принцип Row-Major Order для ефективного доступу до пам'яті
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = (rand() % 21) - 10;
        }
    }

    // Виведення матриці ДО обробки
    printf("Матриця ДО дзеркального відображення (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%6d ", matrix[i][j]); // Фіксована ширина поля %6
        }
        printf("\n");
    }
    printf("\n");

    // Індивідуальне завдання (Варіант 14): Дзеркальне відображення відносно вертикальної осі симетрії[cite: 6]
    // Міняємо місцями елементи в кожному рядку: перший з останнім, другий з передостаннім тощо.
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][COLS - 1 - j];
            matrix[i][COLS - 1 - j] = temp;
        }
    }

    // Виведення матриці ПІСЛЯ обробки
    printf("Матриця ПІСЛЯ дзеркального відображення (Варіант 14):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}