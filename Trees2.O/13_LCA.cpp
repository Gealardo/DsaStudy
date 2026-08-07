#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
   int data;
   Node* left;
   Node*right;
   Node(int val){
    data=val;
    left=right=NULL;
   }
};

Node* makeTree(){

 cout<<"Enter the val of root: ";
 int rootval,leftval,rightval;
 cin>>rootval;
 if(rootval==-1) {
  cout<<"\nNo Tree!"<<endl;
  return nullptr;
}
 Node*root=new Node(rootval);
 queue<Node*>q;
 q.push(root);

 while(!q.empty()){

   Node* temp=q.front();
   q.pop();

   cout<<"Enter left val of "<<temp->data<<" : ";
   cin>>leftval;
   if(leftval!=-1){
    temp->left=new Node(leftval);
    q.push(temp->left);
   }
   cout<<"Enter right val of "<<temp->data<<" : ";
   cin>>rightval;
   if(rightval!=-1){
    temp->right=new Node(rightval);
    q.push(temp->right);
   }

 }
 cout<<"\nTree Constructed! "<<endl;

 return root;
}


Node* LCA(Node*&root,int p,int q){

  if(root==nullptr) return nullptr;
  
  if(root->data==p||root->data==q){
      return root;// Consider it as its own LCA
  } 

  Node* leftLCA=LCA(root->left,p,q);
  Node* rightLCA=LCA(root->right,p,q);

  // leftSearch and rightSearch both null
  if(leftLCA==NULL && rightLCA==NULL ) return NULL;
  // one null
  else if(leftLCA!=NULL && rightLCA==NULL) return leftLCA;
  else if(leftLCA==NULL && rightLCA!=NULL) return rightLCA;
  // both not null
  else{
    return root;
  }

}


int main(){

 Node* root=makeTree();
  cout<<"-------LCA------"<<endl;
  cout<<"Enter p :";
  int p;
  cin>>p;
    cout<<"\nEnter q :";
  int q;
  cin>>q;
  Node* lca=LCA(root,p,q);
  cout<<"Here is the LCA of "<<p<<" & "<<q<<" : ";

  if(lca!=nullptr){
    cout<<lca->data<<endl;
  }
  else cout<<"LCA NOT FOUND"<<endl;
  

}
