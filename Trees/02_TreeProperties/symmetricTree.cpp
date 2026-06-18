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

bool isSymmetricTrees(node*&root1,node*&root2){
    if(root1 ==nullptr && root2==nullptr) return true;
    if(root1==nullptr || root2==nullptr) return false;
    if(root1->data != root2->data) return false;
    bool r1=isSymmetricTrees(root1->left,root2->right);
    bool r2=isSymmetricTrees(root1->right,root2->left);

    return r1&&r2;
}

int main(){
    vector<int>nodes1={1,2,3,4,5};
    node* root1=arrayToTree(nodes1);
    vector<int>nodes2={1,3,2,-1,-1,5,4};
    node* root2=arrayToTree(nodes2);

    bool symmetric=isSymmetricTrees(root1,root2);
    cout<<symmetric;
}