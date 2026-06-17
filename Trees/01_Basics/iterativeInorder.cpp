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
//--------------------------------------------
void inorder_iterative(node*root){
      stack<node*>s;
      node* curr=root;
      while(curr!=nullptr || !s.empty()){
        while(curr!=nullptr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
      }
}
   
//--------------------------------------------
void inorder(node* &root){
   // left->root->right
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
 
}
int main(){
    vector<int>nodes={5,2,5,6,1,2};
    node* root=arraytoTree(nodes);
    inorder(root);
    cout<<endl;
    inorder_iterative(root);
    
}