
// p1) TREE BUILDING BY QUEUE (LEVEL ORDER) 

#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
   int data;
   Node* left;
   Node* right;
   Node(int val){
    data = val;
    left = right = NULL;
   }
};

int main(){

 int rootval,leftval,rightval;
 cout<<"Enter root value : ";
 cin >> rootval;

 // built tree
 Node* root = new Node(rootval);
 queue<Node*>q;
 q.push(root);

 while(!q.empty()){

   Node* temp = q.front();
   q.pop();
   // for left
   cout<<"Enter left value of "<<temp->data<<" : ";
   cin >> leftval;

   if(leftval!= -1){
    temp->left = new Node(leftval);
    q.push(temp->left);
   }

  // for right
   cout<<"Enter Right value of "<<temp->data<<" : ";
   cin >> rightval;

   if(rightval!= -1){
    temp->right = new Node(rightval);
    q.push(temp->right);

   }

 }
 cout<<" Tree constructed ";

}