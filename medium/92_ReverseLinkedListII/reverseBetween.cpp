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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode(0, head);
            ListNode* lNode, *cNode = dummy;
            for (int i = 0; i < left - 1; ++i) {
                cNode = cNode->next;
            }
            lNode = cNode->next;
            for (int i = 0; i < right - left; ++i) {
                ListNode* temp = lNode->next;
                lNode->next = temp->next;
                temp->next = cNode->next;
                cNode->next = temp;
            }
            return dummy->next;
        }
    };