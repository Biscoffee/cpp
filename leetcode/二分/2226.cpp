class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int left = 1, right = *max_element(candies.begin(), candies.end());
            int result = 0;
            
            auto nterval = [](vector<int>& candies, int mid, long long k) {
                long long count = 0;
                for (int candy : candies) {
                    count += candy / mid;
                }
                return count >= k;
            };
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if(nterval(candies, mid, k)) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return result;
        }
    };