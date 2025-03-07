class Solution {
public:
    int smmallestDivider(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());

        while(l <= r)
        {
            int mid = (l + r) >> 1;
            int sum = 0;
            for(int i = 0;i < n;i++)
            {
                sum += (nums[i] + mid - 1) / mid;
            }
            if(sum <= threshold){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};