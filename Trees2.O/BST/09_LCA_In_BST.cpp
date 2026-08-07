#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val){data=val;left=right=NULL;}
};

Node* bstBuilt(Node* root,int val)
{
  if(root==nullptr)
  {
    root=new Node(val);
  }
  
  if(root->data >val) root->left=bstBuilt(root->left,val);

  if(root->data <val) root->right=bstBuilt(root->right,val);

  return root;
}


// O(n) time complexity
Node* LCAinBST(Node*&root,int p,int q)
{
    //base case
    if(root==NULL) return NULL;

    // find p and q in bst
    if(root->data==p || root->data==q)
    {
      return root;
    }
    
  
      Node* leftLCA= LCAinBST(root->left,p,q);
      Node* rightLCA= LCAinBST(root->right,p,q);
  

    if(leftLCA!=NULL && rightLCA!=NULL) return root;
    else if(leftLCA!=NULL) return leftLCA;
    else{
      return rightLCA;
    }

}

// O(H) time complexity
Node* LCAinBST_Optimized(Node* root, int p, int q) {
    if (root == nullptr) return nullptr;

    // 1. If BOTH p and q are SMALLER than root, the LCA MUST be in the left subtree
    if (p < root->data && q < root->data) {
        return LCAinBST_Optimized(root->left, p, q);
    }
    
    // 2. If BOTH p and q are GREATER than root, the LCA MUST be in the right subtree
    if (p > root->data && q > root->data) {
        return LCAinBST_Optimized(root->right, p, q);
    }
    
    // 3. WE FOUND THE SPLIT POINT!
    // This happens if:
    // - One value is on the left and the other is on the right.
    // - OR one of the values IS the root itself.
    // In either case, the current root is the Lowest Common Ancestor.
    return root; 
}

//O(H) time complexity and O(1) space complexity
Node* LCA_BST_Iterative(Node* root, int p, int q) {
    while (root != nullptr) {
        if (p < root->data && q < root->data) {
            root = root->left;       // Both are smaller, go left
        } 
        else if (p > root->data && q > root->data) {
            root = root->right;      // Both are greater, go right
        } 
        else {
            return root;             // We found the split point!
        }
    }
    return nullptr;
}


int main()
{
  vector<int>arr={1,2,7,9,5};
  Node* root=nullptr;
  for(int i=0 ; i<arr.size() ;i++)
  {
    root=bstBuilt(root,arr[i]);
  }

  
  cout<<"-------LCA------"<<endl;
  cout<<"Enter p :";
  int p;
  cin>>p;
    cout<<"\nEnter q :";
  int q;
  cin>>q;
  Node* lca=LCAinBST(root,p,q);
  cout<<"Here is the LCA of "<<p<<" & "<<q<<" : ";

  if(lca!=nullptr){
    cout<<lca->data<<endl;
  }
  else cout<<"LCA NOT FOUND"<<endl;
 
}