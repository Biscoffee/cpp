class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            int max_len = 0;
            int left = 0;
            unordered_map<char, int> window;
            for(int r = 0;r < n;r++){
                char c = s[r];
                window[c]++;
                while(window[c] > 1){
                    char d = s[left];
                    window[d]--;
                    left++;
                }
                max_len = max(max_len, r - left + 1);
            }
            return max_len;
        }
    };