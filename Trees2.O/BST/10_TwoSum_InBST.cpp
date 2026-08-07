#include<bits/stdc++.h>
using namespace std;

class Node{public: int data;Node*left;Node*right;Node(int val){
data=val;left=right=NULL;}};


Node* makeBST(Node*&root,int val){
  if(root==NULL){
    root=new Node(val);
    return root;
  }
  else if(val< root->data) root->left=makeBST(root->left,val);
  else root->right=makeBST(root->right,val);

  return root;
}
//Brute takes O(n^2) not fessable.

// This Approch time Approx O(n);
bool findSum(vector<int>&In,int tar){

  int n=In.size();
  int l=0;
  int r=n-1;
  while(l<r){
    int sum=In[l]+In[r];

    if(sum==tar) return true;
    else if(sum < tar) l++;
    else r--;
  }
  return false;

}

bool optimal(Node*&root,int tar,unordered_map<int,int>&mp){
 
  if(root==NULL) return false;
  int key = tar - root->data;
  if(mp.find(key)!=mp.end()) return true;
  mp[root->data]++;
  bool leftans=optimal(root->left,tar,mp);
  bool rightans= optimal(root->right,tar,mp);
  return leftans || rightans;
}

bool optimal_forBST(Node*root,int tar){

  stack<Node*>st1;
  stack<Node*>st2;
  Node*temp1=root;
  Node*temp2=root;
  while(true){
      
    while(temp1!=nullptr){
      st1.push(temp1);
      temp1=temp1->left;
    }
     while(temp2!=nullptr){
       st2.push(temp2);
      temp2=temp2->right;
    }

    if(st1.empty() || st2.empty()) break;

    temp1=st1.top();
    st1.pop();
    int x=temp1->data;

    temp2=st2.top();
    st2.pop();
    int y=temp2->data;
     
    // base case
    if(x>=y) break;

    if(x+y == tar) return true;
    else if(x+y <tar) {
      temp1=temp1->right;
    }
    else{
       temp2 = temp2->left;
    }
   
  }
  return false;

}


void inorder(Node* root,vector<int>&In) {
    if (root == nullptr) return;
    inorder(root->left,In);
    In.push_back(root->data);
    inorder(root->right,In);
}

int main(){
  vector<int>arr={1,3,2,4,5};
  Node*root=NULL;
  for(auto i:arr){
    root= makeBST(root,i);
  }

  vector<int>In;
  inorder(root,In);
  cout<<"Enter Traget Sum: ";
  int target;
  cin>>target;
  cout<<"Two sum exist? "<<findSum(In,target)<<endl;
  unordered_map<int,int>mp;
  cout<<optimal(root,target,mp)<<endl;
  cout<<optimal_forBST(root,target);

}