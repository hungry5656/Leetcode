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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode *temp = lists[i];
            while(temp){
                pq.push({temp->val,temp});
                temp= temp->next;
            }
        }
        
        ListNode *res = NULL, *mov = NULL;
        while(!pq.empty()){
            ListNode *temp = pq.top().second;
            pq.pop();
            if(res == NULL){
                res = temp;
                mov = res;
            }else{
                mov = temp;
                mov->next = res;
                res= mov;
            }
        }
        return mov;
    }
};


/* original solution
class Compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* startNode = new ListNode(0);
        ListNode* cNode = startNode;
        for (int i = 0; i < lists.size(); ++i) {
            if (!lists[i]) {
                continue;
            }
            pq.push(lists[i]);
        }

        while (!pq.empty()) {
            ListNode* currNode = pq.top();
            pq.pop();
            cNode->next = currNode;
            cNode = cNode->next;
            if (currNode->next) {
                pq.push(currNode->next);
            }
        }
        return startNode->next;
    }
};
*/