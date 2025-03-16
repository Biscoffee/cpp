class Solution {
public:
        int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] == target){
                ans = mid;
                break;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};