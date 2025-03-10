#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 高精度乘法，计算 n!
vector<int> factorial(int n) {
    vector<int> result = {1}; // 初始化为 1
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10; // 当前位
            carry = product / 10;    // 进位
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    return result;
}

// 统计数码 a 在阶乘结果中出现的次数
int countDigit(vector<int>& num, int a) {
    int count = 0;
    for (int digit : num) {
        if (digit == a) count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        vector<int> num = factorial(n); // 计算 n!
        int result = countDigit(num, a); // 统计数码 a 出现的次数
        cout << result << endl;
    }
    return 0;
}