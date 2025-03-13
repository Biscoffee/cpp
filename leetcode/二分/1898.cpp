class Solution {
    public:
        int maximumRemovals(string s, string p, vector<int>& removable) {
            int n = removable.size();
            int ans = 0;
            int l = 0, r = n;
            while (l <= r) {
                int mid = l + (r - l) / 2; // 防止溢出
                if (check(s, p, removable, mid)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return ans;
        }
    
    private:
        bool check(const string& s, const string& p, const vector<int>& removable, int k) {
            unordered_set<int> removed;
            for (int i = 0; i < k; ++i) {
                removed.insert(removable[i]);
            }
            int i = 0, j = 0;
            while (i < s.size() && j < p.size()) {
                if (s[i] == p[j] && removed.count(i) == 0) {
                    ++j;
                }
                ++i;
            }
            return j == p.size();
        }
    };