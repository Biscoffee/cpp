#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
        {
            sort(potions.begin(),potions.end());
            vector<int> ans;
            for(int i = 0;i < n;i++)
            {
                int l = 0,r = m - 1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(spells[i] * potions[mid] < success) l = mid + 1;
                    else r = mid - 1;
                }
                ans[i] = m - l;
            }
            return ans;
        }

}