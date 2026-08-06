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
void predecessor(const vector<int>&In,int key)
{
   for(int i=0;i<In.size();i++){
    if(In[i]==key){
      if(i-1>=0){
      cout<<"\nPredecessor of "<<key<<" is : "<<In[i-1]<<endl;
      return;
      }
      else{
        cout<<"No Predecessor exist of "<<key<<endl;
        return;
      }
    }
   }
   cout<<"Provided No. Not Found In BST"<<endl;
   return;

}

void findPred(Node*root,int key,int &pred)
{

  
  if(root==nullptr) {
    return ;
  }

  if(root->data ==key){
      if(root->left==nullptr){
      cout<<"Predesessor is "<<pred<<endl;
      return;
    }
    else{
       
      Node*temp=root->left;
      while(temp->right!=nullptr){
        temp=temp->right;
      }
      cout<<"Predesessor is "<<temp->data<<endl;
      return;
    }
 
  }
  if(key<root->data){
     
     findPred(root->left,key,pred);
  }
  if(key>root->data){
    pred=root->data;
     findPred(root->right,key,pred);
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
    cout<<"\nEnter no. you want predessesor :";
    cin>>target;
    predecessor(In,target);

    cout<<"----------------"<<endl;
    int pred=-1;
    findPred(root,target,pred);
 
}