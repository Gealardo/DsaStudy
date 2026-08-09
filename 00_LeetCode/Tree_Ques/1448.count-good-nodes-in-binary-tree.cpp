#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */



 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 
// @lc code=start
class Solution {
public:
    int GN(TreeNode*root,int maxval){
        int count=0;
        if(root==nullptr) return count;
        stack<pair<TreeNode*,int>>st;
        st.push({root,root->val});
        
        
        while(!st.empty()){
    
            TreeNode* temp=st.top().first;
            int curmax=st.top().second;
            st.pop();
           
            if(temp->val >= curmax){
                count++;
            }
            int nextmax=max(temp->val,curmax);

            if(temp->right!=NULL) st.push({temp->right,nextmax});
            if(temp->left!=NULL) st.push({temp->left,nextmax});

        }
      return count;

    }

   int Rec(TreeNode*root,int maxval){

     if(root==nullptr) return 0;
     int count=0;
     if(root->val>=maxval){
       count=1;
     }
     maxval=max(maxval,root->val);

     count = count+ Rec(root->left,maxval);
     count =count + Rec(root->right,maxval);

    return count;

   }


    int goodNodes(TreeNode* root) {
        return GN(root,root->val);
       //return Rec(root,root->val);
    }
};
// @lc code=end

