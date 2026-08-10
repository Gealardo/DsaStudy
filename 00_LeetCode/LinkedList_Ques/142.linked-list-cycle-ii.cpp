/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
// @lc code=start

 // Definition for singly-linked list.
 
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        bool cycleFound=false;
        while(fast!=nullptr && fast->next!=nullptr){
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast){
                cycleFound=true;
                break;
             }
        }
        if(cycleFound){

          fast=head;

          while(fast!=slow){
              fast=fast->next;
              slow=slow->next;
          }
           
           return fast;
        }
        else {
           
          return nullptr;
        }
        
    }
};
// @lc code=end

