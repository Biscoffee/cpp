#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 如果总花朵数不足，直接返回 -1
        if (bloomDay.size() < m * k) {
            return -1;
        }

        // 定义 check 函数，判断是否可以在 t 天内制作至少 m 束花
        auto check = [&](int t) -> bool {
            int bouquets = 0; // 当前可以制作的花束数量
            int consecutive = 0; // 连续开放的花朵数量
            for (int day : bloomDay) {
                if (day <= t) {
                    consecutive++; // 如果花朵在 t 天内开放，连续数量加 1
                    if (consecutive == k) { // 如果连续开放的花朵数量达到 k
                        bouquets++; // 制作一束花
                        consecutive = 0; // 重置连续数量
                    }
                } else {
                    consecutive = 0; // 如果花朵未开放，重置连续数量
                }
                if (bouquets >= m) { // 如果已经可以制作 m 束花，直接返回 true
                    return true;
                }
            }
            return false; // 否则返回 false
        };

        // 二分查找的范围
        int l = 0; // 最小天数
        int r = *max_element(bloomDay.begin(), bloomDay.end()); // 最大天数

        // 二分查找
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid; // 尝试更小的天数
            } else {
                l = mid + 1; // 尝试更大的天数
            }
        }

        return l; // 返回最小天数
    }
};