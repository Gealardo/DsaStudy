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

void inorder(Node* root,vector<int>&In) {
    if (root == nullptr) return;
    inorder(root->left,In);
    In.push_back(root->data);
    inorder(root->right,In);
}

//---aprooch1--
void Successor(const vector<int>&In,int key)
{
   for(int i=0;i<In.size();i++){
    if(In[i]==key){
      if(i+1< In.size()){
      cout<<"\nSuccessor of "<<key<<" is : "<<In[i+1]<<endl;
      return;
      }
      else{
        cout<<"No Successor exist of "<<key<<endl;
        return;
      }
    }
   }
   cout<<"Provided No. Not Found In BST"<<endl;
   return;

}

void findSucc(Node*root,int key,int &Suc)
{

  
  if(root==nullptr) return;

  if(root->data ==key){
     
    if(root->right==nullptr){
      cout<<"Successor is "<<Suc<<endl;
      return;
    }
    else{
       Node*temp=root->right;
      while(temp->left!=nullptr){
        temp=temp->left;
      }
     
      cout<<"Successor is "<<temp->data<<endl;
      return;
    }
 
  }
  if(key<root->data){
     Suc=root->data;
     findSucc(root->left,key,Suc);
  }
  if(key>root->data){
    
     findSucc(root->right,key,Suc);
  }
  
  
}



int main() {
    Node* root = nullptr;
    inputBST(root);
    
    vector<int>In;
    inorder(root,In);
    
    cout << "\nInorder Output: ";
    for(auto it:In)
    {
      cout<<it<<" ";
    }  
    int target;
    cout<<"\nEnter no. you want Successor :";
    cin>>target;
    Successor(In,target);

    cout<<"----------------"<<endl;
    int Suc=-1;
    findSucc(root,target,Suc);
 
}