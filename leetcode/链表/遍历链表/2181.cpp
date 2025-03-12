class Solution {
    public:
        ListNode* mergeNodes(ListNode* head) {
            ListNode* dummy = new ListNode(0); // 虚拟头节点
            ListNode* tail = dummy; // 用于构建新链表
            ListNode* curr = head->next; // 从第一个节点开始遍历
            int sum = 0;
    
            while (curr) {
                if (curr->val == 0) {
                    // 遇到 0，将 sum 存入新节点
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0; // 重置 sum
                } else {
                    sum += curr->val; // 累加节点值
                }
                curr = curr->next; // 移动到下一个节点
            }
    
            return dummy->next; // 返回新链表的头节点
        }
    };