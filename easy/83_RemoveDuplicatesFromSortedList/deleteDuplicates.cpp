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
    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicatesHelper(head, -1000);
    }

    ListNode* deleteDuplicatesHelper(ListNode* head, int CheckVal) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val == CheckVal) {
            head = deleteDuplicatesHelper(head->next, head->val);
        } else {
            head->next = deleteDuplicatesHelper(head->next, head->val);
        }
        return head;
    }
};