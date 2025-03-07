class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        sort(items.begin(),items.end());
        vector<int> ans(n,0);
        vector < int > max_beauty ( items . size ( ) ) ; 
        int current_max = 0 ; 
        for ( int i = 0 ; i < items . size ( ) ; i ++ ) { 
            current_max = max ( current_max , items [ i ] [ 1 ] ) ; 
            max_beauty [ i ] = current_max ; 
        }
        for(int i = 0;i < n;i++){
            int l = 0,r = items.size() - 1;
            int idx = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(items[mid][0] >= queries[i])  r = mid - 1;
                else l = mid + 1 , idx = mid;
            }
            if(idx) ans[i] = max_beauty[idx];
            else ans[i] = 0;
        }
        return ans;
    }   
};