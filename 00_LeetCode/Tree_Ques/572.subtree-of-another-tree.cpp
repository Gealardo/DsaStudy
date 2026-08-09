/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

 
  //Definition for a binary tree node.
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
    
    bool isSame(TreeNode* & root,TreeNode*&subRoot){

          if(root==nullptr && subRoot==nullptr) return true;

          if(root==nullptr || subRoot==nullptr) return false;

          if(root->val !=subRoot->val) return false;

          bool left=isSame(root->left,subRoot->left);
          bool right=isSame(root->right,subRoot->right);

          return left && right;

    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      
        if(root==nullptr) return false;
        if(isSame(root,subRoot)) return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
// @lc code=end

