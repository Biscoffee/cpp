class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // 初始化结果数组

        if (k == 0) {
            return result; // 如果 k == 0，直接返回全 0 数组
        }

        for (int i = 0; i < n; i++) {
            if (k > 0) {
                // 计算从 code[i + 1] 开始的 k 个数字的和
                for (int j = 1; j <= k; j++) {
                    result[i] += code[(i + j) % n];
                }
            } else {
                // 计算从 code[i - 1] 开始的 |k| 个数字的和
                for (int j = 1; j <= -k; j++) {
                    result[i] += code[(i - j + n) % n];
                }
            }
        }

        return result;
    }
};