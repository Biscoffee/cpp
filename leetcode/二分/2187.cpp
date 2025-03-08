#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // 定义二分查找的范围
        long long left = 1;
        long long right = 1LL * *min_element(time.begin(), time.end()) * totalTrips;

        // 二分查找
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long total = 0;
            // 计算在 mid 时间内可以完成的总旅途数
            for (int t : time) {
                total += mid / t;
                if (total >= totalTrips) {
                    break;
                }
            }
            // 如果总旅途数 >= totalTrips，尝试更小的时间
            if (total >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};