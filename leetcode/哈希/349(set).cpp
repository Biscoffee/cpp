class Solution{
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
            unordered_set <int> set;
            unordered_set<int> nums_set(nums1.begin(), nums1.end());
            for(int num : nums2){
                if(nums_set.find(num) != nums_set.end()){
                    set.insert(num);
                }
            }
            return vector<int>(set.begin(), set.end());
        }
};
