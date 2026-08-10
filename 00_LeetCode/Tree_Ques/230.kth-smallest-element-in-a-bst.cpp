/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    
    int fun(TreeNode* &root,int &i,int k){
        if(root==nullptr) return -1;
        
       //left
       int left=fun(root->left,i,k);
       if(left!=-1) return left;
        
       i++;
       //root
       if(i==k) return root->val;
       
       //right
       int right=fun(root->right,i,k);
       if(right!=-1) return right;

       return -1;

    }

    int kthSmallest(TreeNode*& root, int k) {
        int i=0;
        return fun(root,i,k);
    }
};
// @lc code=end

