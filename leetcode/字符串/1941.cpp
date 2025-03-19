#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        // 使用哈希表记录每个字符的出现次数
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // 检查所有字符的频率是否相同
        int firstFreq = freq[s[0]]; // 取第一个字符的频率作为参考
        for (auto& pair : freq) {
            if (pair.second != firstFreq) {
                return false;
            }
        }

        return true;
    }
};