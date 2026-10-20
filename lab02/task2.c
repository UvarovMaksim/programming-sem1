#include <stdio.h>
#include <math.h>

int main(void) {
    double x, eps;

    if (scanf("%lf", &x) != 1) return 1;
    if (scanf("%lf", &eps) != 1) return 1;

    if (eps <= 0) {
        return 1;
    }

    double a_n = 1.0;
    double sum = a_n;
    int n = 1;
    int max_iterations = 100000;
    int iterations = 0;

    while (fabs(a_n) >= eps) {
        if (iterations >= max_iterations) {
            break;
        }

        a_n = a_n * (-x * x / n);
        sum += a_n;

        n++;
        iterations++;
    }

    double exact_value = exp(-x * x);
    double abs_error = fabs(sum - exact_value);

    printf("\n=== Результати обчислення ===\n");
    printf("Обчислена сума ряду: %15.8lf\n", sum);
    printf("Точне значення exp(-x^2): %15.8lf\n", exact_value);
    printf("Абсолютна похибка:   %15.8e\n", abs_error);
    printf("Кількість ітерацій:  %d\n", iterations);

    return 0;
}