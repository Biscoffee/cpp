#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};

    // 查找第一个 >= 5 的元素
    auto it = lower_bound(nums.begin(), nums.end(), 5);
    if (it != nums.end()) {
        cout << "Lower bound of 5: " << *it << " at position " << (it - nums.begin()) << endl;
    } else {
        cout << "Not found" << endl;
    }

    // 查找第一个 >= 6 的元素
    it = lower_bound(nums.begin(), nums.end(), 6);
    if (it != nums.end()) {
        cout << "Lower bound of 6: " << *it << " at position " << (it - nums.begin()) << endl;
    } else {
        cout << "Not found" << endl;
    }

    // 查找第一个 >= 10 的元素
    it = lower_bound(nums.begin(), nums.end(), 10);
    if (it != nums.end()) {
        cout << "Lower bound of 10: " << *it << " at position " << (it - nums.begin()) << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}