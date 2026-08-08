#include<bits/stdc++.h>
using namespace std;

class Node{public: int data;Node*left;Node*right;Node(int val){
data=val;left=right=NULL;}};


Node* makeBST(Node*&root,int val){
  if(root==NULL){
    root=new Node(val);
    return root;
  }
  else if(val< root->data) root->left=makeBST(root->left,val);
  else root->right=makeBST(root->right,val);

  return root;
}




 //for converting Inorder node array to list
Node* flattenList(vector<Node*>&In){
  int n=In.size();
  int flag=false;
  Node* ListHead=NULL;
 for(int i=0;i<n;i++){
    
    Node*temp=In[i];
    temp->left=NULL;
    if(i+1<n) temp->right=In[i+1];
    else temp->right=NULL;


    // taking the head of list out;
    if(flag==false){
      ListHead=temp;
      flag=true;
    }
 }

 return ListHead;

} 


void printList(vector<Node*>&In){
  Node*head=flattenList(In);
  if(head==NULL);
  Node* temp=head;
  while(temp!=nullptr){

    cout<<temp->data<<"->";
    temp=temp->right;
  }
  cout<<"NULL"<<endl;
  
}


void inorder(Node* root,vector<Node*>&In) {
    if (root == nullptr) return;
    inorder(root->left,In);
    In.push_back(root);
    inorder(root->right,In);
}

int main(){
  vector<int>arr={1,4,7,8,9,11};
  Node*root=NULL;
  for(auto i:arr){
    root= makeBST(root,i);
  }

 vector<Node*>In;
 inorder(root,In);

 printList(In);

}