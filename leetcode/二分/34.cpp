#include <iostream>
#include <vector>
using namespace std;   
class Solution {
public:
    int bsearch_1(vector<int>& nums, int target , int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= target) r = mid;   
        else l = mid + 1;
    }
    return l;
}


int bsearch_2(vector<int>& nums,int target, int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}
vector<int> searchRange(vector<int>& nums, int target) 
{
    int n = nums.size();
    if (n == 0) return {-1, -1};
    int l = bsearch_1(nums, target, 0, n - 1);
    int r = bsearch_2(nums, target, 0, n - 1);
    if(nums[l] = target && nums[r] == target)
        return {l, r};
    else
        return {-1, -1};

}
};
