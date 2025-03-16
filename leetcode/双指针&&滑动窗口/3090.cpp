class Solution {
    public:
        int maximumLengthSubstring(string s) {
            int n = s.size();
            int max_len = 0;
            int l = 0;
            unordered_map<char, int> window;
            for(int r = 0;r < n;r++){
                char c = s[r];
                window[c]++;
                while(window[c] > 2){
                    char d = s[l];
                    window[d]--;
                    l++;
                }
                max_len = max(max_len, r - l + 1);
            }
            return max_len;
        }
    };