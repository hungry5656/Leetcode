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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        
        ListNode* retNode = head;
        
        rotateRightHelper(nullptr, head, &retNode, k, 1);
        return retNode;
    }
    int rotateRightHelper(ListNode* last, ListNode* currNode, ListNode **retNode, int k, int size) {
        if (currNode == nullptr) {
            int retK = k % (size - 1);
            if (retK == 0) {
                return 0;
            }
            last->next = *retNode;
            return retK;
        }
        int numK = rotateRightHelper(currNode, currNode->next, retNode, k, size + 1);
        if (numK == 1) {
            last->next = nullptr;
            *retNode = currNode;
            return 0;
        } else if (numK == 0) {
            return 0;
        }
        return numK - 1;
    }
};