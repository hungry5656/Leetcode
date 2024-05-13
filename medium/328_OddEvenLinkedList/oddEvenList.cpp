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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode* secondNodeHeader = nullptr, *currSecondNode = nullptr;
        ListNode* currNode = head->next, *currFirstNode = head;
        int i = 1;
        while (currNode) {
            if ((i % 2) == 1) {
                if (!secondNodeHeader) {
                    secondNodeHeader = currNode;
                    currSecondNode = currNode;
                } else {
                    currSecondNode->next = currNode;
                    currSecondNode = currNode;
                }
            } else {
                currFirstNode->next = currNode;
                currFirstNode = currNode;
            }
            currNode = currNode->next;
            i++;
        }
        if (!secondNodeHeader)
            return head;
        currFirstNode->next = secondNodeHeader;
        currSecondNode->next = nullptr;
        return head;
    }
};