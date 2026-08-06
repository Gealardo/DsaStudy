#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
  int data;
  node*left;
  node*right;
  node(int val){
    data=val;
    left=right=nullptr;
  }
};

node* makeBST(node*&root,int val)
{
  if(root==nullptr) {
    root=new node(val);
   return root;
  }
  else if(root->data >val){
    root->left=makeBST(root->left,val);
  }
  else{
    root->right=makeBST(root->right,val);
  }
  return root;
}


void takeInputs(node* &root){
  
  cout<<"Enter no. of elem in bst: ";
  int n;
  cin>>n;
  cout<<"Enter elements of bst: ";
  int x;
  while(n--){
    cin>>x;
    makeBST(root,x);
  }
  
}

int findSmallest(node*&root,int &i,int k)
{
  if(root==nullptr)  return -1;
  //left
  int left=findSmallest(root->left,i,k);
  if(left!=-1) return left;
  //node
  i++;
  if(i==k) return root->data;

  //right
  int right=findSmallest(root->right,i,k);
  if(right!=-1) return right;

  return -1;

}

//--------------------------------------------------
int findLargest(node*&root,int &j,int l)
{
  if(root==nullptr)  return -1;
   //right
  int right=findLargest(root->right,j,l);
  if(right!=-1) return right;
 
  //node
  j++;
  if(j==l) return root->data;

  //left
  int left=findLargest(root->left,j,l);
  if(left!=-1) return left;

  return -1;
}

//---------------------------------------------------

void inorder(node* &root){
  if(root==nullptr) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main(){
  node* root=nullptr;
  takeInputs(root);

  int k;
  int i=0;
  cout<<"Enter No. of smallest element requires: ";
  cin>>k;
  int s=findSmallest(root,i,k);
  cout<<"\n Small-val: "<<s;

  int l;
  int j=0;
  cout<<"\nEnter No. of largest element requires: ";
  cin>>l;
  int p=findLargest(root,j,l);
  cout<<"\n Lar-val: "<<p;
  cout<<"\ninorder: ";
  inorder(root);
}