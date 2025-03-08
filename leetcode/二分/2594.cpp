#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
      
        auto check = [&](long long t) -> bool {
            long long total = 0;
            for (int r : ranks) {
                total += sqrt(t / r); // 每个技工在 t 时间内可以修理的汽车数
                if (total >= cars) {
                    return true; 
                }
            }
            return false; 
        };

        long long left = 1;
        long long right = *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }

        return left; 
    }
};