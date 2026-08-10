/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// @lc code=start

 

 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    
    // Move fast n steps ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    // If we need to remove the head
    if(fast == nullptr) {
        return head->next;
    }
    
    // Move both until fast reaches the end
    while(fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow is now at the node BEFORE the one to delete
    slow->next = slow->next->next;
    return head;
}
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(head==nullptr) return nullptr;
    //     ListNode* temp=head;
    //     int s=0;
    //     while(temp!=nullptr){
    //         s++;
    //         temp=temp->next;
    //     }
    //     // s = number of total node in this linked list;
    //     if((s==1 && n==1) || s-n==0){
    //         ListNode*temp=head;
    //         head=head->next;
    //         delete(temp);
    //         return head;
    //     }
    //     ListNode* prev=head;
    //     int x=s-n-1;
        
    //     while(x--){
    //         prev=prev->next;
    //     }
    //     ListNode* NodeforDel=prev->next;
    //     prev->next=NodeforDel->next;
    //     delete(NodeforDel);

    //     return head;

    // }
};
// @lc code=end

