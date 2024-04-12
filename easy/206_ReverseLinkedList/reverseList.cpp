/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        return reverseListHelper(nullptr, head);
    }

    ListNode* reverseListHelper(ListNode* lastNode, ListNode* node) {
        if (node->next == nullptr) {
            node->next = lastNode;
            return node;
        }
        ListNode* head = reverseListHelper(node, node->next);
        node->next = lastNode;
        return head;
    }
};