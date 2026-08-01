// p9) Left view of tree
// method 1) By level wise treveling
// method 2) Recursively

#include<bits/stdc++.h>
using namespace std;

class Node
{ 
  public:
  int data; Node* left; Node* right;
  Node(int val){data=val; left=right=NULL;}
};

Node* MakeTree()
{
  int rootval,leftval,rightval;
  cout<<"Enter rootval : ";
  cin >> rootval;
  if(rootval==-1) return nullptr;
  Node* root=new Node(rootval);
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    cout<<"Enter left value of "<<temp->data<<": ";
    cin >> leftval;
    if(leftval!=-1){
      temp->left=new Node(leftval);
      q.push(temp->left);
    }
    cout<<"Enter right value of "<<temp->data<<": ";
    cin >> rightval;
    if(rightval!=-1){
      temp->right=new Node(rightval);
      q.push(temp->right);
    }    
  }

  cout<<"\nTree Constructed"<<endl;
  return root;
}

vector<int> lViewBFS(Node* root)
{
  vector<int>ans;
  if(root==nullptr) return ans;

  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    ans.push_back(q.front()->data);
    int n=q.size();
    while(n--){
      Node* temp=q.front();
      q.pop();
      if(temp->left!=nullptr) q.push(temp->left);
      if(temp->right!=nullptr) q.push(temp->right);
    }
  }
  return ans;
}

void lViewDFS(Node*root,int level,vector<int>&Left_View_Values2){

 if(root==nullptr) return ;
 
 if(level == Left_View_Values2.size()){
  Left_View_Values2.push_back(root->data);
 }
 lViewDFS(root->left,level+1,Left_View_Values2);
 lViewDFS(root->right,level+1,Left_View_Values2);

}

int main()
{
 Node* root = MakeTree();

 vector<int>Left_View_Values = lViewBFS(root);
 cout<<"Left View : ";
 for(const auto x: Left_View_Values)
 {
  cout<<x<<" ";
 }

 vector<int>Left_View_Values2;
 lViewDFS(root,0,Left_View_Values2);
 cout<<"\nLeft View 2.O :";
 for(const auto x: Left_View_Values2)
 {
  cout<<x<<" ";
 }
}