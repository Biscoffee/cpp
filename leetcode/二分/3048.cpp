#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, int k) {
        int n = nums.size();
        return (n + k - 1) / k; // 计算 ceil(n / k)
    }
};