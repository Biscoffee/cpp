#include <stdio.h>
#include <math.h>
int w0, w, m;
double calculate_monthly_payment(double r) {
    return w0 * r * pow(1 + r, m) / (pow(1 + r, m) - 1);
}
int check(double r) {
    double payment = calculate_monthly_payment(r);
    return payment <= w;
}

int main() {
    
    scanf("%d %d %d", &w0, &w, &m);
    double left = 0.0, right = 3.0; 
    double interest_rate = 0; 
    while (right - left > 1e-7) {  
        double mid = (left + right) / 2;
        if (check(mid)) {
            interest_rate = mid;
            right = mid;  
        } else {
            left = mid;  
        }
    }
    printf("%.1f\n", interest_rate * 100);

    return 0;
}