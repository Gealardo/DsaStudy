// p9) Top view of tree
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

// top view->use level order traversal 
void topview(Node*root)
{
  int HD=0;
  queue<pair<Node*,int>>q;
  q.push({root,HD});
  map<int,int>mp;
  while(!q.empty())
  {
    Node* tempNode= q.front().first;
    int tempHD = q.front().second;
    q.pop();
    if(mp.find(tempHD)==mp.end()) //if already not present
    {
       mp[tempHD]=tempNode->data;
    }
    if(tempNode->left!=NULL)
    {
      q.push({tempNode->left,tempHD-1});
    }
    if(tempNode->right!=NULL)
    {
      q.push({tempNode->right,tempHD+1});
    }
  }
  cout<<"Top View : ";
  for(auto x:mp)
  {
    cout<<x.second<<" ";
  }
}
// bottom view 
void bottomview(Node*root)
{
  int HD=0;
  queue<pair<Node*,int>>q;
  q.push({root,HD});
  map<int,int>mp;
  while(!q.empty())
  {
    Node* tempNode= q.front().first;
    int tempHD = q.front().second;
    q.pop();
     //if already present just over-write
    
    mp[tempHD]=tempNode->data;
    
    if(tempNode->left!=NULL)
    {
      q.push({tempNode->left,tempHD-1});
    }
    if(tempNode->right!=NULL)
    {
      q.push({tempNode->right,tempHD+1});
    }
  }
  cout<<"\nBottom View : ";
  for(auto x:mp)
  {
    cout<<x.second<<" ";
  }
}


int main()
{
 Node* root = MakeTree();
 
 topview(root);
 bottomview(root);

}