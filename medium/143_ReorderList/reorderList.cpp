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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodeQueue;
        ListNode* currNode = head;
        while (currNode != nullptr) {
            nodeQueue.push_back(currNode);
            currNode = currNode->next;
        }
        currNode = head;
        int front = 1, back = nodeQueue.size() - 1;
        bool isFront = false;
        while (front <= back) {
            if (isFront) {
                currNode->next = nodeQueue[front];
                front++;
            } else {
                currNode->next = nodeQueue[back];
                back--;
            }
            isFront = !isFront;
            currNode = currNode->next;
        }
        currNode->next = nullptr;
    }
};