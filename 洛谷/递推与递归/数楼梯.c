#include <stdio.h>
#include <string.h>

// 实现两个大整数相加，
// a[] 存储数字，a_len 为 a 的位数（低位在前）
// b[] 同理，结果存储在 res[] 中，同时更新 res_len
void add(int a[], int a_len, int b[], int b_len, int res[], int *res_len) {
    int carry = 0, i;
    int max = a_len > b_len ? a_len : b_len;
    for(i = 0; i < max; i++){
        int d1 = i < a_len ? a[i] : 0;
        int d2 = i < b_len ? b[i] : 0;
        int sum = d1 + d2 + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }
    while(carry) {
        res[i++] = carry % 10;
        carry /= 10;
    }
    *res_len = i;
}

int main(){
    int n;
    scanf("%d", &n);
    
    // 边界处理
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    if(n == 2) {
        printf("2\n");
        return 0;
    }
    
    // dp1 表示 f(n-2)，dp2 表示 f(n-1)
    // 数组长度足够大，假设 6000 位足够
    int dp1[6000] = {0}, dp2[6000] = {0}, sum[6000] = {0};
    int len1 = 1, len2 = 1, len_sum;
    dp1[0] = 1;  // f(1) = 1
    dp2[0] = 2;  // f(2) = 2
    
    // 从 3 开始迭代
    for (int i = 3; i <= n; i++) {
        // 计算 f(i) = f(i-1) + f(i-2)
        add(dp1, len1, dp2, len2, sum, &len_sum);
        
        // 更新状态：dp1 <- dp2, dp2 <- sum
        memcpy(dp1, dp2, sizeof(int) * len2);
        len1 = len2;
        memcpy(dp2, sum, sizeof(int) * len_sum);
        len2 = len_sum;
    }
    
    // 输出 dp2（即 f(n)），注意逆序输出
    for (int i = len2 - 1; i >= 0; i--) {
        printf("%d", dp2[i]);
    }
    printf("\n");
    return 0;
}