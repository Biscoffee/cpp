#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
    public:
    int maximumCount(vector<int>& nums)
    {
        int l = 0,r = nums.size() - 1;
        int n = nums.size();
        int ans1 = n;  //重点
        int ans2 = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] > 0) ans1 = mid,r = mid - 1;
            else l = mid + 1;
        }
        l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] < 0) ans2 = mid, l = mid + 1;
            else r = mid - 1;
        }
        return max(ans2 + 1, n - ans1);
    }
};