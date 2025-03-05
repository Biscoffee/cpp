#include <stdio.h>
#include <stdbool.h>

#define MAX_DEVICES 100000

int n;
double p;
double a[MAX_DEVICES];
double b[MAX_DEVICES];

bool can_use(double t) {
    double sum_diff = 0.0;
    double charge_available = p * t;
    for (int i = 0; i < n; ++i) {
        double required = a[i] * t;
        if (required > b[i]) {
            sum_diff += required - b[i];
            if (sum_diff > charge_available) {
                return false;
            }
        }
    }
    return sum_diff <= charge_available;
}

int main() {
    scanf("%d %lf", &n, &p);
    double sum_a = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &a[i], &b[i]);
        sum_a += a[i];
    }
    if (sum_a <= p) {
        printf("-1\n");
        return 0;
    }

    double left = 0.0, right = 1e18;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (left + right) / 2;
        if (can_use(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%.10f\n", left);
    return 0;
}