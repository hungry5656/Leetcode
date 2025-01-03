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
    ListNode* removeNthFromEndHelper(ListNode* currNode, ListNode* lastNode, int n, int &num) {
        if (currNode == nullptr) {
            num = 0;
            return nullptr;
        }
        ListNode* nextNode = removeNthFromEndHelper(currNode->next, currNode, n, num);
        num++;
        if (num == n) {
            if (lastNode)
                lastNode->next = nextNode;
            else
                return nextNode;
        }
        return currNode;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        return removeNthFromEndHelper(head, nullptr, n, num);
    }
};