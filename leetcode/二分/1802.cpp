class Solution {
    public:
        int n, index, maxSum;
    
        bool check(int k) {

            long sum = k; 
            long left = index, right = n - index - 1; // 左右两侧的元素个数
    
            // 计算左侧的和
            if (k > left) {
                sum += (k - 1 + k - left) * left / 2; // 等差数列求和
            } else {
                sum += (k - 1 + 1) * (k - 1) / 2 + (left - (k - 1)); // 不足部分补 1
            }
    
            // 计算右侧的和
            if (k > right) {
                sum += (k - 1 + k - right) * right / 2; // 等差数列求和
            } else {
                sum += (k - 1 + 1) * (k - 1) / 2 + (right - (k - 1)); // 不足部分补 1
            }
    
            return sum <= maxSum;
        }
    
        int maxValue(int n, int index, int maxSum) {
            this->n = n;
            this->index = index;
            this->maxSum = maxSum;
    
            int ans = 0;
            int l = 1, r = maxSum; // 最小值为 1，最大值为 maxSum
            while (l <= r) {
                int mid = l + (r - l) / 2; // 防止溢出
                if (check(mid)) {
                    ans = mid; // 更新答案
                    l = mid + 1; // 尝试更大的值
                } else {
                    r = mid - 1; // 尝试更小的值
                }
            }
            return ans;
        }
    };