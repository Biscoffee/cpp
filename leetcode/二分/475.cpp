class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        auto check = [&](int r) -> bool{
            for(int house : houses){
                auto it = lower_bound(heaters.begin(),heaters.end(),house - r);
                if(it == heaters.end() || *it - house > r)
                    return false;
            }
            return true;
        };
        int l = 0, r = max(*max_element(heaters.begin(),heaters.end()),*max_element(houses.begin(),houses.end()));
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid))  r = mid - 1;
            else    l = mid + 1;
        }
        return l;
    }
};