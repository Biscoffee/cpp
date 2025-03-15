class Solution {
    public:
        // 辅助函数：判断字符是否是元音字母
        bool is_vowel(char a) {
            return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
        }
    
        int maxVowels(string s, int k) {
            int max_len = 0; // 最大元音字母数量
            int temp_len = 0; // 当前窗口的元音字母数量
            int n = s.size();
    
            // 初始化第一个窗口
            for (int i = 0; i < k; i++) {
                if (is_vowel(s[i])) {
                    temp_len++;
                }
            }
            max_len = temp_len;
    
            // 滑动窗口
            for (int left = 1; left <= n - k; left++) {
                int right = left + k - 1;
                temp_len = temp_len - is_vowel(s[left - 1]) + is_vowel(s[right]);
                max_len = max(max_len, temp_len);
            }
    
            return max_len;
        }
    };