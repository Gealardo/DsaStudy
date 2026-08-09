/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSame(TreeNode* &p,TreeNode*&q){

       if(p==nullptr && q==nullptr) return true;
       if(p==nullptr || q==nullptr) return false;
       if(p->val != q->val) return false;
       bool l=isSame(p->left,q->left);
       bool r=isSame(p->right,q->right);

       return l&&r;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isSame(p,q);
    }
};
// @lc code=end

