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

// Count nodes in a complete binary tree - O(log²N)
int countNodes(node* root){
    if(root==nullptr) return 0;
    int l=0;
    node*curr=root;
    while(curr!=nullptr){
        l++;
        curr=curr->left;
    }
    int r=0;
    node*curr2=root;
    while(curr2!=nullptr){
        r++;
       curr2= curr2->right;
    }
    if(r==l) return (1<<l)-1;

  return 1+countNodes(root->left)+countNodes(root->right);

}

int main(){
    // Test Case 1: Perfect binary tree
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    vector<int> nodes1 = {1, 2, 3, 4, 5, 6, 7};
    node* root1 = arrayToTree(nodes1);
    cout << "Tree 1: " << countNodes(root1) << " (Expected: 7)\n";

    // Test Case 2: Complete but not perfect
    //         1
    //        / \
    //       2   3
    //      / \  /
    //     4  5 6
    vector<int> nodes2 = {1, 2, 3, 4, 5, 6};
    node* root2 = arrayToTree(nodes2);
    cout << "Tree 2: " << countNodes(root2) << " (Expected: 6)\n";

    // Test Case 3: Single node
    vector<int> nodes3 = {1};
    node* root3 = arrayToTree(nodes3);
    cout << "Tree 3: " << countNodes(root3);
}