//p2) TREE BUILDING BY RECURTION(STACK) (DFS);

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
int main(){

  Node* root;
  cout<<"Enter root value : ";
  root = BinaryTree();
}