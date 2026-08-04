
#include<bits/stdc++.h>
using namespace std;

class Node
{
 public:
 int data;
 Node*left;
 Node*right;
 Node(int val)
 {
  data=val;
  left=right=NULL;
 }
};

Node * builtBST(Node*&root,int val)
{
  if(root==NULL){
    Node*temp=new Node(val);
    return temp;
  }
  // if(val<root->data) go left
  if(val<root->data)
  {
    root->left=builtBST(root->left,val);
  }

  if(val>=root->data)
  {
    root->right=builtBST(root->right,val);
  }
  return root;
}

void preorder(Node*root)
{
  if(root==NULL) return;
  stack<Node*>s;
  s.push(root);
  cout<<"Preorder : ";
  while(!s.empty())
  {
    Node*temp=s.top();
    s.pop();
    cout<<temp->data<<" ";
     if(temp->right!=nullptr) s.push(temp->right);
    if(temp->left!=nullptr) s.push(temp->left);
   
  }
}


int main()
{
  vector<int>arr={1,4,3,2,6,5};
  int i=0;
  Node* root=nullptr;

  for(int i=0;i<arr.size();i++){
    root=builtBST(root,arr[i]);
  }

  preorder(root);
}