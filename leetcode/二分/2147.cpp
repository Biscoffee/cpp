class Solution {
public:
    bool check(int n, vector<int>& batteries, long long T) {
        long long totalEnergy = 0;
    
        for (int b : batteries) {
            totalEnergy += min((long long)b, T); // 每个电池最多贡献 T 分钟,如果超过就只能废弃
        }
    
        return totalEnergy >= (long long)n * T;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        long long int l = 0;
        long long r = 0;
        for ( int b : batteries ) { 
            r += b ; // 最大可能的总运行时间 
            }
        long long int ans= 0;
        while(l <= r){
            long long int mid = (l + r) >> 1;
            if(check(n,batteries, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};