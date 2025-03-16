class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            int sum = 0;
            if(n == k) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
            for(int i = 0;i < n - k;i++){
                sum += cardPoints[i];
            }
            int minSum = sum;
            for(int i = n - k;i < n;i++){
                sum += cardPoints[i] - cardPoints[i - n + k];
                minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};