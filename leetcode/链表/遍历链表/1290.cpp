class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};