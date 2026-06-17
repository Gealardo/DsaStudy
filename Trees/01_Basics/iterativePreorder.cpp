#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
node* arraytoTree(vector<int>arr){
    if(arr.size()==0 || arr[0]==-1) return nullptr;
    node* root=new node(arr[0]);
    queue<node*>q;
    q.push(root);
    int i=1;
    while(i<arr.size()){
        node* curr=q.front();
        q.pop();
        if(arr[i]!=-1){
            curr->left=new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(arr[i]!=-1 && i<arr.size()){
            curr->right=new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
//-------------iterative mehtod--------


void iterative_preorder(node*root){
    if(root==nullptr) return;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node* curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right!=nullptr) st.push(curr->right);
        if(curr->left!=nullptr) st.push(curr->left);
    }
   
}
   
  
//-------------------------------------

void preorde_rec(node* & root){
     if(root==nullptr) return;
     cout<<root->data<<" ";
     preorde_rec(root->left);
     preorde_rec(root->right);
}



int main(){
  vector<int>arr={1,-1,3};
  node* root=arraytoTree(arr);
  preorde_rec(root);
  cout<<endl;
  iterative_preorder(root);
}
