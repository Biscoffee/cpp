class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(citations, n, mid)){
                ans = mid + 1;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    bool check(vector<int>& citations , int n ,int k)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(citations[i] > k )  cnt++;
        }
        return cnt >= k ;
    }
};