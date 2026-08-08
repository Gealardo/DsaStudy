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

//---------------------------------------------------------

Node* makeBalencedBST(const vector<int>& In, int l, int h) {
    if (l > h) return nullptr;
    
    int mid = l + (h - l) / 2;
    Node* rt = new Node(In[mid]);
    
    rt->left = makeBalencedBST(In, l, mid - 1);
    rt->right = makeBalencedBST(In, mid + 1, h);
    
    return rt;
}

//----------------------------------------------------------

vector<vector<int>> LevelOrder(Node*&root){
   
  vector<vector<int>>ans;

   if(root==nullptr) return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
    int n=q.size();

    vector<int>levelVal;

    for(int i=0;i<n;i++){
      Node*temp=q.front();
      q.pop();

      levelVal.push_back(temp->data);

      if(temp->left!=NULL) q.push(temp->left);
      if(temp->right!=NULL) q.push(temp->right);
    }

    ans.push_back(levelVal);

   }

   return ans;

}

void printLO(vector<vector<int>>&Fk){


 cout<<"[";
 for(int i=0;i<Fk.size();i++){
  cout<<"[";
  for(int j=0;j<Fk[i].size();j++){
    cout<<Fk[i][j]<<" "; 
  }
  cout<<"]";
 }
 cout<<"]";
 cout<<endl;
}


void inorder(Node* root,vector<int>&In){
    if (root == nullptr) return;
    inorder(root->left,In);
    In.push_back(root->data);
    inorder(root->right,In);
}

int main(){
  vector<int>arr={1,2,3};
  Node*root=NULL;
  for(auto i:arr){
    root= makeBST(root,i);
  }

 vector<int>In;
 inorder(root,In);

 
 int l=0;
 int h=In.size()-1;
 Node* rt=makeBalencedBST(In,l,h);
 

 vector<vector<int>>Before=LevelOrder(root);
 vector<vector<int>>After=LevelOrder(rt);
 cout<<"Before: ";
 printLO(Before);
 cout<<"After: ";
 printLO(After);


}