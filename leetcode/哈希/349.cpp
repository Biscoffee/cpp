class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set <int> set;
        int hash[1005] = {0};
        for(int num : nums1){
            hash[num] = 1;
        }
        for(int num : nums2){
            if(hash[num] == 1){
                set.insert(num);
            }
        }
        return vector<int>(set.begin(), set.end());
    }
};