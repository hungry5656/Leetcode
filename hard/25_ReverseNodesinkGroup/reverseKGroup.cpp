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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        int currK = k;
        ListNode* curr = head, *next = curr->next, *temp;
        while (currK > 0 && curr){
            curr = curr->next;
            currK--;
        }
        // not enough k
        if (currK != 0)
            return head;

        curr = head;
        currK = k - 1;
        while (currK > 0) {
            temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
            currK--;
        }
        head->next = reverseKGroup(next, k);
        return curr;
    }
};