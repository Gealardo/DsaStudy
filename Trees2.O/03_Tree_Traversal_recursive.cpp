//-------recursivily------Time O(n),space O(h);DFS
// p3) Preorder
// p4) Inorder
// p5) Postorder
// p6) Height of tree


#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data=val;
    left= nullptr;
    right=nullptr;
  }
};

Node* BinaryTree(){
  int rootval;
  cin>>rootval;
  if(rootval==-1) return nullptr;
  Node*temp=new Node(rootval);
  //left
  cout<<"Enter Left child of "<<rootval<<": ";
  temp->left= BinaryTree();
 
  //right
  cout<<"Enter Right child of "<<rootval<<": ";
  temp->right= BinaryTree();
  return temp;
}

void pre(Node*root){
  if(root==nullptr) return ;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}

void In(Node*root){
  if(root==nullptr) return ;
  In(root->left);
  cout<<root->data<<" ";
  In(root->right);
}

void post(Node*root){
  if(root==nullptr) return ;
  post(root->left);
  post(root->right);
  cout<<root->data<<" ";
}

int height(Node* root){

  if(root==nullptr) return 0;
  int left=height(root->left);
  int right=height(root->right);
  return 1+ max(left,right);
}
int main(){

  Node* root;
  cout<<"Enter root value : ";
  root = BinaryTree();
  
  cout<<"----Traversal Result-----\n";
  cout<<"PreOrder :";
  pre(root);

  cout<<"\nInOrder :";
  In(root);

  cout<<"\nPostOrder :";
  post(root);

  int h=height(root);
  cout<<"\nHeight of Above Tree : "<<h-1<<endl;

  return 0;
}