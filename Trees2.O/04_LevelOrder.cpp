// Note Tree construction by given array
// P7) Level Order traversal
// using queue data structure Bfs

#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
  int data;
  Node*left,*right;
  Node(int val){
    data=val;
    left=right=nullptr;
  }
};

Node* BuiltTree(const vector<int>& arr){

  int n=arr.size();
  if(n==0 || arr[0]==-1) return nullptr;
  int i=0;
  Node *root=new Node(arr[i]);
  i++;
  queue<Node*>q;
  q.push(root);
  while(i<n){
    Node* temp=q.front();
    q.pop();
    //left
    if(arr[i]!=-1){
      temp->left=new Node(arr[i]);
      q.push(temp->left);
    }
    i++;
    //right
    if(i<n && arr[i]!=-1){
       temp->right=new Node(arr[i]);
      q.push(temp->right);
    }
    i++;
  }
  return root;

}

//level order traversal (basic form)
void lot(Node* &root){
  
  if(root==nullptr) return ;
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left!=nullptr) q.push(temp->left);
    if(temp->right!=nullptr) q.push(temp->right);
  }
}

//level order traversal (advanced form)
vector<vector<int>> lot2(Node* &root){
  vector<vector<int>>result;
  if(root==nullptr) return result;
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    int levelsize=q.size();
    vector<int>level;
    for(int i=0;i<levelsize;i++){
       Node* temp=q.front();
       q.pop();
       level.push_back(temp->data);

       if(temp->left!=nullptr) q.push(temp->left);
       if(temp->right!=nullptr) q.push(temp->right);
    }
    result.push_back(level);
  }

 return result;
}


int main(){
  vector<int>arr={1,2,3,4,-1,0};
  Node* root=BuiltTree(arr);
  cout<<"\nLevel Order Traversal: ";
  lot(root);


  cout<<"\nLevel Order Traversal 2.O : ";
  vector<vector<int>>result=lot2(root);
  cout<<"[";
  for(int i=0;i<result.size();i++){
    cout<<"[";
    for(int j=0;j<result[i].size();j++){
      cout<<" "<<result[i][j]<<" ";
    }
    cout<<"]";
  }
  cout<<"]\n";
}