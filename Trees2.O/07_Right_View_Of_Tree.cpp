// p10) Right view of tree
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

vector<int> rViewBFS(Node* root)
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
      if(temp->right!=nullptr) q.push(temp->right);
      if(temp->left!=nullptr) q.push(temp->left);
    }
  }
  return ans;
}

void rViewDFS(Node*root,int level,vector<int>&Right_View_Values2){

 if(root==nullptr) return ;
 
 if(level == Right_View_Values2.size()){
  Right_View_Values2.push_back(root->data);
 }
 rViewDFS(root->right,level+1,Right_View_Values2);
 rViewDFS(root->left,level+1,Right_View_Values2);

}

int main()
{
 Node* root = MakeTree();

 vector<int>Right_View_Values = rViewBFS(root);
 cout<<"Right View : ";
 for(const auto x: Right_View_Values)
 {
  cout<<x<<" ";
 }

 vector<int>Right_View_Values2;
 rViewDFS(root,0,Right_View_Values2);
 cout<<"\nRight View 2.O :";
 for(const auto x: Right_View_Values2)
 {
  cout<<x<<" ";
 }
}