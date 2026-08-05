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

bool search(Node*root,int target)
{
  if(root==nullptr) return false;
  if(target==root->data) return true;
  if(target<root->data) return search(root->left,target); 
  if(target>root->data) return search(root->right,target);
  return false;  
}

int main()
{
  vector<int>arr={1,2,7,9,5};
  Node* root=nullptr;
  for(int i=0 ; i<arr.size() ;i++)
  {
    root=bstBuilt(root,arr[i]);
  }
  cout<<(search(root,3));
}