class Solution {
    public:
        vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            int size = queries.size();
            //统计字符串中字典序最小字符出现的频率
            auto countFun = [](string s) -> int{
                vector<int>cnt(26, 0);
                int size = s.size();
                for(int i = 0; i < size; i++){
                    cnt[s[i] - 'a']++;
                }
                //找到那个字典序最小的字符索引位置
                int index = 0;
                for(int i = 0; i < 26; i++){
                    if(cnt[i] > 0){
                        index = i;
                        break;
                    }
                }
                return cnt[index];
            };
            //对word中字符串统计最小字典序字符的出现次数
            vector<int>cnt;
            for(int i = 0; i < words.size(); i++){
                int c = countFun(words[i]);
                cnt.push_back(c);
            }
            sort(cnt.begin(), cnt.end());
    
            //二分查找cnt中最小满足f(w) > q(s)的位置，然后满足要求的数目为cnt.size() - pos - 1;
            auto findPosition = [](vector<int>&cnt, int target) -> int{
                int left = 0, right = cnt.size() - 1;
                while(left <= right){
                    int mid = left + (right - left) / 2;
                    if(cnt[mid] > target){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
                return right;
            };
    
            vector<int>ans;
            for(int i = 0; i < size; i++){
                string s = queries[i];
                int c = countFun(s);
                int p = findPosition(cnt, c);
                ans.push_back(words.size() - p - 1);
            }
            return ans;
        }
    };