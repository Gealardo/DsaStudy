
// p8) size of a tree (p stards for problem no.)

#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
  int data;
  Node*left,*right;
  Node(int val){
    data=val;
    left=right=nullptr;
  }
};

Node* BuiltTree(const vector<int>& arr){

  int n=arr.size();
  if(n==0 || arr[0]==-1) return nullptr;
  int i=0;
  Node *root=new Node(arr[i]);
  i++;
  queue<Node*>q;
  q.push(root);
  while(i<n){
    Node* temp=q.front();
    q.pop();
    //left
    if(arr[i]!=-1){
      temp->left=new Node(arr[i]);
      q.push(temp->left);
    }
    i++;
    //right
    if(i<n && arr[i]!=-1){
       temp->right=new Node(arr[i]);
      q.push(temp->right);
    }
    i++;
  }
  return root;

}

int findSize(Node*&root){
  if(root==nullptr ) return 0;
  int left=findSize(root->left);
  int right=findSize(root->right);
  return left+right+1;
}
int s=0;
int findSum(Node*root){
  if(root==nullptr ) return 0;
  int left=findSum(root->left);
  int right=findSum(root->right);
  return s=s+root->data;
}

// count of lafe nodes
void lnodes(Node*root,int &c){
   if(root==nullptr) return; 
  if(root->left ==NULL && root->right==NULL ) {
    c++;
    return;
  }
  lnodes(root->left,c);
  lnodes(root->right,c);
}
// for non leaf nodes
// void lnodes(Node*root,int &c){
//    if(root==nullptr) return; 
//   if(root->left !=NULL || root->right!=NULL ) {
//     c++;
    
//   }
//   lnodes(root->left,c);
//   lnodes(root->right,c);
// }


int main(){
  vector<int>arr={1,2,3,4};
  Node* root=BuiltTree(arr);
  
  int size=findSize(root);
  cout<<size;
  int p=findSum(root);
  cout<<"\nSum : ";
  cout<<s;
  
  int c=0;
  lnodes(root,c);

  cout<<"\nLeaf count : "<<c;
  

}