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

vector<int> postOrder(node* &root){
    if(root==nullptr) return {};
    //reverse of root->right->left;
    vector<int>rev_post;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node* curr=st.top();
        st.pop();
          rev_post.push_back(curr->data);
         if(curr->left!=nullptr) st.push(curr->left);
        if(curr->right!=nullptr) st.push(curr->right);
       
     }
     return rev_post;

}
   
//------------------------------------------------
 

int main(){
    vector<int>nodes={5,2,5,6,1,2};
    node* root=arraytoTree(nodes);
    vector<int>post_order=postOrder(root);
    for(int i=post_order.size()-1;i>=0;i--){
         cout<<post_order[i]<<" ";
    }
    
}