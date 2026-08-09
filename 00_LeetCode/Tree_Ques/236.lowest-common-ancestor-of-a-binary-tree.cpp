/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
// @lc code=start

class Solution {
public:

    TreeNode* lca(TreeNode* &root,TreeNode* &p, TreeNode* &q)
    {
        if(root==nullptr) return nullptr;
        if(p->val == root->val || q->val == root->val){
            return root;
        }
        TreeNode* lft=lca(root->left,p,q);
        TreeNode* rit=lca(root->right,p,q);

        // conclution in 3 cases
        if(lft!=nullptr && rit!=nullptr){
            return root;
        }
        else if(lft!=nullptr){
            return lft;
        }
        else return rit;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
      return lca(root,p,q);
      

    }
};
// @lc code=end

