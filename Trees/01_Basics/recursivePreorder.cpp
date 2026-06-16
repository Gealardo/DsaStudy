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
node* arraytoTree(vector<int> & nodes){
    if(nodes.size()==0 || nodes[0]==-1 ) return nullptr;
    node* root = new node(nodes[0]);
    queue< node* > q;
    q.push(root);
    int i=1;
    while(i<nodes.size()){
        node* current=q.front();
        q.pop();
        if(nodes[i]!=-1){
        current->left=new node(nodes[i]);
        q.push(current->left);
        }
        i++;
        if(nodes[i]!=-1 && i<nodes.size()){
            current->right=new node(nodes[i]);
        q.push(current->right);
        }
        i++;
    }
    return root;
}
void preorder(node* &root){
   // left->right->root
   if(root==nullptr) return;

   cout<<root->data<<" ";

   preorder(root->left);
   
   preorder(root->right);

   
   
}
int main(){
    vector<int>nodes={1,4,6,8,2,-1,0,-1};
    node* root=arraytoTree(nodes);
    preorder(root);
}