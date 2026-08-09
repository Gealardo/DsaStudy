
#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
vector<int> rightView(TreeNode* root)
  {
     vector<int>ans;
     //base case
     if(root==nullptr) return ans;

     queue<TreeNode*>q;
     q.push(root);
     
     while(!q.empty()){
       int n=q.size();
       ans.push_back(q.front()->val);
       for(int i=0;i<n;i++){
          TreeNode* temp=q.front();
          q.pop();

          if(temp->right!=nullptr) q.push(temp->right);
          if(temp->left!=nullptr) q.push(temp->left);
          

       }

     }

     return ans;
  }
    vector<int> rightSideView(TreeNode* root) {
        
       return  rightView(root);

    }
};
// @lc code=end

