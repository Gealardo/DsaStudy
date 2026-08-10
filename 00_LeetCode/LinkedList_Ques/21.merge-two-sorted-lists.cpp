/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  // make a new linked list;
  // take two pointer to each sorted ll
  // compare and link the nodes..
   
    ListNode* newLL(ListNode* &list1, ListNode* &list2) {
        ListNode* Head=nullptr;
        
        ListNode* dummyNode=new ListNode(-1);
        ListNode* connector=dummyNode;
        ListNode* temp1=list1;
        
        ListNode* temp2=list2;

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val < temp2->val){
                Head=new ListNode(temp1->val);
                connector->next=Head;
                connector=Head;
                Head=Head->next;
                temp1=temp1->next;
            }
            else{

                Head=new ListNode(temp2->val);
                temp2=temp2->next;
                connector->next=Head;
                connector=Head;
                Head=Head->next;

            }     
        }
        while(temp1!=nullptr){
            Head=new ListNode(temp1->val);
            connector->next=Head;
            connector=Head;
            Head=Head->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            Head=new ListNode(temp2->val);
            connector->next=Head;
            connector=Head;
            Head=Head->next;
            temp2=temp2->next;
        }
        return dummyNode->next;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return newLL(list1,list2);
    }
};
// @lc code=end

