class Solution {
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            if (!head || !head->next || !head->next->next) {
                return {-1, -1};
            }
    
            ListNode* prev = head;   //指向当前节点的前驱节点
            ListNode* curr = head->next;   // 指向当前节点
            int index = 1; // 当前节点的索引
            vector<int> criticalPoints; // 存储关键点的索引
    
            while (curr->next) {
                ListNode* next = curr->next;  //当前节点后继节点
                // 检查是否是关键点
                if ((curr->val > prev->val && curr->val > next->val) ||
                    (curr->val < prev->val && curr->val < next->val)) {
                    criticalPoints.push_back(index);
                }
                prev = curr;
                curr = next;
                index++;
            }
    
            if (criticalPoints.size() < 2) {
                return {-1, -1};
            }
    
            // 计算最小距离和最大距离
            int minDist = INT_MAX;
            int maxDist = criticalPoints.back() - criticalPoints.front();
    
            for (int i = 1; i < criticalPoints.size(); i++) {
                minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
            }
    
            return {minDist, maxDist};
        }
    };