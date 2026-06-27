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
    if(nodes.size()==0 || nodes[0]==-1) return nullptr;
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

// Check if tree satisfies Children Sum Property
bool isChildrenSum(node* root){
    if(root==nullptr) return true;
    if(root->left == nullptr && root->right == nullptr) return true;
    // left data;
   int x=0;
    if(root->left!=nullptr)  x=root->left->data;
    //right
    int y=0;
    if(root->right!=nullptr) y=root->right->data;
    if(root->data!=(x+y)) return false;

    return isChildrenSum(root->left)&& isChildrenSum(root->right);
}

int main(){
    // Test Case 1: Satisfies Property
    //         14
    //        /  \
    //       8    6
    //      / \    \
    //     3   5    6
    vector<int> nodes1 = {14, 8, 6, 3, 5, -1, 6};
    node* root1 = arrayToTree(nodes1);
    cout << "Tree 1: " << (isChildrenSum(root1) ? "True" : "False") << " (Expected: True)\n";

    // Test Case 2: Does NOT Satisfy Property
    //         10
    //        /  \
    //       8    3
    //      / \
    //     3   5
    vector<int> nodes2 = {10, 8, 3, 3, 5};
    node* root2 = arrayToTree(nodes2);
    cout << "Tree 2: " << (isChildrenSum(root2) ? "True" : "False") << " (Expected: False)\n";

    // Test Case 3: Single Node (Leaf)
    vector<int> nodes3 = {100};
    node* root3 = arrayToTree(nodes3);
    cout << "Tree 3: " << (isChildrenSum(root3) ? "True" : "False") << " (Expected: True)\n";

    return 0;
}