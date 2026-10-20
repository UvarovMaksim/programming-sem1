#include <stdio.h>

int main(void) {
    double x_start, x_end, dx;

    if (scanf("%lf", &x_start) != 1) return 1;
    if (scanf("%lf", &x_end) != 1) return 1;
    if (scanf("%lf", &dx) != 1) return 1;

    if (x_start >= x_end || dx <= 0) {
        return 1;
    }

    printf("\n-------------------------\n");
    printf("    X     |     Y(X)     \n");
    printf("-------------------------\n");

    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        double y;

        if (x < -2.0) {
            y = -x - 2.0;
        } else if (x <= 2.0) {
            y = x / 2.0;
        } else {
            y = x * x - 3.0;
        }

        printf("%10.2lf | %12.4lf\n", x, y);
    }
    printf("-------------------------\n");

    return 0;
}