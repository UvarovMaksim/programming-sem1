#include <stdio.h>

int main(void) {
    double u, r;

    printf("Введіть напругу U (В): ");
    if (scanf("%lf", &u) != 1) {
        printf("Помилка: некоректне числове значення напруги.\n");
        return 1;
    }

    printf("Введіть опір R (Ом): ");
    if (scanf("%lf", &r) != 1) {
        printf("Помилка: некоректне числове значення опору.\n");
        return 1;
    }

    if (r <= 0.0) {
        printf("Помилка: опір повинен бути строго більшим за нуль (R > 0).\n");
        return 1;
    }

    double i = u / r;
    double p = (u * u) / r;

    printf("\n--- Результати розрахунку ---\n");
    printf("Сила струму (I):  %.2f А\n", i);
    printf("Потужність (P):   %.2f Вт\n", p);

    return 0;
}
