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

// Helper function to get height (Used in Brute Force)
int getHeight(node* root){
    if(root==nullptr) return 0;

    return 1+ max(getHeight(root->left),getHeight(root->right));
}

// Version 1: Brute Force - O(N^2)
bool isBalancedBrute(node* root){
    if(root==nullptr) return true;
    int lefth=getHeight(root->left);
    int righth=getHeight(root->right);
    if((righth-lefth)>1 || (lefth-righth>1)) return false;
    
    return isBalancedBrute(root->left)&&isBalancedBrute(root->right); 
}

// Version 2: Optimal - O(N) (The Interview Favorite!)
// HINT: Instead of just returning height, return -1 if the tree is unbalanced!
int checkHeightOptimal(node* root){
    if(root == nullptr) return 0;
    
    int lh = checkHeightOptimal(root->left);
    if(lh == -1) return -1;  //  Early exit
    
    int rh = checkHeightOptimal(root->right);
    if(rh == -1) return -1;  //  Early exit
    
    if(abs(lh - rh) > 1) return -1;  // Current node is unbalanced
    
    return 1 + max(lh, rh);  //  Return actual height!
}

bool isBalancedOptimal(node* root){
    return checkHeightOptimal(root) != -1;  //  Just check if it's -1!
}

int main(){
    // Test Case 1: Balanced Tree
    vector<int> nodes1 = {1, 2, 3, 4, 5};
    node* root1 = arrayToTree(nodes1);
    cout << "Tree 1 (Balanced): " << (isBalancedOptimal(root1) ? "True" : "False") << "\n";

    // Test Case 2: Unbalanced Tree
    vector<int> nodes2 = {1, 2, -1, 3, -1, 4};
    node* root2 = arrayToTree(nodes2);
    cout << "Tree 2 (Unbalanced): " << (isBalancedOptimal(root2) ? "True" : "False") << "\n";

    return 0;
}