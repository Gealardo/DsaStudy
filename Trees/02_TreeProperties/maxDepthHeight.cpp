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

// RECURSIVE METHOD - O(N) time, O(H) space (call stack)
int maxDepthRecursive(node* root){
    if(root==nullptr) return 0;
    int leftmax=maxDepthRecursive(root->left);
    int rightmax=maxDepthRecursive(root->right);
    return 1+max(leftmax,rightmax);
}

// ITERATIVE METHOD (Level Order) - O(N) time, O(N) space (queue)
int maxDepthIterative(node* root){
    int count=0;
    if(root==nullptr) return 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
          node* curr=q.front();
          q.pop();
          if(curr->left!=nullptr) q.push(curr->left);
           if(curr->right!=nullptr) q.push(curr->right);
        }
        count++;

    }
    
    return count;
}

int main(){
    // Test Case 1: Standard tree
    vector<int> nodes1 = {1, 2, 3, 4, 5, -1, 6};
    node* root1 = arrayToTree(nodes1);
    cout << "Tree 1 Height (Recursive): " << maxDepthRecursive(root1) << " (Expected: 3)\n";
    cout << "Tree 1 Height (Iterative): " << maxDepthIterative(root1) << " (Expected: 3)\n";
    cout << "-------------------\n";
    
    // Test Case 2: Single node
    vector<int> nodes2 = {1};
    node* root2 = arrayToTree(nodes2);
    cout << "Tree 2 Height (Recursive): " << maxDepthRecursive(root2) << " (Expected: 1)\n";
    cout << "Tree 2 Height (Iterative): " << maxDepthIterative(root2) << " (Expected: 1)\n";
    cout << "-------------------\n";
    
    // Test Case 3: Empty tree
    vector<int> nodes3 = {};
    node* root3 = arrayToTree(nodes3);
    cout << "Tree 3 Height (Recursive): " << maxDepthRecursive(root3) << " (Expected: 0)\n";
    cout << "Tree 3 Height (Iterative): " << maxDepthIterative(root3) << " (Expected: 0)\n";
    cout << "-------------------\n";
    
    // Test Case 4: Skewed tree (like linked list)
    vector<int> nodes4 = {1, 2, -1, 3, -1, 4};
    node* root4 = arrayToTree(nodes4);
    cout << "Tree 4 Height (Recursive): " << maxDepthRecursive(root4) << " (Expected: 4)\n";
    cout << "Tree 4 Height (Iterative): " << maxDepthIterative(root4) << " (Expected: 4)\n";
    
    return 0;
}