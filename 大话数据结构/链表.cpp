#include <iostream>
#include <cstdlib> // 用于 malloc 和 free
using namespace std;

// 定义链表节点
typedef struct ListNode {
    int val; // 节点的值
    ListNode* next; // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} // 构造函数
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data; // 修正：使用 val 而不是 data
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入节点
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head; // 修正：newNode 而不是 newnode
    *head = newNode; // 修正：添加分号
}

// 删除指定值的节点
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL; // 修正：*head 而不是 *had
    if (temp != NULL && temp->val == key) { // 修正：val 而不是 DATA
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->val != key) { // 修正：val 而不是 data
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// 更新指定值的节点
void updateNode(Node* head, int key, int newData) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == key) { // 修正：val 而不是 data
            temp->val = newData; // 修正：val 而不是 data
            break;
        }
        temp = temp->next;
    }
}

// 查找指定值的节点
Node* searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == key) { // 修正：val 而不是 data
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 反转链表
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

Node* reverse(Node* head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;  
}
// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " "; // 修正：val 而不是 data
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL; // 初始化链表为空

    // 插入节点
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    cout << "插入后的链表: ";
    printList(head);

    // 删除节点
    deleteNode(&head, 2);
    cout << "删除后的链表: ";
    printList(head);

    // 更新节点
    updateNode(head, 3, 30);
    cout << "更新后的链表: ";
    printList(head);

    // 查找节点
    Node* found = searchNode(head, 30);
    if (found) {
        cout << "找到节点: " << found->val << endl;
    } else {
        cout << "未找到节点" << endl;
    }

    // 反转链表
    reverseList(&head);
    cout << "反转后的链表: ";
    printList(head);

    return 0;
}