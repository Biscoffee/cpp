#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 高精度加法
string add(string a, string b) {
    string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string countPaths(int m, int n) {
    if (m == n) return "1";

    int k = n - m + 1;
    string dp[k + 1]; // DP 数组

    // 初始条件
    dp[1] = "1"; 
    dp[2] = "1"; 

    // 递推计算
    for (int i = 3; i <= k; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }

    return dp[k];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << countPaths(m, n) << endl;

    return 0;
}