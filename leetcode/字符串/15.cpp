class Solution {
    public:
        vector<int> masterMind(string solution, string guess) {
            vector<int> cnt(2,0);
            for(int i=0;i<4;i++){
                if(solution[i]==guess[i]) cnt[0]++;
                else cnt[1]++;
            }
            return cnt; 
        }
    };