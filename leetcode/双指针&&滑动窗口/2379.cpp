 class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n;
        for(int i = 0;i < n - k + 1;i++){
            int cnt = 0;
            for(int j = i;j < i + k;j++){
                if(blocks[j] == 'W') cnt++;
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
 };