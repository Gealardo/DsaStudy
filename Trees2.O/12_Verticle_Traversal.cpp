


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



void verticalTraversal(Node*root)
{
  int HD=0;
  queue<pair<Node*,int>>q;
  q.push({root,HD});
  map<int,vector<int>>mp;
  while(!q.empty())
  {
    Node* tempNode= q.front().first;
    int tempHD = q.front().second;
    q.pop();
    
    mp[tempHD].push_back(tempNode->data);
    
    if(tempNode->left!=NULL)
    {
      q.push({tempNode->left,tempHD-1});
    }
    if(tempNode->right!=NULL)
    {
      q.push({tempNode->right,tempHD+1});
    }
  }
  cout<<"\nVerticle Traverse : ";
  for(auto x:mp)
  {  
    cout<<"\n"<<x.first<<"  -> ";
    for(auto val:x.second)
    {
      cout<<val<<" ";
    }
  }
}


int main()
{
 Node* root = MakeTree();
 
 
 verticalTraversal(root);

}





