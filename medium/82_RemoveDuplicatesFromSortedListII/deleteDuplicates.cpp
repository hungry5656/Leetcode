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
            ListNode * newHead = new ListNode(101, head);
            ListNode* currNode = head;
            ListNode* lastNode = newHead;
            if (!head) {
                return nullptr;
            }
            int lastVal = currNode->val;
            while (lastNode->next && currNode->next) {
                int currVal = currNode->next->val;
                if (currVal == lastVal) {
                    while (lastNode->next && lastNode->next->val == lastVal) {
                        ListNode* temp = lastNode->next;
                        lastNode->next = lastNode->next->next;
                        delete temp;
                        temp = nullptr;
                    }
                    currNode = lastNode->next;
                    if (lastNode->next) {
                        lastVal = lastNode->next->val;
                    }
                } else {
                    lastNode = lastNode->next;
                    currNode = lastNode->next;
                    lastVal = lastNode->next->val;
                }
            }
            return newHead->next;
        }
    };