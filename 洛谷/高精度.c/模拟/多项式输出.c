#include <stdio.h>
int main() {
    int n;
    int a[101];

    scanf("%d", &n);
    

    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int first = 1;  

    for (int i = 0; i <= n; i++) {
        int coef = a[i];  // 当前系数
        int exp = n - i;  // 当前指数

        if (coef == 0) {
            continue;  
        }

        // 处理符号
        if (first) {
            if (coef == -1 && exp != 0) {
                printf("-");
            } else if (coef != 1 || exp == 0) {
                printf("%d", coef);
            }
        } else {
            if (coef > 0) {
                printf("+");
            } else {
                printf("-");
            }

            if (coef == -1 && exp != 0) {
                // 只输出负号，不输出 -1
            } else if (coef != 1 || exp == 0) {
                printf("%d", coef < 0 ? -coef : coef);
            }
        }
        if (exp > 1) {
            printf("x^%d", exp);
        } else if (exp == 1) {
            printf("x");
        }

        first = 0;  
    }
    
    printf("\n");
    return 0;
}