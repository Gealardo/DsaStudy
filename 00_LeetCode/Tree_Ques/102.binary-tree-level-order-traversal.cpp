#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
     
  vector<vector<int>> LOT(TreeNode* root)
  {
     vector<vector<int>>ans;
     //base case
     if(root==nullptr) return ans;

     queue<TreeNode*>q;
     q.push(root);
     
     while(!q.empty()){
       int n=q.size();
       vector<int>level(n,0);
       for(int i=0;i<n;i++){
          TreeNode* temp=q.front();
          q.pop();
          level[i]= temp->val;

          if(temp->left!=nullptr) q.push(temp->left);
          if(temp->right!=nullptr) q.push(temp->right);

       }
       ans.push_back(level);

     }

     return ans;
  }


    vector<vector<int>> levelOrder(TreeNode* root) {
        
       return LOT(root);

    }
};
// @lc code=end

