/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

 // Definition for singly-linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        //----------------
        ListNode* dummyNode=new ListNode(-1);
        ListNode* connector=dummyNode;
        //----------------
        int carry=0;
        while(temp1!=nullptr && temp2!=nullptr){
            int sum= (temp1->val) + (temp2->val) +carry;
            int val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(val);
            connector->next=newNode;
            connector=newNode;

            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=nullptr){
            int sum= (temp1->val) + carry;
            int val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(val);
            connector->next=newNode;
            connector=newNode;

            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            int sum= (temp2->val) + carry;
            int val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(val);
            connector->next=newNode;
            connector=newNode;

            temp2=temp2->next;
        }

        if(carry!=0){
            ListNode* newNode=new ListNode(carry);
            connector->next=newNode;
            connector=newNode;
        }
       
         return dummyNode->next;

    }
};
// @lc code=end








/* if want all in one loop
 while(l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if(l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int val = sum % 10;
        
        connector->next = new ListNode(val);
        connector = connector->next;
    }
    
    return dummy->next;
}
*/