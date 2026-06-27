#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
node* arrayToTree(vector<int>& nodes){
    if(nodes.size()==0 ||nodes[0]==-1) return nullptr;
    node* root=new node(nodes[0]);
    queue<node*>q;
    q.push(root);
    int i=1;
    while(i<nodes.size() && !q.empty()){
        node* curr=q.front();
        q.pop();
        if(nodes[i]!=-1){
            curr->left=new node(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if(i<nodes.size() && nodes[i]!=-1){
            curr->right=new node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
node* invertBinaryTree(node*&root){
    if(root==nullptr) return nullptr;
    node* temp=root->right;
    root->right=root->left;
    root->left=temp;
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

void preorder(node*&root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    vector<int>nodes1={1,2,3,4,5};
    node* root1=arrayToTree(nodes1);
    preorder(root1);
    cout<<endl;
    invertBinaryTree(root1);
    preorder(root1);

    
}