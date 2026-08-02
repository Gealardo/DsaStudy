// preorder + inorder = complete unique tree

#include<bits/stdc++.h>
using namespace std;


class node
{ public:
  int data; node*left;node*right;
  node(int val){data=val; right=left=NULL;}
};


int search(int rootval,vector<int>&in,int left,int right)
{
  for(int i=left;i<=right;i++)
  {
    if(in[i]==rootval) return i;
  }
  return -1; //never execute , provided input should be correct.
}


node* BuiltTree( vector<int>&pre,vector<int>&in,int &preIdx,int left,int right)
{
   if(left>right ) return NULL; // no left or right root exist. 
   node* root=new node(pre[preIdx]);
   
   int rootIdx=search(pre[preIdx],in,left,right);
   preIdx++;
   root->left=BuiltTree(pre,in,preIdx,left,rootIdx-1);
   root->right=BuiltTree(pre,in,preIdx,rootIdx+1,right);
   
   return root;
}

// find inorder to verify the constructed tree
void inorder(node* &root){
  stack<node*>s;
  node* temp=root;
  cout<<"Inorder : ";
  while(!s.empty() || temp!=NULL)
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
  vector<int>pre={1, 2, 4, 5, 3};
  vector<int>in={4,2,5,1,3};
  int left =0;
  int right=pre.size()-1;  
  int preIdx=0;  
  node* root=BuiltTree(pre,in,preIdx,left,right);

  inorder(root);
}