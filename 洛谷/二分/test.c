#include <stdio.h>

int a[1000000];  // 存储树木的高度
int n, m;        // n为树木数目，m为需要的木材长度

// 判断在高度H下能获得的木材总量是否至少为M
int check(int H) {
    long long total = 0;  // 用long long避免溢出
    for (int i = 0; i < n; i++) {
        if (a[i] > H) {
            total += a[i] - H;  // 只加上大于H的部分
        }
    }
    return total >= m;  // 如果总量大于等于M，则返回1
}

int main() {
    // 读取输入
    scanf("%d %d", &n, &m);
    int max_height = 0;  // 记录树木的最大高度
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max_height) {
            max_height = a[i];  // 更新最大树木高度
        }
    }

    // 二分查找的范围是[0, max_height]
    int l = 0, r = max_height;
    int result = 0;

    while (l <= r) {
        int mid = (l + r) / 2;  // 计算中间值
        if (check(mid)) {
            result = mid;  // 如果能得到至少M米木材，记录当前高度
            l = mid + 1;   // 尝试更高的高度
        } else {
            r = mid - 1;   // 尝试更低的高度
        }
    }

    // 输出最终找到的最大高度
    printf("%d\n", result);
    return 0;
}