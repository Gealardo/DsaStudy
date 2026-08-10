#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
   void hmp(vector<int>&inorder,unordered_map<int,int> &mp){

      int n=inorder.size();

       for(int i=0;i<n;i++){
        
        mp[inorder[i]]=i; 

       }
   }
   
//    int  search(vector<int>&inorder,int inStart,int inEnd,int rootval){
//        int n=inorder.size();

//        for(int i=0;i<n;i++){
        
//          if(inorder[i]==rootval) return i; 

//        }

//        return -1;        

//    }    

    TreeNode* makeTree(vector<int>&preorder,vector<int>&inorder,int &preIdx,int inStart,int inEnd,unordered_map<int,int>&mp){

       int n=preorder.size();
       if(preIdx>=n || inStart > inEnd) return nullptr;
       
       TreeNode* root=new TreeNode(preorder[preIdx]);

       //int rootIdx=search(inorder,inStart,inEnd,preorder[preIdx]);
       int rootIdx=mp[preorder[preIdx]];
       preIdx++;

       root->left=makeTree(preorder,inorder,preIdx,inStart,rootIdx-1,mp);
      
       root->right=makeTree(preorder,inorder,preIdx,rootIdx+1,inEnd,mp);

       return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
       int preIdx=0;
       int inStart=0;
       int inEnd=inorder.size()-1;
          unordered_map<int,int>mp;
          hmp(inorder,mp);

       return makeTree(preorder,inorder,preIdx,inStart,inEnd,mp);


    }
};
// @lc code=end

