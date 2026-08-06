

// validating is it a bst or not
#include <bits/stdc++.h>
using namespace std;

class node
{
  public:
   int data;
   node* left;
   node* right;
   node(int val){
    data=val;
    left=right=nullptr;
   }
};


node* makeBST(node*&root,int val)
{
   if(root==nullptr)
   {
    root = new node(val);
    return root;
   }
   else if(val>root->data)
   {
      root->right=makeBST(root->right,val);
   }
   else{
     root->left=makeBST(root->left,val);
   }
   return root;
}


void takeInput(node*&root)
{
  cout<<"Enter No. of elememt in Bst: ";
  int n;
  cin>>n;
  cout<<"Enter elements of Bst: "<<endl;
  int x;
  while(n--){
    cin>>x;
    makeBST(root,x);
  }
}
// for validation a binary search tree
bool IsBST(node* &root, int min,int max){
  
  //if root is null return true
  if(root== nullptr) return 1;

  // check root data under -infi to +infi.
  // go left where max will be root data(root->data >= left->data)
  // go right where min will be root data (root->data <=right->data)
  if(root->data >=min && root->data<=max)
  {
    bool left=IsBST(root->left,min,root->data);
    bool right=IsBST(root->right,root->data,max);
    return left && right;
  }
  
  return 0;

}


void inorder(node* &root){
  if(root==nullptr) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main(){
  node*root=nullptr;
  takeInput(root);

  cout<<"Inorder: ";
  inorder(root);

  cout<<"\nIs Tree a BST: ";
  cout<<IsBST(root,INT_MIN,INT_MAX);
}