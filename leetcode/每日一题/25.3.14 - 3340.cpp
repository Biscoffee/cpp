class Solution {
    public:
        bool isBalanced(string num) {
            int diff = 0, sign = 1; // diff 用于计算偶数下标和奇数下标的差值，sign 用于交替改变符号
            for (char c : num) {
                int d = c - '0'; // 将字符转换为数字
                diff += d * sign; // 根据 sign 的值累加到 diff 中
                sign = -sign; // 交替改变符号
            }
            return diff == 0; // 如果差值为 0，说明偶数下标和奇数下标的和相等
        }
    };