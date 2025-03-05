#include <iostream>
#include <vector>
using namespace std;

int lower_bound1(vector<int>& nums, int target)   //闭区间，左边界
{
    int l = 0,r = (int) nums.size() - 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(nums[mid] < target) l = mid + 1;
        else   r = mid - 1;
    }
    return l;
}

int lower_bound2(vector<int>& nums, int target)   //，左边界
{
    int l = 0,r = (int) nums.size();   //左闭右开
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(nums[mid] < target) l = mid + 1;
        else   r = mid;
    }
    return l;  //return right也可以
}

int lower_bound3(vector<int>& nums, int target)   //闭区间，左边界
{
    int l = -1 , r = (int) nums.size() ;  //开区间
    while(l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if(nums[mid] < target) l = mid ;
        else   r = mid  ;
    }
    return l;
}