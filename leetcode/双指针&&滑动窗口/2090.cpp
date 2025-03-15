class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(k == 0){
            return nums;
        }
        if(2 * k + 1 > n){
            return ans;
        }
        vector<long long> sum(n + 1,0);
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for(int i = 0;i < n;i++){
            int l = i - k;
            int r = i + k;
            if(l >= 0 && r < n){
                long long summ += sum[r + 1] - sum[l];
                ans[i] = summ / (2 * k + 1);
            }
        }
        return ans;
    }
};