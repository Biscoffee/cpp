class Solution {
    public:
        vector<vector<int>> findMatrix(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
            unordered_map<int,int> mp;
            int max = 0;
            for(int i = 0;i < n;i++){
                mp[nums[i]]++;
            }
            for(int i= 0;i <n;i++){
                int v= cnt[i];
                for(int j = 0;j < v;j++){
                    if(ans.size() <= j){
                        ans.push_back(vector<int>());
                    }
                    ans[j].push_back(i);
                }
            }
            return ans;
        }
    };