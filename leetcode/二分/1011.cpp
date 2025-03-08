class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto check = [&](int x) -> bool{
            int current = 0,cnt = 1;
            for(int weight : weights){
                if(current + weight > x){
                    cnt++;
                    current = weight;
                    if(current > x) return false;
                }   else {
                    current += weight;
                }
            }
            return cnt <= days;
        };
        int l = *max_element(weights.begin(),weights.end()),r =  accumulate(weights.begin(),weights.end(),0) - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid))  r = mid - 1;
            else    l = mid + 1;
        }
        return l;
    }
};