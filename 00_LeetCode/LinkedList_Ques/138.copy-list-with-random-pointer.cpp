#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// @lc code=start



class Solution {
public:

    Node* makenewList(Node* head) {
        if(head== nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        
        Node* chead=new Node(head->val);
        mp[head]=chead;

        Node* connector=chead;
        Node* temp=head->next;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            mp[temp]=newNode;
            connector->next=newNode;
            connector=newNode;
            temp=temp->next;
        }
        Node* tempCRandom=nullptr;
        Node* tempChead=chead;

        Node* tempRandom=nullptr;
        Node* temphead=head;
        while(temphead!=nullptr){

            tempRandom=temphead->random; //pick the random of original
          //  tempCRandom=tempRandom;  //this is worng i think// put in random of copylist
      
            if(tempRandom) tempCRandom=mp[tempRandom];
            else tempCRandom=nullptr;



            tempChead->random=tempCRandom;

            //--------------
            tempRandom=tempCRandom=nullptr;
            temphead=temphead->next;
            tempChead=tempChead->next;
        }

        return chead;
        
    }


    Node* copyRandomList(Node* head) {
        return makenewList(head);
    }
};
// @lc code=end

