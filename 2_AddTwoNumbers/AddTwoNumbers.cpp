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
#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *SolutionNode = nullptr;
        ListNode *CurrentNode1 = l1;
        ListNode *CurrentNode2 = l2;
        int currentNum = 0;
        int CarryOut = 0;
        int i = 0;
        while(!((CurrentNode1 == nullptr)&&(CurrentNode2 == nullptr)&&(CarryOut==0))){
            ListNode *CurrentN = new ListNode();
            if (CurrentNode1 == nullptr){
                if (CurrentNode2 == nullptr){
                    currentNum = 1;
                } else {
                    currentNum = CurrentNode2->val + CarryOut;
                    CurrentNode2 = CurrentNode2->next;
                }
            } else if (CurrentNode2 == nullptr){
                currentNum = CurrentNode1->val + CarryOut;
                CurrentNode1 = CurrentNode1->next;
            } else {
                currentNum = CurrentNode1->val + CurrentNode2->val + CarryOut;
                CurrentNode1 = CurrentNode1->next;
                CurrentNode2 = CurrentNode2->next;
            }
            if (currentNum > 9){
                currentNum = currentNum - 10;
                CarryOut = 1;
            } else {
                CarryOut = 0;
            }
            CurrentN->val = currentNum;
            if (SolutionNode == nullptr){
                SolutionNode = CurrentN;
                continue;
            }
            ListNode* CNode = SolutionNode;
            while (CNode->next != nullptr){
                CNode = CNode->next;
            }
            CNode->next = CurrentN;
        }
        return SolutionNode;
    }
};