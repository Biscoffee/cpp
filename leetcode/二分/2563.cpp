class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int size = nums.size();
            long long ans = 0;
    
            sort(nums.begin(), nums.end());
            for(int i = 0; i < size; i++){
                //nums[j]的下限和上限
                int lowerBound = lower - nums[i];
                int upperBound = upper - nums[i];
                //查找第一个大于等于 下限lowerBound 的元素的位置
                auto left = lower_bound(nums.begin() + i + 1, nums.end(), lowerBound);
                //查找第一个大于 上限upperBound 的元素的位置
                auto right = upper_bound(nums.begin() + i + 1, nums.end(), upperBound);
    
                ans += (right - left);
            }
            return ans;
        }
    };
  