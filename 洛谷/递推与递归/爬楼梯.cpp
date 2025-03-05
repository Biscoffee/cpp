#include <iostream>
using namespace std;

const int N = 50; // 限制 n 的范围
long long dp[N]; // 使用 long long 存储结果

int main() {
    int n;
    cin >> n;

    // 初始条件
    dp[0] = 1; // f(0) = 1
    dp[1] = 1; // f(1) = 1

    // 动态规划
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // f(i) = f(i-1) + f(i-2)
    }

    // 输出结果
    cout << dp[n] << endl;
    return 0;
}