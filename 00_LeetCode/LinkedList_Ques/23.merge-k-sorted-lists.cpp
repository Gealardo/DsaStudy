#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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

   void putinarray(ListNode* &headnode,vector<int>&arr){
       if(headnode==nullptr) return ;
       ListNode* temp=headnode;
       while(temp!=nullptr){
          arr.push_back(temp->val);
          temp=temp->next;
       }
       return;
   }

   ListNode* makeAnsList(vector<int>&arr){

       int n=arr.size();
       if(n==0) return nullptr;

       ListNode* head=new ListNode(arr[0]);
       ListNode* connector=head;

       for(int i=1;i<n;i++){
         ListNode* newNode=new ListNode(arr[i]);
         connector->next=newNode;
          connector=newNode;
       }
      return head;
   }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      vector<int>arr;
      
      int n=lists.size();
      for(auto headnode: lists){
        putinarray(headnode,arr);
      }

      sort(arr.begin(),arr.end());

      return makeAnsList(arr);

    }
};
// @lc code=end








    /*
     
     * CURRENT APPROACH: Flatten to Array + Sort
     * - Time Complexity: O(N log N) where N is the total number of nodes.
     * - Space Complexity: O(N) to store all node values.

     * 
     *  TODO FOR REVISION: Priority Queue (Min-Heap) Approach
     * - Why it's better: Reduces Time Complexity to O(N log k) and Space to O(k), 
     *   where 'k' is the number of lists. (Massive win when k is small).
     * - The Logic:
     *   1. Create a Min-Heap (priority_queue) that stores ListNode* pointers.
     *   2. Push the head of each of the 'k' lists into the heap.
     *   3. Pop the smallest node, attach it to our result list.
     *   4. If the popped node has a 'next' node, push that 'next' node into the heap.
     *   5. Repeat until the heap is empty.
    
     */