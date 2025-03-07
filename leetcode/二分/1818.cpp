class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7; 
        int n = nums1.size();   
        long long sum = 0;    
        for (int i = 0; i < n; ++i) {
            sum += abs(nums1[i] - nums2[i]);
        }

        vector<int> sorted_nums1 = nums1;
        sort(sorted_nums1.begin(), sorted_nums1.end());
        
        long long min_sum = sum; 
        
        // 遍历 nums2，寻找最佳替换
        for (int i = 0; i < n; ++i) {
            int num2 = nums2[i]; // nums2 的当前元素
            int original_diff = abs(nums1[i] - num2); // 原始差值
            
            // 在 sorted_nums1 中查找最接近 num2 的元素
            auto it = lower_bound(sorted_nums1.begin(), sorted_nums1.end(), num2);
            int closest_diff = INT_MAX; // 最接近的差值
            
            // 检查当前元素和上一个元素
            if (it != sorted_nums1.end()) {
                closest_diff = min(closest_diff, abs(*it - num2));
            }
            if (it != sorted_nums1.begin()) {
                closest_diff = min(closest_diff, abs(*(prev(it)) - num2));
            }
            
            // 如果替换后的差值更小，则更新最小差值和
            if (closest_diff < original_diff) {
                min_sum = min(min_sum, sum - original_diff + closest_diff);
            }
        }
        
        return min_sum % MOD; // 返回结果
    }
};