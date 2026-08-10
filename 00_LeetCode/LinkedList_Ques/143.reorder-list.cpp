#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

//  Definition for singly-linked list.
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

    void reorder(ListNode* &head,vector<int>&ll){
           int n=ll.size();
           int idx=0;
           ListNode*temp=head;
           while(temp!=nullptr){

            temp->val=ll[idx++];

            temp=temp->next;
           }

    }
    

    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        int n=arr.size();
        vector<int>arr2(n,-1);
         for(int i=n-1;i>=0;i--){
            arr2[n-1-i]=arr[i];
         }

        vector<int>ll(n,-1);
        int idx=0;
        for(int i=0;i<n;i++){
          if(idx<n)  ll[idx++]=arr[i];
          if(idx<n)  ll[idx++]=arr2[i];
          if(idx>=n) break;
        } 

        reorder(head,ll);
        return;
        
    }
    /*
    //for space optimization (pending to implement)
    void reorderList(ListNode* head) {
    // Step 1: Find the middle (slow/fast pointers)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse the second half (you already did this!)
    ListNode* second = reverseList(slow->next);
    slow->next = nullptr;
    
    // Step 3: Merge the two halves alternately
    ListNode* first = head;
    while(second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        
        first->next = second;
        second->next = temp1;
        
        first = temp1;
        second = temp2;
    }
}
    */
};
// @lc code=end

