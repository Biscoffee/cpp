class Solution {
    public:
        int shipWithinDays(vector<int>& piles, int h) {
            int n = piles.size();
            auto check = [&](int x) -> bool{
                int cnt = 0;
                for(int i = 0;i < n;i++){
                    cnt += (piles[i] - 1 + x) / x; 
                    if(cnt > h) return false;  
                }
                return true;
            };
            int l = 1 , r = *max_element(piles.begin(),piles.end());
            while(l <= r){
                int mid = (l + r) >> 1; 
                if(check(mid)){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            return l;
        }
    };