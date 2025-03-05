#include <iostream>
using namespace std;

const int N = 20; 
long long dp[N][N]; // 使用 long long 防止溢出

int main() {
    int n;
    cin >> n;

    // 初始状态
    dp[0][0] = 1;

    // 动态规划
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j + 1]; // push 操作
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1]; // pop 操作
            }
        }
    }

    // 输出结果
    cout << dp[n][0] << endl;
    return 0;
}