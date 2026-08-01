#include<bits/stdc++.h>
using namespace std;


class Node
{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int val)
  {
    data=val;
    left=nullptr;
    right=nullptr;
  }
};

Node* MakeTree(const vector<int>&arr)
{
  int n=arr.size();
  if(n==0 || arr[0]==-1)return nullptr;
  Node* root=new Node(arr[0]);
  int i=0;
  queue<Node*>q;
  q.push(root);
  i++;
  while(i<n){
    Node* temp=q.front();
    q.pop();

    if(arr[i]!=-1)
    {
      temp->left=new Node(arr[i]);
      q.push(temp->left);
    }
    i++;
    if(i<n && arr[i]!=-1)
    {
      temp->right=new Node(arr[i]);
      q.push(temp->right);
    }
    i++;
  }
  return root;
  
}

// preorder Root Left Right
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
    if(temp->left!=nullptr) s.push(temp->left);
    if(temp->right!=nullptr) s.push(temp->right);
  }
}

// inorder Left Root Right
void inorder(Node*root)
{
  if(root==nullptr)return ;
  stack<Node*>s;
  Node* temp=root;
  cout<<"Inorder : ";
  while(!s.empty() || temp!=nullptr)
  {
    while(temp!=nullptr){
      s.push(temp);
      temp=temp->left;
    }
    temp=s.top();
    s.pop();
    cout<<temp->data<<" ";
    temp=temp->right;
  }
}


int main(){
  vector<int>arr={1,2,3,4,5,6};
  Node*root=MakeTree(arr);
  preorder(root);
  cout<<"\n";
  inorder(root);
}