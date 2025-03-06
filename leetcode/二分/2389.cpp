class Solution{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries){
        int n = nums.size(), m = queries.size();
        vector<int> ans(m,0);
        sort(nums.begin(), nums.end());
        vector <int> prefixSum ( n ) ; 

        prefixSum[0] = nums [ 0 ] ; 
        for ( int i = 1 ; i < n ; i ++ ) { 
            prefixSum [ i ] = prefixSum [ i - 1 ] + nums [ i ] ; 
        }
        for(int i = 0;i < m ; i++)
        {
           int l = 0,r = n - 1;
            while(l <= r)
           {
               int mid = (l + r) >> 1;
               if(prefixSum[mid] <= queries[i]) ans[i] = mid + 1 , l = mid + 1;
               else r = mid - 1;
           }
        }
        return ans;
    }
};