#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  
}

int main() {
    int n;
    scanf("%d", &n);  // 读取整数个数

    int a[n];  // 动态创建数组

    // 读取数组元素
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 使用 qsort 排序
    qsort(a, n, sizeof(int), cmp);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}