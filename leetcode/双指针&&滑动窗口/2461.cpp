class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        unordered_map<int,int> mp;
        for(int i = 0;i < k;i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        long long ans = 0;
        if(mp.size() == k) ans = max(ans,sum);
        for(int i = k;i < n;i++){
            sum += nums[i] - nums[i - k];
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            if(mp[nums[i - k]] == 0){
                mp.erase(nums[i - k]);
            }  // 如果mp[nums[i - k]] == 0，说明nums[i - k]在子数组中出现的次数为0，需要将其从mp中删除
           //如果哈希表存在频率为0的元素，导致size不准确，使用需要删除，维护哈希表大小
            
            if(mp.size() == k) ans = max(ans,sum);
        }
        return ans;
    }
};