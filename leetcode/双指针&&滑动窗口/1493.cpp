#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0; // 最大长度
        int left = 0; // 窗口的左边界
        int zero_count = 0; // 窗口中 0 的数量

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zero_count++;
            }
            // 如果窗口中的 0 的数量超过 1，移动 left 指针
            while (zero_count > 1) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            // 更新最大长度
            max_len = max(max_len, right - left);
        }

        // 如果数组中没有 0，则必须删除一个元素
        if (max_len == n) {
            return n - 1;
        }

        return max_len;
    }
};