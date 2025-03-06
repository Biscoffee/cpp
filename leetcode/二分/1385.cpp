
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int distance = 0; // 距离值

  
        for (int x : arr1) {
            bool valid = true;
            int low = 0, high = arr2.size() - 1;

            // 二分查找
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (abs(x - arr2[mid]) <= d) {
                    valid = false; // 存在不满足条件的元素
                    break;
                }
                if (arr2[mid] < x) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // 如果不存在满足 |x - y| <= d 的元素，则距离值加 1
            if (valid) {
                distance++;
            }
        }

        return distance;
    }
};