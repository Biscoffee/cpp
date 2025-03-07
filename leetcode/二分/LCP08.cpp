class Solution {
public:
    vector < int > getTriggerTime(vector < vector < int >> & increase, vector < vector < int >> & requirements) {
        int n = increase.size();
        vector<vector<int>> sum(n + 1, vector<int>(3, 0));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                sum[i][j] = increase[i - 1][j] + sum[i - 1][j];
            }
        }
        vector < int > res;
        for(auto & req : requirements){
            int c = req [ 0 ] , r = req [ 1 ] , h = req [ 2 ] ;
            int l = 0,right = n;
            int ans = -1;
            while(l <=right){
            int mid = (l + right) >> 1;
            if(sum[mid][0] >= c && sum[mid][1] >= r && sum[mid][2] >= h){
                ans = mid;
                right = mid - 1;
            } else {
                l = mid + 1;
            }
        }
            res.push_back(ans);
        }
        return res;
    }
};