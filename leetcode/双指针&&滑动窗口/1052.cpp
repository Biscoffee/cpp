class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int n = customers.size();
            int max_sum = 0;
            int sum = 0;
            vector<int> angry_cus(n + 1);
            for(int i = 0;i < n;i++){
                if(grumpy[i] == 1)  angry_cus[i] = customers[i];
                else angry_cus[i] = 0;
            } 

            for(int i = 0;i < minutes;i++){
                sum += angry_cus[i];
            }
            max_sum = max(max_sum, sum);

            for(int i = minutes;i < n ;i++){
                sum += angry_cus[i] - angry_cus[i - minutes];
                max_sum = max(max_sum, sum);
            }
            int init_sum = 0;
            for(int i = 0;i < n;i++){
                if(grumpy[i] == 0) init_sum += customers[i];
            }
            return max_sum + init_sum;
        }
    };