#include <stdio.h>
#include <stdlib.h>  // 用于 abs 函数

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    if (n == 1) {
        printf("Jolly\n");
        return 0;
    }
    
    int cha[n - 1];  // 存储差值的绝对值
    int found[n - 1];  // 用于标记差值是否已经出现
    for (int i = 0; i < n - 1; i++) {
        found[i] = 0;  // 初始化 found 数组
    }
    
    int jolly = 1;
    
    // 计算相邻元素的差的绝对值
    for (int i = 0; i < n - 1; i++) {
        cha[i] = abs(a[i] - a[i + 1]);
    }

    // 检查差值的有效性
    for (int i = 0; i < n - 1; i++) {
        if (cha[i] < 1 || cha[i] >= n || found[cha[i] - 1]) {
            jolly = 0;
            break;
        }
        found[cha[i] - 1] = 1;
    }
    
    if (jolly) {
        printf("Jolly\n");
    } else {
        printf("Not jolly\n");
    }

    return 0;
}