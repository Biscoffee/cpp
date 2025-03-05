#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int price; // 牛奶单价
    int amount; // 每日供应量
} Farmer;

// 按单价排序的比较函数
int cmp(const void *a, const void *b) {
    return ((Farmer*)a)->price - ((Farmer*)b)->price;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Farmer farmers[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &farmers[i].price, &farmers[i].amount);
    }
    qsort(farmers, m, sizeof(Farmer), cmp);

    int total_cost = 0;
    for (int i = 0; i < m && n > 0; i++) {
        if (farmers[i].amount <= n) {
            total_cost += farmers[i].price * farmers[i].amount;
            n -= farmers[i].amount;
        } else {
            
            total_cost += farmers[i].price * n;
            n = 0; 
        }
    }
    printf("%d\n", total_cost);

    return 0;
}