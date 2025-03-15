class Solution {
    public:
        long long maxSum(vector<int>& nums, int m, int k) {
            int len=nums.size();
            unordered_map<long long int,int> map;
            long long int sum=0,max=0;
            int count=0;
            for(int i=0;i<=(len-k);++i)
            {
                if(i==0)
                {
                    for(int j=0;j<k;++j)
                    {
                        map[nums[j]]++;
                        sum+=nums[j];
                    }
                }
                else
                {
                    map[nums[i+k-1]]++;
                    if(--map[nums[i-1]]==0)
                    {
                        map.erase(nums[i-1]);
                    }
                    sum=sum+nums[i+k-1]-nums[i-1];
                }
                if(map.size()>=m &&sum>max)
                {
                    max=sum;
                }
            }
            return max;
        }
    };
    