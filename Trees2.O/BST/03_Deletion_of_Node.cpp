#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* makeBST(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return root;
    }
    else if (val < root->data) {
         root->left = makeBST(root->left, val);
    }
    else {
         root->right = makeBST(root->right, val);
    }
    return root;
}

void inputBST(Node*& root) {
    cout << "No. of Nodes in BST: ";
    int x;
    cin >> x;
    cout << "Enter elements of BST: " << endl;
    int val;
    while (x--) {
        cin >> val;
        makeBST(root, val);
    }
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* deletNode(Node* &root,int tar){
  if(root==NULL) return nullptr;
  if(root->data == tar && root->left==NULL && root->right==NULL){
    delete(root);
    return nullptr;
  }
  //---- case 2 with one chile either left or right---
  if(root->data==tar &&(root->left==NULL) && root->right!=NULL){
    Node* temp=root->right;
    delete(root);
    return temp;
  }
  if(root->data==tar &&(root->right==NULL) && root->left!=NULL){
    Node* temp=root->left;
    delete(root);
    return temp;
  }
  //---------------------------------------------
  if(root->data==tar && root->left!=NULL && root->right!=NULL){

    //find largest in left of root.
    Node* temp=root->left;
    while(temp->right!=NULL){
      temp=temp->right;
    }
    root->data=temp->data;

    root->left=deletNode(root->left,temp->data);

  }
  if(root->data >tar){
    root->left=deletNode(root->left,tar);
  }
  if(root->data <tar){
    root->right =deletNode(root->right,tar);
  }
  return root;
}

int main() {
    Node* root = nullptr;
    inputBST(root);
    
    cout << "\nInorder Output: ";
    inorder(root);
    cout << endl;
    
    cout<<"Enter Node to delete : ";
    int x;
    cin>>x;
    Node* root1=deletNode(root,x);
    cout << "\nInorder Output after del "<<x<<": ";
    inorder(root1);
    cout << endl;
}